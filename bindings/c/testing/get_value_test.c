#include <bmi.h>
#include <bmi_grid.h>

#include <stdio.h>
#include <stdlib.h>

void print_var_values (const char *var_name);

int
main (void)
{
  int i;
  const int n_steps = 10;
  initialize (NULL);

  {
    char name[BMI_MAX_NAME];
    get_component_name (name);
    fprintf (stdout, "%s\n", name);
  }

  for (i = 0; i < n_steps; i++)
  {
    fprintf (stdout, "Values at time %d\n", i);
    fprintf (stdout, "==============\n");
    print_var_values ("surface_elevation");

    update (-1);
  }

  fprintf (stdout, "Values at time %d\n", i);
  fprintf (stdout, "==============\n");
  print_var_values ("surface_elevation");

  finalize ();

  return EXIT_SUCCESS;
}

void
print_var_values (const char *var_name)
{
  double *var;
  int len;
  int rank;
  int *shape;

  get_var_rank (var_name, &rank);
  fprintf (stderr, "rank = %d\n", rank);
  shape = (int*) malloc (sizeof (int) * rank);

  get_grid_shape (var_name, shape);
  fprintf (stderr, "shape = %d x %d\n", shape[0], shape[1]);

  {
    int n;
    for (n = 0, len = 1; n < rank; n++)
      len *= shape[n];
  }

  /* Get a reference to the variable */
  get_var (var_name, (void *)&var);

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

  free (shape);

  return;
}
