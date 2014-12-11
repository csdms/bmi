#include <poisson/bmi.h>
#include <poisson/bmi_poisson.h>

#include <stdio.h>
#include <stdlib.h>

void print_var_values (void *self, const char *var_name);

int
main (void)
{
  int i;
  const int n_steps = 10;
  void *self = NULL;
  double *new_vals = NULL;
  int err = 0;

  err = BMI_POISSON_Initialize (NULL, &self);
  if (err || !self)
    return EXIT_FAILURE;

  {
    char name[BMI_MAX_COMPONENT_NAME];
    BMI_POISSON_Get_component_name (self, name);
  
    fprintf (stdout, "%s\n", name);
  }

  { /* Get grid information */
    int n_dims;
    int *shape;
    int len = 0;
    int i;

    BMI_POISSON_Get_var_rank (self, "land_surface__elevation", &n_dims);
    shape = (int*) malloc (sizeof (int)*n_dims);

    BMI_POISSON_Get_grid_shape (self, "land_surface__elevation", shape);
    for (i = 0, len = 1; i < n_dims; i++)
      len *= shape[i];

    new_vals = (double *)malloc (sizeof (double) * len);
    for (i = 0; i < len; i++)
      new_vals[i] = -1;

    free (shape);
  }

  fprintf (stdout, "Values before set\n");
  fprintf (stdout, "=================\n");
  print_var_values (self, "land_surface__elevation");

  BMI_POISSON_Set_value (self, "land_surface__elevation", new_vals);

  fprintf (stdout, "Values after set\n");
  fprintf (stdout, "================\n");
  print_var_values (self, "land_surface__elevation");

  {
    int inds[5] = {1, 2, 4, 8, 16};
    double vals[5] = {11, 22, 44, 88, 1616};
    double *p;
    int i;

    BMI_POISSON_Set_value_at_indices (self, "land_surface__elevation", inds, 5, vals);
    print_var_values (self, "land_surface__elevation");

    BMI_POISSON_Get_value_ptr (self, "land_surface__elevation", (void**)(&p));
    for (i=0; i<5; i++) {
      fprintf (stdout, "Checking %d...", inds[i]);
      if (p[inds[i]] == vals[i])
        fprintf (stdout, "PASS\n");
    }
  }

  free (new_vals);

  BMI_POISSON_Finalize (self);

  return EXIT_SUCCESS;
}

void
print_var_values (void *self, const char *var_name)
{
  double *var = NULL;
  int n_dims = 0;
  int *shape = NULL;

  BMI_POISSON_Get_var_rank (self, var_name, &n_dims);
  shape = (int*) malloc (sizeof (int)*n_dims);

  BMI_POISSON_Get_grid_shape (self, "land_surface__elevation", shape);
  BMI_POISSON_Get_value_ptr (self, var_name, (void**)(&var));

  fprintf (stdout, "Variable: %s\n", var_name);
  fprintf (stdout, "Number of dimension: %d\n", n_dims);
  fprintf (stdout, "Shape: %d x %d\n", shape[0], shape[1]);
  fprintf (stdout, "================\n");

  {
    int i, j;
    for (i = 0; i < shape[0]; i++) {
      for (j = 0; j < shape[1]; j++)
        fprintf (stdout, "%f ", var[i*shape[1]+j]);
      fprintf (stdout, "\n");
    }
  }

  return;
}
