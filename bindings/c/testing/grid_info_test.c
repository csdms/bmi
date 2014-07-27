#include <bmi.h>
#include <bmi_grid.h>

#include <stdio.h>
#include <stdlib.h>

#define INPUT_VAR_NAME_COUNT 1
#define OUTPUT_VAR_NAME_COUNT 1


void print_var_info (const char *var);

int
main (void)
{
  initialize (NULL);

  {
    char name[BMI_MAX_NAME];
    get_component_name (name);
    fprintf (stdout, "%s\n", name);
  }

  {
    const char **vars = NULL;
    char **var = NULL;

    char *names[INPUT_VAR_NAME_COUNT];


    {
      int i;
      int n;
      char name[BMI_MAX_NAME];
      get_var_count (&n);
      for (i = 0; i<INPUT_VAR_NAME_COUNT; i++) {
        get_var_name(i, name);
        print_var_info (name);
      }
    }

  }
  finalize ();

  return EXIT_SUCCESS;
}

void
print_var_info (const char *var)
{
  char type[BMI_MAX_NAME];
  char units[BMI_MAX_NAME];
  int n_dims;
  int *shape;
  double *spacing;
  double *origin;

  get_var_type (var, type);
  get_var_units (var, units);
  get_var_rank (var, &n_dims);

  shape = (int*) malloc (sizeof (int)*n_dims);
  spacing = (double*) malloc (sizeof (double)*n_dims);
  origin = (double*) malloc (sizeof (double)*n_dims);

  get_grid_shape (var, shape);
  get_grid_spacing (var, spacing);
  get_grid_origin (var, origin);

  fprintf (stdout, "\n");
  fprintf (stdout, "Variable info\n");
  fprintf (stdout, "=============\n");
  fprintf (stdout, "Name: %s\n", var);
  fprintf (stdout, "Type: %s\n", type);
  fprintf (stdout, "Units: %s\n", units);
  fprintf (stdout, "Rank: %d\n", n_dims);
  fprintf (stdout, "Dimension: %d x %d\n", shape[0], shape[1]);
  fprintf (stdout, "Resolution: %f x %f\n", spacing[0], spacing[1]);
  fprintf (stdout, "Corner: %f x %f\n", origin[0], origin[1]);

  free (origin);
  free (spacing);
  free (shape);

  return;
}
