#include <bmi.hxx>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void print_var_values (BMI::Model model, const char *var_name);

int
main (void)
{
  int i;
  const int n_steps = 10;
  BMI::Model model;
  double *new_vals = NULL;

  model.initialize ("");

  std::cout << model.get_component_name () << std::endl;

  { /* Get grid information */
    int n_dims = 0;
    int *shape = NULL;
    int len = 0;
    int i;

    shape = model.get_grid_shape ("surface_elevation", n_dims);
    len = shape[0] * shape[1];

    new_vals = (double *)malloc (sizeof (double) * len);
    for (i = 0; i < len; i++)
      new_vals[i] = -1;

    free (shape);
  }

  fprintf (stdout, "Values before set\n");
  fprintf (stdout, "=================\n");
  print_var_values (model, "surface_elevation");

  model.set_double ("surface_elevation", new_vals);

  fprintf (stdout, "Values after set\n");
  fprintf (stdout, "================\n");
  print_var_values (model, "surface_elevation");

  free (new_vals);

  model.finalize ();

  return EXIT_SUCCESS;
}

void
print_var_values (BMI::Model model, const char *var_name)
{
  double *var = NULL;
  int n_dims;
  int *shape;
  int i, j;

  shape = model.get_grid_shape (var_name, n_dims);
  var = model.get_double (var_name, n_dims);

  fprintf (stdout, "Variable: %s\n", var_name);
  fprintf (stdout, "Number of dimension: %d\n", n_dims);
  fprintf (stdout, "Shape: %d x %d\n", shape[0], shape[1]);
  fprintf (stdout, "================\n");

  for (i = 0; i < shape[0]; i++) {
    for (j = 0; j < shape[1]; j++)
      fprintf (stdout, "%f ", var[i*shape[1]+j]);
    fprintf (stdout, "\n");
  }

  return;
}
