#include <bmi.hxx>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void print_var_values (BMI::Model model, const char *var_name);
void print_var_column (BMI::Model model, const char *var_name, int colno);

int
main (void)
{
  int i;
  const int n_steps = 10;
  BMI::Model model;

  model.initialize ("");

  std::cout << model.get_component_name () << std::endl;

  for (i = 0; i < n_steps; i++)
  {
    fprintf (stdout, "Values at time %d\n", i);
    fprintf (stdout, "==============\n");
    print_var_values (model, "surface_elevation");

    model.update_until (i);
  }

  fprintf (stdout, "Values at time %d\n", i);
  fprintf (stdout, "==============\n");
  print_var_values (model, "surface_elevation");

  model.finalize ();

  return EXIT_SUCCESS;
}

void
print_var_column (BMI::Model model, const char *name, int colno)
{
  const int n_dims = model.get_var_rank (name);
  int * shape = new int[n_dims];

  model.get_grid_shape (name, shape);

  {
    //int * inds = new int[shape[0]];
    //double * col = new double[shape[0]];
    int * inds = (int*)malloc (sizeof (int)*shape[0]);
    //double * col = (double*)malloc (sizeof (double)*shape[0]);
    double * col = NULL;

    inds[0] = colno;
    for (int i=1; i<shape[0]; i++)
      inds[i] = inds[i-1] + shape[1];

    col = model.get_double_at_indices (name, NULL, inds, shape[0]);

    fprintf (stdout, "Column %d: ", colno);
    for (int i=0; i<shape[0]; i++)
      fprintf (stdout, "%f ", col[i]);
    fprintf (stdout, "\n");

    free (col);
    free (inds);
    //delete col;
    //delete inds;
  }

  delete shape;

  return;
}

void
print_var_values (BMI::Model model, const char *var_name)
{
  int n_dims = model.get_var_rank (var_name);
  int *shape = new int[n_dims];
  double *var = NULL;
  int i, j;

  model.get_grid_shape (var_name, shape);

  //var = new double[shape[0]*shape[1]];
  var = model.get_double (var_name, NULL);

  fprintf (stdout, "Variable: %s\n", var_name);
  fprintf (stdout, "Number of dimension: %d\n", n_dims);
  fprintf (stdout, "Shape: %d x %d\n", shape[0], shape[1]);
  fprintf (stdout, "================\n");

  for (i = 0; i < shape[0]; i++) {
    for (j = 0; j < shape[1]; j++)
      fprintf (stdout, "%f ", var[i*shape[1]+j]);
    fprintf (stdout, "\n");
  }

  print_var_column (model, var_name, 1);
  print_var_column (model, var_name, shape[1]-2);

  //delete var;
  delete shape;

  return;
}
