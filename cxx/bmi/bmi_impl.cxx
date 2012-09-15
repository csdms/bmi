#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#include <iostream>
#include <bmi.hxx>

void BMI::Model::
initialize (std::string config_file)
{
  if (!config_file.empty ())
  { /* Read input file */
    FILE *fp = NULL;

    double dt = 0.;
    int n_x = 0;
    int n_y = 0;

    fp = fopen (config_file.c_str (), "r");
    if (!fp)
      return;
    fscanf (fp, "%f, %d, %d", &dt, &n_x, &n_y);

    this->dt = dt;
    this->n_x = n_x;
    this->n_y = n_y;
    this->dx = 1.;
    this->dy = 1.;
  }
  else
  { /* Set to default values */
    this->dt = 1.;
    this->n_x = 10;
    this->n_y = 20;
    this->dx = 1.;
    this->dy = 1.;
  }

  { /* Initialize data */
    int i;
    const int len = this->n_x * this->n_y;
    double top_x = this->n_x - 1;

    /* Allocate memory */
    this->temp_z = (double **)malloc (sizeof (double*) * this->n_y);
    this->z = (double **)malloc (sizeof (double*) * this->n_y);

    this->z[0] = (double *)malloc (sizeof (double) * this->n_x * this->n_y);
    this->temp_z[0] = (double *)malloc (sizeof (double) * this->n_x * this->n_y);
    for (i=1; i<this->n_y; i++) {
      this->z[i] = this->z[i-1] + this->n_x;
      this->temp_z[i] = this->temp_z[i-1] + this->n_x;
    }

    this->t = 0;
    for (i = 0; i < len; i++)
      this->z[0][i] = 0.;
    for (i = 0; i < this->n_y; i++) {
      this->z[i][0] = 0.;
      this->z[i][this->n_x-1] = 0.;
    }
    for (i = 0; i < this->n_x; i++) {
      this->z[0][i] = 0.;
      this->z[this->n_y-1][i] = top_x*top_x*.25 - (i-top_x*.5) * (i-top_x*.5);
    }

    memcpy (this->temp_z[0], this->z[0], sizeof (double)*this->n_x*this->n_y);
  }

  return;
}
// End: initialize

void BMI::Model::
update_until (double dt)
{
  this->t += this->dt;

  {
    int i, j;
    const double rho = 0.;
    const double dx2 = this->dx * this->dx;
    const double dy2 = this->dy * this->dy;
    const double dx2_dy2_rho = dx2 * dy2 * rho;
    const double denom = 1./(2 * (dx2 + dy2));
    double **z = this->z;

    for (i=1; i<this->n_y-1; i++)
      for (j=1; j<this->n_x-1; j++)
        this->temp_z[i][j] = denom * (dx2 * (z[i-1][j] + z[i+1][j]) +
                                      dy2 * (z[i][j-1] + z[i][j+1]) -
                                      dx2_dy2_rho);
  }

  memcpy (this->z[0], this->temp_z[0], sizeof (double) * this->n_y * this->n_x);

  return;
}
// End: update_until

void BMI::Model::
finalize ()
{
  free (this->temp_z[0]);
  free (this->temp_z);
  free (this->z[0]);
  free (this->z);

  return;
}
// End: finalize

std::string BMI::Model::
get_var_type (std::string long_var_name)
{
  const char *type;
  if (long_var_name.compare ("surface_elevation")==0)
    type = "double";
  else
    type = "";

  return std::string (type);
}
// End: get_var_type

std::string BMI::Model::
get_var_units (std::string long_var_name)
{
  const char *units;
  if (long_var_name.compare ("surface_elevation")==0)
    units = "meter";
  else
    units = "";

  return std::string (units);
}
// End: get_var_units

int BMI::Model::
get_var_rank (std::string long_var_name)
{
  if (long_var_name.compare ("surface_elevation")==0)
    return 2;
  else
    return -1;
}
// End: get_var_rank

int * BMI::Model::
get_grid_shape (std::string long_var_name, int &n_dim)
{
  int * shape = NULL;

  if (long_var_name.compare ("surface_elevation")==0) {
    shape = (int *)malloc (sizeof (int)*2);

    shape[0] = this->n_y;
    shape[1] = this->n_x;

    n_dim = 2;
  }
  else
    n_dim = 0;

  return shape;
}
// End: get_grid_shape

double * BMI::Model::
get_grid_spacing (std::string long_var_name, int &n_dim)
{
  double * spacing = NULL;

  if (long_var_name.compare ("surface_elevation")==0) {
    spacing = (double *)malloc (sizeof (double)*2);

    spacing[0] = this->dy;
    spacing[1] = this->dx;

    n_dim = 2;
  }
  else
    n_dim = 0;

  return spacing;
}
// End: get_grid_spacing

double * BMI::Model::
get_grid_origin (std::string long_var_name, int &n_dim)
{
  double * origin = NULL;

  if (long_var_name.compare ("surface_elevation")==0) {
    origin = (double *)malloc (sizeof (double)*2);

    origin[0] = 0.;
    origin[1] = 0.;

    n_dim = 2;
  }
  else
    n_dim = 0;

  return origin;
}
// End: get_grid_origin

BMI::Grid_type BMI::Model::
get_grid_type (std::string long_var_name)
{
  if (long_var_name.compare ("surface_elevation")==0)
    return GRID_TYPE_UNIFORM;
  else
    return GRID_TYPE_UNKNOWN;
}
// End: get_grid_type

double * BMI::Model::
get_double (std::string long_var_name, int &n_dims)
{
  double * val = NULL;

  if (long_var_name.compare ("surface_elevation")==0) {
    val = this->z[0];
    n_dims = 2;
  }

  return val;
}
// End: get_double

void BMI::Model::
set_double (std::string long_var_name, double *array)
{
  if (long_var_name.compare ("surface_elevation")==0) {
    memcpy (this->z[0], array, sizeof (double) * this->n_x * this->n_y);
  }

  return;
}
// End: set_double

std::string BMI::Model::
get_component_name ()
{
  return "Example C++ model";
}
// End: get_component_name

const char *input_var_names[] = {
  "surface_elevation",
  NULL
};

const char ** BMI::Model::
get_input_var_names ()
{
  return input_var_names;
}
// End: get_input_var_names

const char *output_var_names[] = {
  "surface_elevation",
  NULL
};

const char ** BMI::Model::
get_output_var_names ()
{
  return output_var_names;
}
// End: get_output_var_names

double BMI::Model::
get_start_time () {
  return 0.;
}
// End: get_start_time

double BMI::Model::
get_end_time () {
  return DBL_MAX;
}
// End: get_end_time

double BMI::Model::
get_current_time () {
  return this->t;
}
// End: get_current_time

