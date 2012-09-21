#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#include <bmi.h>

struct _BMI_Model {
  double dt;
  double t;
  double t_end;

  int n_x;
  int n_y;

  double dx;
  double dy;
  double **z;

  double **temp_z;
};

BMI_Model *
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
BMI_Update_until (BMI_Model *self, double t)
{
  //BMI_Model *self = (BMI_Model *) handle;

  {
    int n;
    const int n_steps = (t - BMI_Get_current_time (self)) / BMI_Get_time_step (self);

    for (n=0; n<n_steps; n++) {
      BMI_Update (self);
    }

    if (t>BMI_Get_current_time (self)) {
      double dt = BMI_Get_time_step (self);
      self->dt = t - BMI_Get_current_time (self); 

      BMI_Update (self);

      self->dt = dt;
    }
  }

  fprintf (stderr, "Time is %f\n", BMI_Get_current_time (self));

  return;
}
/* End: BMI_Update_until */

void
BMI_Update (BMI_Model *self)
{
  //BMI_Model *self = (BMI_Model *) handle;

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
BMI_Finalize (BMI_Model *self)
{
  //BMI_Model *self = (BMI_Model *) handle;

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

BMI_Var_type
BMI_Get_var_type (BMI_Model *self, const char *long_var_name)
{
  if (strcasecmp (long_var_name, "surface_elevation") == 0)
    return BMI_VAR_TYPE_DOUBLE;
  else
    return BMI_VAR_TYPE_UNKNOWN;
}
/* End: BMI_Get_var_type */

const char *
BMI_Get_var_units (BMI_Model *self, const char *long_var_name)
{
  if (strcmp (long_var_name, "surface_elevation") == 0)
    return "meter";
  else
    return NULL;
}
/* End: BMI_Get_var_units */

int
BMI_Get_var_rank (BMI_Model *self, const char *long_var_name)
{
  if (strcmp (long_var_name, "surface_elevation") == 0)
    return 2;
  else
    return -1;
}
/* End: BMI_Get_var_rank */

void
BMI_Get_grid_shape (BMI_Model *self, const char *long_var_name, int * shape)
{
  if (strcmp (long_var_name, "surface_elevation") == 0) {
    shape[0] = self->n_y;
    shape[1] = self->n_x;
  }

  return;
}

/* End: BMI_Get_grid_shape */

void
BMI_Get_grid_spacing (BMI_Model *self, const char *long_var_name, double * spacing)
{
  if (strcmp (long_var_name, "surface_elevation") == 0) {
    spacing[0] = self->dy;
    spacing[1] = self->dx;
  }

  return;
}
/* End: BMI_Get_grid_spacing */

void
BMI_Get_grid_origin (BMI_Model *self, const char *long_var_name, double * origin)
{
  if (strcmp (long_var_name, "surface_elevation") == 0) {
    origin[0] = 0.;
    origin[1] = 0.;
  }

  return;
}
/* End: BMI_Get_grid_origin */

BMI_Grid_type
BMI_Get_grid_type (BMI_Model *self, const char *long_var_name)
{
  if (strcmp (long_var_name, "surface_elevation") == 0)
    return BMI_GRID_TYPE_UNIFORM;
  else
    return BMI_GRID_TYPE_UNKNOWN;
}
/* End: BMI_Get_grid_type */

double *
BMI_Get_double (BMI_Model *self, const char *long_var_name, double *val)
{
  double *src = NULL;

  if (strcmp (long_var_name, "surface_elevation")==0) {
    src = self->z[0];
  }

  if (val)
    memcpy (val, src, sizeof (double) * self->n_x * self->n_y);
  else
    val = src;

  return val;
}
/* End: BMI_Get_double */

double *
BMI_Get_double_at_indices (BMI_Model *self, const char *long_var_name, double *dest, int * inds, int len)
{
  double *src = NULL;

  if (strcmp (long_var_name, "surface_elevation")==0) {
    src = self->z[0];
  }

  { /* Copy the data */
    int i;
    for (i=0; i<len; i++) {
      dest[i] = src[inds[i]];
    }
  }

  return dest;
}
/* End: BMI_Get_double_at_indices */

void
BMI_Set_double (BMI_Model *self, const char *long_var_name, double *array)
{
  if (strcmp (long_var_name, "surface_elevation")==0) {
    memcpy (self->z[0], array, sizeof (double) * self->n_x * self->n_y);
  }

  return;
}
/* End: BMI_Set_double */

void
BMI_Set_double_at_indices (BMI_Model *self, const char *long_var_name, int * inds, int len, double *src)
{
  double * dest;

  if (strcmp (long_var_name, "surface_elevation")==0) {
    dest = self->z[0];
  }

  { /* Copy the data */
    int i;
    for (i=0; i<len; i++) {
      dest[inds[i]] = src[i];
    }
  }

  return;
}
/* End: BMI_Set_double_at_indices */

const char *
BMI_Get_component_name (BMI_Model *self)
{
  return "Example C model";
}
/* End: BMI_Get_component_name */

const char *input_var_names[] = {
  "surface_elevation",
  NULL
};

const char **
BMI_Get_input_var_names (BMI_Model *self)
{
  return input_var_names;
}
/* End: BMI_Get_input_var_names */

const char *output_var_names[] = {
  "surface_elevation",
  NULL
};

const char **
BMI_Get_output_var_names (BMI_Model *self)
{
  return output_var_names;
}
/* End: BMI_Get_output_var_names */

double
BMI_Get_start_time (BMI_Model *self) {
  return 0.;
}
/* End: BMI_Get_start_time */

double
BMI_Get_end_time (BMI_Model *self) {
  //BMI_Model *self = (BMI_Model *) handle;
  return self->t_end;
}
/* End: BMI_Get_end_time */

double
BMI_Get_current_time (BMI_Model *self) {
  //BMI_Model *self = (BMI_Model *) handle;
  return self->t;
}
/* End: BMI_Get_current_time */

double
BMI_Get_time_step (BMI_Model *self) {
  //BMI_Model *self = (BMI_Model *) handle;
  return self->dt;
}
/* End: BMI_Get_time_step */

const char *
BMI_Get_time_units (BMI_Model *self) {
  //BMI_Model *self = (BMI_Model *) handle;
  return "-";
}
/* End: BMI_Get_time_units */

