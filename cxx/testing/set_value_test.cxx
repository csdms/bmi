#include <bmi.hxx>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void print_matrix (double *m, int n_dims, int * shape);
void print_var_values (BMI::Model model, const char *var_name);

int
main (void)
{
  int i;
  const int n_steps = 10;
  BMI::Model model;
  double *new_vals = NULL;
  int *shape = NULL;
  int n_dims = 0;

  model.initialize ("");

  std::cout << model.get_component_name () << std::endl;

  n_dims = model.get_var_rank ("surface_elevation");
  shape = new int[n_dims];
  model.get_grid_shape ("surface_elevation", shape);

  new_vals = (double*)model.get_value_ptr ("surface_elevation");

  fprintf (stdout, "Values before set\n");
  fprintf (stdout, "=================\n");
  print_matrix (new_vals, n_dims, shape);

  new_vals[0] = -1;

  { /* Allocate memory */
    int len = 0;

    len = shape[0] * shape[1];

    new_vals = new double[len];
    for (int i = 0; i < len; i++)
      new_vals[i] = -1;
  }

  model.get_value ("surface_elevation", (void*)new_vals);
  print_matrix (new_vals, n_dims, shape);

  new_vals[0] = 1.;

  model.set_double ("surface_elevation", new_vals);

  fprintf (stdout, "Values after set\n");
  fprintf (stdout, "================\n");
  print_matrix (new_vals, n_dims, shape);


  delete shape;
  delete new_vals;

  model.finalize ();

  return EXIT_SUCCESS;
}

void
print_matrix (double *m, int n_dims, int * shape)
{
  int i, j;

  fprintf (stdout, "Number of dimension: %d\n", n_dims);
  fprintf (stdout, "Shape: %d x %d\n", shape[0], shape[1]);
  fprintf (stdout, "================\n");

  for (i = 0; i < shape[0]; i++) {
    for (j = 0; j < shape[1]; j++)
      fprintf (stdout, "%f ", m[i*shape[1]+j]);
    fprintf (stdout, "\n");
  }
}

void
print_var_values (BMI::Model model, const char *var_name)
{
  int n_dims = model.get_var_rank (var_name);
  int *shape = new int[n_dims];
  double *var = NULL;
  int i, j;

  model.get_grid_shape (var_name, shape);

  var = new double[shape[0]*shape[1]];

  model.get_double (var_name, var);

  fprintf (stdout, "Variable: %s\n", var_name);

  print_matrix (var, n_dims, shape);

  delete var;
  delete shape;

  return;
}
