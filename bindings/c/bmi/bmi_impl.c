#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#include <bmi.h>
#include <bmi_grid.h>

typedef struct BMI_Model {
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

BMI_Model *self = NULL;

#define VAR_COUNT 1

int
initialize (const char *config_file)
{

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
      return BMI_FAILURE;

    fscanf (fp, "%lf, %lf, %d, %d", &dt, &t_end, &n_x, &n_y);

    self->dt = dt;
    self->t_end = t_end;
    self->n_x = n_x;
    self->n_y = n_y;
  }
  else
  { /* Set to default values */
    self->dt = 1.;
    self->t_end = 10.;
    self->n_x = 10;
    self->n_y = 20;
  }

  self->dx = 1.;
  self->dy = 1.;

  { /* Initialize data */
    int i;
    const int len = self->n_x * self->n_y;
    double top_x = self->n_x - 1;

    /* Allocate memory */
    self->z = (double **)malloc (sizeof (double*) * self->n_y);
    self->temp_z = (double **)malloc (sizeof (double*) * self->n_y);

    if (!self->temp_z || !self->z)
      return BMI_FAILURE;

    self->z[0] = (double *)malloc (sizeof (double) * self->n_x * self->n_y);
    self->temp_z[0] = (double *)malloc (sizeof (double) * self->n_x * self->n_y);

    if (!self->temp_z[0] || !self->z[0])
      return BMI_FAILURE;

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
  return BMI_SUCCESS;
}
/* End: BMI_Initialize */

int
update (double dt)
{
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

  return BMI_SUCCESS;
}
/* End: update */

int
update_frac (double f)
{
  if (f>0) {
    double dt;

    get_time_step (&dt);

    self->dt = f * dt;

    update (dt);

    self->dt = dt;
  }

  return BMI_SUCCESS;
}
/* End: update_frac */

int
update_until (double t)
{
  {
    double dt;
    double now;

    get_time_step (&dt);
    get_current_time (&now);

    {
      int n;
      const double n_steps = (t - now) / dt;
      for (n=0; n<(int)n_steps; n++) {
        update (-1);
      }

      update_frac (n_steps - (int)n_steps);
    }
  }

  return BMI_SUCCESS;
}
/* End: update_until */

int
finalize ()
{
  if (self)
  {
    free (self->temp_z[0]);
    free (self->temp_z);
    free (self->z[0]);
    free (self->z);
    free (self);
  }

  return BMI_SUCCESS;
}
/* End: BMI_Finalize */

int
get_var_type (const char *long_var_name, char * type)
{
  if (strcasecmp (long_var_name, "surface_elevation") == 0) {
    strncpy(type, "double", BMI_MAX_NAME);
    return BMI_SUCCESS;
  }
  else {
    strncpy(type, "", BMI_MAX_NAME);
    return BMI_FAILURE;
  }
}
/* End: get_var_type */

int
get_var_units (const char *long_var_name, char * units)
{
  if (strcmp (long_var_name, "surface_elevation") == 0) {
    strncpy (units, "meter", BMI_MAX_NAME);
    return BMI_SUCCESS;
  }
  else {
    units[0] = '\0';
    return BMI_FAILURE;
  }
}
/* End: get_var_units */

int
get_var_rank (const char *long_var_name, int * rank)
{
  if (strcmp (long_var_name, "surface_elevation") == 0) {
    *rank = 2;
    return BMI_SUCCESS;
  }
  else {
    *rank = -1;
    return BMI_FAILURE;
  }
}
/* End: get_var_rank */

int
get_grid_shape (const char *long_var_name, int * shape)
{
  if (strcmp (long_var_name, "surface_elevation") == 0) {
    shape[0] = self->n_y;
    shape[1] = self->n_x;
  }

  return BMI_SUCCESS;
}

/* End: get_grid_shape */

int
get_grid_spacing (const char *long_var_name, double * spacing)
{
  if (strcmp (long_var_name, "surface_elevation") == 0) {
    spacing[0] = self->dy;
    spacing[1] = self->dx;
  }

  return BMI_SUCCESS;
}
/* End: get_grid_spacing */

int
get_grid_origin (const char *long_var_name, double * origin)
{
  if (strcmp (long_var_name, "surface_elevation") == 0) {
    origin[0] = 0.;
    origin[1] = 0.;
  }

  return BMI_SUCCESS;
}
/* End: get_grid_origin */

int
get_grid_type (const char *long_var_name, BMI_Grid_type * type)
{
  if (strcmp (long_var_name, "surface_elevation") == 0) {
    *type = BMI_GRID_TYPE_UNIFORM;
    return BMI_SUCCESS;
  }
  else {
    *type = BMI_GRID_TYPE_UNKNOWN;
    return BMI_FAILURE;
  }
  return BMI_SUCCESS;
}
/* End: get_grid_type */


int
get_var (const char *long_var_name, void **dest)
{
  void *src = NULL;

  if (strcmp (long_var_name, "surface_elevation")==0) {
    src = &self->z;
  }

  *dest = src;

  return BMI_SUCCESS;
}
/* End: get_var */


int
set_var (const char *long_var_name, const void *ptr)
{
  if (strcmp (long_var_name, "surface_elevation")==0) {
    memcpy (self->z[0], ptr, sizeof (double) * self->n_x * self->n_y);
  }

  return BMI_SUCCESS;
}
/* End: BMI_Set_double */

int
set_var_at_indices (const char *long_var_name, const int * inds, const int len, const void *ptr)
{
  double * dest;

  if (strcmp (long_var_name, "surface_elevation")==0) {
    dest = self->z[0];
  }

  { /* Copy the data */
    int i;
    for (i=0; i<len; i++) {
      dest[inds[i]] = ((double*)ptr)[i];
    }
  }

  return BMI_SUCCESS;
}
/* End: BMI_Set_double_at_indices */



int
get_value (const char *long_var_name, void *dest)
{
  void *src = NULL;

  if (strcmp (long_var_name, "surface_elevation")==0) {
    src = (void*) self->z[0];
  }

  memcpy (dest, src, sizeof (double) * self->n_x * self->n_y);

  return BMI_SUCCESS;
}
/* End: get_value */

int
get_value_ptr (const char *long_var_name, void **dest)
{
  void *src = NULL;

  if (strcmp (long_var_name, "surface_elevation")==0) {
    src = (void*) self->z[0];
  }

  *dest = src;

  return BMI_SUCCESS;
}
/* End: get_value */



int
get_value_at_indices (const char *long_var_name, void *dest, int * inds, int len)
{
  double *src = NULL;

  if (strcmp (long_var_name, "surface_elevation")==0) {
    src = self->z[0];
  }

  { /* Copy the data */
    int i;
    double * to = (double*) dest;
    for (i=0; i<len; i++) {
      to[i] = src[inds[i]];
    }
  }

  return BMI_SUCCESS;
}

/* End: get_double_at_indices */
int
get_double (const char *long_var_name, double *dest)
{
  double *src = NULL;

  if (strcmp (long_var_name, "surface_elevation")==0) {
    src = self->z[0];
  }

  memcpy (dest, src, sizeof (double) * self->n_x * self->n_y);

  return BMI_SUCCESS;
}
/* End: get_double */

int
get_double_ptr (const char *long_var_name, double **dest)
{
  double *src = NULL;

  if (strcmp (long_var_name, "surface_elevation")==0) {
    src = self->z[0];
  }

  *dest = src;

  return BMI_SUCCESS;
}
/* End: get_double_ptr */

int
get_double_at_indices (const char *long_var_name, double *dest, int * inds, int len)
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

  return BMI_SUCCESS;
}
/* End: get_double_at_indices */

int
BMI_Set_value (const char *long_var_name, void *array)
{
  if (strcmp (long_var_name, "surface_elevation")==0) {
    memcpy (self->z[0], array, sizeof (double) * self->n_x * self->n_y);
  }

  return BMI_SUCCESS;
}
/* End: BMI_Set_double */

int
BMI_Set_value_at_indices (const char *long_var_name, int * inds, int len, void *src)
{
  double * to;

  if (strcmp (long_var_name, "surface_elevation")==0) {
    to = self->z[0];
  }

  { /* Copy the data */
    int i;
    double * from = src;
    for (i=0; i<len; i++) {
      to[inds[i]] = from[i];
    }
  }

  return BMI_SUCCESS;
}
/* End: BMI_Set_value_at_indices */

int
BMI_Set_double (const char *long_var_name, double *array)
{
  if (strcmp (long_var_name, "surface_elevation")==0) {
    memcpy (self->z[0], array, sizeof (double) * self->n_x * self->n_y);
  }

  return BMI_SUCCESS;
}
/* End: BMI_Set_double */

int
BMI_Set_double_at_indices (const char *long_var_name, int * inds, int len, double *src)
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

  return BMI_SUCCESS;
}
/* End: BMI_Set_double_at_indices */

int
get_component_name (char * name)
{
  strncpy (name, "Example C model", BMI_MAX_NAME);
  return BMI_SUCCESS;
}
/* End: get_component_name */


char *var_names[VAR_COUNT] = {
  "surface_elevation"
};

char *roles[VAR_COUNT] = {
  "inout"
};


int get_var_count(int *n) {
  *n = VAR_COUNT;
  return BMI_SUCCESS;
}


int get_var_name(int index, char *name) {
  if (index < VAR_COUNT) {
    strcpy (name, var_names[index]);
  }
  else {
    return BMI_FAILURE;
  }
  return BMI_SUCCESS;
}

int get_var_index(const char *name, int *index) {
  *index = -1;
  int i;
  for (i = 0; i < VAR_COUNT; i++) {
    if (strcmp(name, var_names[i]) == 0) {
      *index = i;
    }
  }
  return BMI_SUCCESS;
} 


int get_var_role(const char *name, char *role) {
  int index;
  int status;
  status = get_var_index(name, &index);
  if (status != BMI_SUCCESS) {
    return status;
  }
  strcpy (role, roles[index]);
  return BMI_SUCCESS;
}


int
get_input_var_count(int *n) {
  int i;
  /* scan for input variables */
  for (i=0; i<VAR_COUNT; i++) {
    if(strstr(roles[i], "in")) {
      (*n)++;
    };
  }
  return BMI_SUCCESS;
}
  

int
get_input_var_names (char ** names)
{
  int i;
  int j;
  int n;
  get_input_var_count(&n);

  char *input_var_names[n];
  for (i = 0; i<n; i++) {
    input_var_names[i] = (char*) malloc (sizeof (char) * BMI_MAX_NAME);
  }
  /* input var index */
  j = 0;                        
  for (i=0; i<VAR_COUNT; i++) {
    if(strstr(roles[i], "in")) {
      strncpy (names[i], input_var_names[j], BMI_MAX_NAME);
      j++;
    }
  }
  return BMI_SUCCESS;
}
/* End: get_input_var_names */


int
get_output_var_count(int *n) {
  int i;
  /* scan for output variables */
  for (i=0; i<VAR_COUNT; i++) {
    if(strstr(roles[i], "out")) {
      (*n)++;
    };
  }
  return BMI_SUCCESS;
}
  

int
get_output_var_names (char ** names)
{
  int i;
  int j;
  int n;
  get_output_var_count(&n);

  char *output_var_names[n];
  for (i = 0; i<n; i++) {
    output_var_names[i] = (char*) malloc (sizeof (char) * BMI_MAX_NAME);
  }
  /* output var index */
  j = 0;                        
  for (i=0; i<VAR_COUNT; i++) {
    if(strstr(roles[i], "out")) {
      strncpy (names[i], output_var_names[j], BMI_MAX_NAME);
      j++;
    }
  }
  return BMI_SUCCESS;
}
/* End: get_output_var_names */

int
get_start_time (double * time)
{
  if (time) {
    *time = 0.;
    return BMI_SUCCESS;
  }
  else {
    return BMI_FAILURE;
  }
}
/* End: get_start_time */

int
get_end_time (double * time)
{
  *time = self->t_end;
  return BMI_SUCCESS;
}
/* End: get_end_time */

int
get_current_time (double * time)
{
  *time = self->t;
  return BMI_SUCCESS;
}
/* End: get_current_time */

int
get_time_step (double * dt)
{
  *dt = self->dt;
  return BMI_SUCCESS;
}
/* End: get_time_step */

int
get_time_units (char * units)
{
  strncpy (units, "-", BMI_MAX_NAME);
  return BMI_SUCCESS;
}
/* End: get_time_units */

