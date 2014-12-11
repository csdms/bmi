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
  double *new_vals = NULL;
  int err = 0;

  //self = BMI_Initialize (NULL);
  err = initialize (NULL);
  if (err)
    return EXIT_FAILURE;

  {
    char name[BMI_MAX_NAME];
    get_component_name (name);
  
    fprintf (stdout, "%s\n", name);
  }

  { /* Get grid information */
    int n_dims;
    int *shape;
    int len = 0;
    int i;

    get_var_rank ("surface_elevation", &n_dims);
    shape = (int*) malloc (sizeof (int)*n_dims);

    get_grid_shape ("surface_elevation", shape);
    for (i = 0, len = 1; i < n_dims; i++)
      len *= shape[i];

    new_vals = (double *)malloc (sizeof (double) * len);
    for (i = 0; i < len; i++)
      new_vals[i] = -1;

    free (shape);
  }

  fprintf (stdout, "Values before set\n");
  fprintf (stdout, "=================\n");
  print_var_values ("surface_elevation");

  set_var ("surface_elevation", &new_vals);

  fprintf (stdout, "Values after set\n");
  fprintf (stdout, "================\n");
  print_var_values ("surface_elevation");

  {
    int inds[5] = {1, 2, 4, 8, 16};
    double vals[5] = {11, 22, 44, 88, 1616};
    void *p;
    int i;

    set_var_at_indices ("surface_elevation", inds, 5, (void *)(&vals));
    print_var_values ("surface_elevation");

    get_var ("surface_elevation", &p);
    for (i=0; i<5; i++) {
      fprintf (stdout, "Checking %d...", inds[i]);
      if (((double*)p)[inds[i]] == vals[i])
        fprintf (stdout, "PASS\n");
    }
  }

  free (new_vals);

  finalize ();

  return EXIT_SUCCESS;
}

void
print_var_values (const char *var_name)
{
  double *var = NULL;
  int n_dims = 0;
  int *shape = NULL;

  get_var_rank (var_name, &n_dims);
  shape = (int*) malloc (sizeof (int)*n_dims);

  get_grid_shape ("surface_elevation", shape);
  /* Point var the model variable named var_name */
  get_var (var_name, (void *)&var);

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
