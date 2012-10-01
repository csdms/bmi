#include <stdio.h>
#include <string.h>

#include <cstdlib>
#include <bmi.hxx>

void BMI::Model::
initialize (std::string config_file)
{
  if (!config_file.empty ())
  { /* Read input file */
    FILE * fp;

    double dt = 0.;
    double t_end = 0.;
    int n_x = 0;
    int n_y = 0;

    fp = fopen (config_file.c_str (), "r");
    if (!fp)
      return;

    fscanf (fp, "%lf, %lf, %d, %d", &dt, &t_end, &n_x, &n_y);

    this->dt = dt;
    this->t_end = t_end;
    this->n_x = n_x;
    this->n_y = n_y;
    this->dx = 1.;
    this->dy = 1.;
  }
  else
  { /* Set to default values */
    this->dt = 1.;
    this->t_end = 10.;
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
    this->temp_z = new double*[this->n_y];
    this->z = new double*[this->n_y];

    this->z[0] = new double[this->n_x*this->n_y];
    this->temp_z[0] = new double[this->n_x*this->n_y];
    for (i=1; i<this->n_y; i++) {
      this->z[i] = this->z[i-1] + this->n_x;
      this->temp_z[i] = this->temp_z[i-1] + this->n_x;
    }

    this->t = 0;
    for (i = 0; i < len; i++)
      this->z[0][i] = rand ()*1./RAND_MAX * top_x*top_x*.5 - top_x*top_x*.25;
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
update ()
{

  {
    int i, j;
    const double rho = 0.;
    const double dx2 = this->dx * this->dx;
    const double dy2 = this->dy * this->dy;
    const double dx2_dy2_rho = dx2 * dy2 * rho;
    const double denom = this->dt/(2 * (dx2 + dy2));
    double **z = this->z;

    for (i=1; i<this->n_y-1; i++)
      for (j=1; j<this->n_x-1; j++)
        this->temp_z[i][j] = denom * (dx2 * (z[i-1][j] + z[i+1][j]) +
                                      dy2 * (z[i][j-1] + z[i][j+1]) -
                                      dx2_dy2_rho);

    this->t += this->dt;
  }

  memcpy (this->z[0], this->temp_z[0], sizeof (double) * this->n_y * this->n_x);

  return;
}
// End: update

void BMI::Model::
update_until (double t)
{
  const int n_steps = (t - this->t) / this->dt;

  for (int n=0; n<n_steps; n++)
    this->update ();

  if (t > this->t) {
    double dt = this->dt;
    this->dt = t-this->t;

    this->update ();

    this->dt = dt;
  }

  return;
}
// End: update_until

void BMI::Model::
finalize ()
{
  delete this->temp_z[0];
  delete this->temp_z;
  delete this->z[0];
  delete this->z;

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

void BMI::Model::
get_grid_shape (std::string long_var_name, int *shape)
{
  if (long_var_name.compare ("surface_elevation")==0) {
    shape[0] = this->n_y;
    shape[1] = this->n_x;
  }

  return;
}
// End: get_grid_shape

void BMI::Model::
get_grid_spacing (std::string long_var_name, double * spacing)
{
  if (long_var_name.compare ("surface_elevation")==0) {
    spacing[0] = this->dy;
    spacing[1] = this->dx;
  }

  return;
}
// End: get_grid_spacing

void BMI::Model::
get_grid_origin (std::string long_var_name, double *origin)
{
  if (long_var_name.compare ("surface_elevation")==0) {
    origin[0] = 0.;
    origin[1] = 0.;
  }

  return;
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
get_double (std::string long_var_name, double *dest)
{
  double * src = NULL;

  if (long_var_name.compare ("surface_elevation")==0) {
    src = this->z[0];
  }

  if (dest && src)
    memcpy (dest, src, sizeof (double) * this->n_x * this->n_y);
  else
    dest = src;

  return dest;
}
// End: get_double

double * BMI::Model::
get_double_at_indices (std::string long_var_name, double *dest, int * inds, int len)
{
  double * src = NULL;

  if (long_var_name.compare ("surface_elevation")==0) {
    src = this->z[0];
  }

  if (dest == NULL) {
    dest = (double*) malloc (sizeof (double)*len);
  }

  if (src)
  { /* Copy the data */
    for (int i=0; i<len; i++) {
      dest[i] = src[inds[i]];
    }
  }

  return dest;
}
// End: get_double_at_indices

void * BMI::Model::
get_value (std::string long_var_name, void *dest)
{
  void * src = NULL;
  int size = 0;

  if (long_var_name.compare ("surface_elevation")==0) {
    src = (void *)this->z[0];
    size = sizeof (double) * this->n_x * this->n_y;
  }

  if (src)
    memcpy (dest, src, size);

  return dest;
}
// End: get_value

void * BMI::Model::
get_value_ptr (std::string long_var_name)
{
  void * src = NULL;

  if (long_var_name.compare ("surface_elevation")==0) {
    src = (void *)this->z[0];
  }

  return src;
}
// End: get_value_ptr

void * BMI::Model::
get_value_at_indices (std::string long_var_name, void *dest, int *inds, int len)
{
  void * src = NULL;

  if (long_var_name.compare ("surface_elevation")==0) {
    src = (void *)this->z[0];
  }

  if (src)
  { /* Copy the data */
    double * from = (double *)src;
    double * to = (double *)dest;

    for (int i=0; i<len; i++) {
      to[i] = from[inds[i]];
    }
  }

  return dest;
}
// End: get_value_at_indices

void BMI::Model::
set_double (std::string long_var_name, double *src)
{
  double * dest = NULL;

  if (long_var_name.compare ("surface_elevation")==0) {
    dest = this->z[0];
  }

  if (dest)
    memcpy (dest, src, sizeof (double) * this->n_x * this->n_y);

  return;
}
// End: set_double

void BMI::Model::
set_double_at_indices (std::string long_var_name, int * inds, int len, double *src)
{
  double * dest = NULL;

  if (long_var_name.compare ("surface_elevation")==0) {
    dest = this->z[0];
  }

  if (dest) {
    for (int i=0; i<len; i++)
      dest[inds[i]] = src[i];
  }

  return;
}
// End: set_double_at_indices

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
  return this->t_end;
}
// End: get_end_time

double BMI::Model::
get_current_time () {
  return this->t;
}
// End: get_current_time

double BMI::Model::
get_time_step () {
  return this->dt;
}
// End: get_current_time

std::string BMI::Model::
get_time_units () {
  return std::string ("-");
}
// End: get_time_units

