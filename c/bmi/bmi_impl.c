#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#include <bmi.h>

typedef struct
{
  double dt;
  double t;
  double t_end;

  int n_x;
  int n_y;

  double dx;
  double dy;
  double **z;

  double **temp_z;
} BMI_Model;

void *
BMI_Initialize (const char *config_file)
{
  BMI_Model *self = NULL;

  self = malloc (sizeof (BMI_Model));

  if (config_file)
  { /* Read input file */
    FILE *fp = NULL;

    double dt = 0.;
    double t_end = 1.;
    int n_x = 0;
    int n_y = 0;

    fp = fopen (config_file, "r");
    if (!fp)
      return NULL;
    fscanf (fp, "%lf, %lf, %d, %d", &dt, &t_end, &n_x, &n_y);

    self->dt = dt;
    self->t_end = t_end;
    self->n_x = n_x;
    self->n_y = n_y;
    self->dx = 1.;
    self->dy = 1.;
  }
  else
  { /* Set to default values */
    self->dt = 1.;
    self->t_end = 10.;
    self->n_x = 10;
    self->n_y = 20;
    self->dx = 1.;
    self->dy = 1.;
  }

  { /* Initialize data */
    int i;
    const int len = self->n_x * self->n_y;
    double top_x = self->n_x - 1;

    /* Allocate memory */
    self->temp_z = (double **)malloc (sizeof (double*) * self->n_y);
    self->z = (double **)malloc (sizeof (double*) * self->n_y);

    self->z[0] = (double *)malloc (sizeof (double) * self->n_x * self->n_y);
    self->temp_z[0] = (double *)malloc (sizeof (double) * self->n_x * self->n_y);
    for (i=1; i<self->n_y; i++) {
      self->z[i] = self->z[i-1] + self->n_x;
      self->temp_z[i] = self->temp_z[i-1] + self->n_x;
    }

    self->t = 0;
    for (i = 0; i < len; i++)
      self->z[0][i] = random ()*1./RAND_MAX * top_x * top_x * .5 - top_x * top_x * .25;
    for (i = 0; i < self->n_y; i++) {
      self->z[i][0] = 0.;
      self->z[i][self->n_x-1] = 0.;
    }
    for (i = 0; i < self->n_x; i++) {
      self->z[0][i] = 0.;
      self->z[self->n_y-1][i] = top_x*top_x*.25 - (i-top_x*.5) * (i-top_x*.5);
    }
    
    memcpy (self->temp_z[0], self->z[0], sizeof (double)*self->n_x*self->n_y);
  }

  return (void *)self;
}
/* End: BMI_Initialize */

void
BMI_Update_until (void *handle, double t)
{
  BMI_Model *self = (BMI_Model *) handle;

  {
    int n;
    const int n_steps = (t - BMI_Get_current_time (handle)) / BMI_Get_time_step (handle);

    for (n=0; n<n_steps; n++) {
      BMI_Update (handle);
    }

    if (t>BMI_Get_current_time (handle)) {
      double dt = BMI_Get_time_step (handle);
      self->dt = t - BMI_Get_current_time (handle); 

      BMI_Update (handle);

      self->dt = dt;
    }
  }

  fprintf (stderr, "Time is %f\n", BMI_Get_current_time (handle));

  return;
}
/* End: BMI_Update_until */

void
BMI_Update (void *handle)
{
  BMI_Model *self = (BMI_Model *) handle;

  {
    int i, j;
    const double rho = 0.;
    const double dx2 = self->dx * self->dx;
    const double dy2 = self->dy * self->dy;
    const double dx2_dy2_rho = dx2 * dy2 * rho;
    const double denom = self->dt/(2 * (dx2 + dy2));
    double **z = self->z;

    for (i=1; i<self->n_y-1; i++)
      for (j=1; j<self->n_x-1; j++)
        self->temp_z[i][j] = denom * (dx2 * (z[i-1][j] + z[i+1][j]) +
                                      dy2 * (z[i][j-1] + z[i][j+1]) -
                                      dx2_dy2_rho);
    self->t += self->dt;
  }

  memcpy (self->z[0], self->temp_z[0], sizeof (double) * self->n_y * self->n_x);

  return;
}
/* End: BMI_Update */

void
BMI_Finalize (void *handle)
{
  BMI_Model *self = (BMI_Model *) handle;

  if (self)
  {
    free (self->temp_z[0]);
    free (self->temp_z);
    free (self->z[0]);
    free (self->z);
    free (self);
  }

  return;
}
/* End: BMI_Finalize */

const char *
BMI_Get_var_type (void *handle, const char *long_var_name)
{
  if (strcasecmp (long_var_name, "surface_elevation") == 0)
    return "double";
  else
    return NULL;
}
/* End: BMI_Get_var_type */

const char *
BMI_Get_var_units (void *handle, const char *long_var_name)
{
  if (strcmp (long_var_name, "surface_elevation") == 0)
    return "meter";
  else
    return NULL;
}
/* End: BMI_Get_var_units */

int
BMI_Get_var_rank (void *handle, const char *long_var_name)
{
  if (strcmp (long_var_name, "surface_elevation") == 0)
    return 2;
  else
    return -1;
}
/* End: BMI_Get_var_rank */

int *
BMI_Get_grid_shape (void *handle, const char *long_var_name, int * n_dim)
{
  int * shape = NULL;

  if (strcmp (long_var_name, "surface_elevation") == 0) {
    BMI_Model *self = (BMI_Model *) handle;

    shape = (int *)malloc (sizeof (int)*2);

    shape[0] = self->n_y;
    shape[1] = self->n_x;

    *n_dim = 2;
  }
  else
    *n_dim = 0;

  return shape;
}
/* End: BMI_Get_grid_shape */

double *
BMI_Get_grid_spacing (void *handle, const char *long_var_name, int * n_dim)
{
  double * spacing = NULL;

  if (strcmp (long_var_name, "surface_elevation") == 0) {
    BMI_Model *self = (BMI_Model *) handle;

    spacing = (double *)malloc (sizeof (double)*2);

    spacing[0] = self->dy;
    spacing[1] = self->dx;

    *n_dim = 2;
  }
  else
    *n_dim = 0;

  return spacing;
}
/* End: BMI_Get_grid_spacing */

double *
BMI_Get_grid_origin (void *handle, const char *long_var_name, int * n_dim)
{
  double * origin = NULL;

  if (strcmp (long_var_name, "surface_elevation") == 0) {
    origin = (double *)malloc (sizeof (double)*2);

    origin[0] = 0.;
    origin[1] = 0.;

    *n_dim = 2;
  }
  else
    *n_dim = 0;

  return origin;
}
/* End: BMI_Get_grid_origin */

BMI_Grid_type
BMI_Get_grid_type (void *handle, const char *long_var_name)
{
  if (strcmp (long_var_name, "surface_elevation") == 0)
    return BMI_GRID_TYPE_UNIFORM;
  else
    return BMI_GRID_TYPE_UNKNOWN;
}
/* End: BMI_Get_grid_type */

double *
BMI_Get_double (void *handle, const char *long_var_name, int * n_dims, int **shape)
{
  double * val = NULL;

  if (strcmp (long_var_name, "surface_elevation")==0) {
    BMI_Model *self = (BMI_Model *) handle;

    val = self->z[0];
    *n_dims = 2;
  }

  if (shape != NULL)
    *shape = BMI_Get_grid_shape (handle, long_var_name, n_dims);

  return val;
}
/* End: BMI_Get_double */

void
BMI_Set_double (void *handle, const char *long_var_name, double *array)
{
  if (strcmp (long_var_name, "surface_elevation")==0) {
    BMI_Model *self = (BMI_Model *) handle;
    memcpy (self->z[0], array, sizeof (double) * self->n_x * self->n_y);
  }

  return;
}
/* End: BMI_Set_double */

// Assume string arrays are NULL-terminated
const char *
BMI_Get_component_name (void *handle)
{
  return "Example C model";
}
/* End: BMI_Get_component_name */

const char *input_var_names[] = {
  "surface_elevation",
  NULL
};

const char **
BMI_Get_input_var_names (void *handle)
{
  return input_var_names;
}
/* End: BMI_Get_input_var_names */

const char *output_var_names[] = {
  "surface_elevation",
  NULL
};

const char **
BMI_Get_output_var_names (void *handle)
{
  return output_var_names;
}
/* End: BMI_Get_output_var_names */

double
BMI_Get_start_time (void *handle) {
  return 0.;
}
/* End: BMI_Get_start_time */

double
BMI_Get_end_time (void *handle) {
  BMI_Model *self = (BMI_Model *) handle;
  return self->t_end;
}
/* End: BMI_Get_end_time */

double
BMI_Get_current_time (void *handle) {
  BMI_Model *self = (BMI_Model *) handle;
  return self->t;
}
/* End: BMI_Get_current_time */

double
BMI_Get_time_step (void *handle) {
  BMI_Model *self = (BMI_Model *) handle;
  return self->dt;
}
/* End: BMI_Get_time_step */

const char *
BMI_Get_time_units (void *handle) {
  BMI_Model *self = (BMI_Model *) handle;
  return "-";
}
/* End: BMI_Get_time_units */

