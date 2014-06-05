#include <bmi.h>

#include <stdio.h>
#include <stdlib.h>

void print_var_values (void *self, const char *var_name);

int
main (void)
{
  int i;
  const int n_steps = 10;
  BMI_Model *self = NULL;

  BMI_Initialize (NULL, &self);

  if (!self)
    return EXIT_FAILURE;

  {
    char name[BMI_MAX_COMPONENT_NAME];
    BMI_Get_component_name (self, name);
    fprintf (stdout, "%s\n", name);
  }

  for (i = 0; i < n_steps; i++)
  {
    fprintf (stdout, "Values at time %d\n", i);
    fprintf (stdout, "==============\n");
    print_var_values (self, "surface_elevation");

    BMI_Update (self);
  }

  fprintf (stdout, "Values at time %d\n", i);
  fprintf (stdout, "==============\n");
  print_var_values (self, "surface_elevation");

  BMI_Finalize (self);

  return EXIT_SUCCESS;
}

void
print_var_values (void *self, const char *var_name)
{
  double *var = NULL;
  int len;
  int rank;
  int *shape;

  BMI_Get_var_rank (self, var_name, &rank);
  fprintf (stderr, "rank = %d\n", rank);
  shape = (int*) malloc (sizeof (int) * rank);

  BMI_Get_grid_shape (self, var_name, shape);
  fprintf (stderr, "shape = %d x %d\n", shape[0], shape[1]);

  {
    int n;
    for (n = 0, len = 1; n < rank; n++)
      len *= shape[n];
  }

  var = (double*) malloc (sizeof (double)*len);

  BMI_Get_value (self, var_name, var);

  fprintf (stdout, "Variable: %s\n", var_name);
  fprintf (stdout, "================\n");

  {
    int i, j;
    for (i = 0; i < shape[0]; i++) {
      for (j = 0; j < shape[1]; j++)
        fprintf (stdout, "%f ", var[i*shape[1] + j]);
      fprintf (stdout, "\n");
    }
  }

  free (var);
  free (shape);

  return;
}
