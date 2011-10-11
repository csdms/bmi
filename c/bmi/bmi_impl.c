#include <stdio.h>
#include <stdlib.h>

#include <bmi.h>

typedef struct
{
  double dt;

  double t;

  int len;
  double *x;
  double *z;
} Self;

void *
BMI_Initialize (const char *config_file)
{
  Self *self = NULL;

  self = malloc (sizeof (Self));

  if (config_file)
  {     /* Read input file */
    FILE *fp = NULL;

    double dt = 0.;

    int len = 0.;

    fp = fopen (config_file, "r");
    if (!fp)
      return NULL;
    fscanf (fp, "%f, %d", &dt, &len);

    self->dt = dt;
    self->len = len;
  }
  else
  {
    self->dt = 1.;
    self->len = 10;
  }

  self->x = (double *)malloc (sizeof (double) * self->len);
  self->z = (double *)malloc (sizeof (double) * self->len);

  {     /* Initialize data */
    int i;

    self->t = 0;
    for (i = 0; i < self->len; i++)
    {
      self->x[i] = i;
      self->z[i] = 0.;
    }
  }

  return (void *)self;
}

void
BMI_Update (void *handle)
{
  Self *self = (Self *) handle;
  int i;

  self->t += self->dt;

  for (i = 0; i < self->len; i++)
    self->z[i] += self->x[i] * self->dt;

  return;
}

void
BMI_Finalize (void *handle)
{
  Self *self = (Self *) handle;

  if (self)
  {
    free (self->z);
    free (self->x);
    free (self);
  }

  return;
}

const char *
BMI_Get_var_type (void *handle, const char *long_var_name)
{
  Self *self = (Self *) handle;

  if (strcasecmp (long_var_name, "grid_longitude") == 0)
    return "double";
  else if (strcasecmp (long_var_name, "height_above_sea_floor") == 0)
    return "double";
  else
    return NULL;
}

const char *
BMI_Get_var_units (void *handle, const char *long_var_name)
{
  Self *self = (Self *) handle;

  if (strcmp (long_var_name, "grid_longitude") == 0)
    return "arc_degree";
  else if (strcmp (long_var_name, "height_above_sea_floor") == 0)
    return "meter";
  else
    return NULL;
}

int
BMI_Get_var_rank (void *handle, const char *long_var_name)
{
  Self *self = (Self *) handle;

  if (strcmp (long_var_name, "grid_longitude") == 0)
    return 1;
  else if (strcmp (long_var_name, "height_above_sea_floor") == 0)
    return 1;
  else
    return -1;
}

// Assumes arrays start at 0, and have contiguous elements (unit stride).
double *
BMI_Get_1d_double (void *handle, const char *long_var_name, int len[1])
{
  Self *self = (Self *) handle;

  len[0] = self->len;
  if (strcmp (long_var_name, "grid_longitude") == 0)
    return self->x;
  else if (strcmp (long_var_name, "height_above_sea_floor") == 0)
    return self->z;
  else
  {
    len[0] = 0;
    return NULL;
  }
}

double *
BMI_Get_1d_double_at_indices (void *handle, const char *long_var_name,
                          int *indices, int len, double *dest)
{
  Self *self = (Self *) handle;
  double *val = NULL;
  int val_len = 0;

  val = BMI_Get_1d_double (self, long_var_name, &val_len);

  if (val)
  {
    int i;

    for (i = 0; i < len; i++)
      dest[i] = val[indices[i]];
    return dest;
  }
  else
    return NULL;
}

void
BMI_Set_1d_double (void *handle, const char *long_var_name, const double *array)
{
  Self *self = (Self *) handle;
  double *val = NULL;
  int val_len = 0;

  val = BMI_Get_1d_double (self, long_var_name, &val_len);

  if (val)
  {
    int i;

    for (i = 0; i < val_len; i++)
      val[i] = array[i];
  }

  return;
}

void
BMI_Set_1d_double_at_indices (void *handle, const char *long_var_name,
                          int *indices, const double *array, int len)
{
  Self *self = (Self *) handle;
  double *val = NULL;
  int val_len = 0;

  val = BMI_Get_1d_double (self, long_var_name, &val_len);

  if (val)
  {
    int i;

    for (i = 0; i < len; i++)
      val[indices[i]] = array[i];
  }

  return;
}

// Assume string arrays are NULL-terminated
const char *
BMI_Get_component_name (void *handle)
{
  return "Example model";
}

const char *input_var_names[] = {
  "height_above_sea_floor",
  NULL
};

const char **
BMI_Get_input_var_names (void *handle)
{
  return input_var_names;
}

const char *output_var_names[] = {
  "grid_longitude",
  "height_above_sea_floor",
  NULL
};

const char **
BMI_Get_output_var_names (void *handle)
{
  return output_var_names;
}

int *
BMI_Get_grid_dimen (void *handle, const char *long_var_name, int *rank)
{
  Self *self = (Self *) handle;
  int *dimen = (int *)malloc (sizeof (int));

  *rank = 1;
  dimen[0] = self->len;
  return dimen;
}

double *
BMI_Get_grid_res (void *handle, const char *long_var_name, int *rank)
{
  Self *self = (Self *) handle;
  double *res = (double *)malloc (sizeof (double));

  *rank = 1;
  res[0] = 1.;
  return res;
}

double *
BMI_Get_grid_corner (void *handle, const char *long_var_name, int *rank)
{
  Self *self = (Self *) handle;
  double *corner = (double *)malloc (sizeof (double));

  *rank = 1;
  corner[0] = 0;
  return corner;
}

int
BMI_Is_raster_grid (void *handle, const char *long_var_name)
{
  return 1;
}

