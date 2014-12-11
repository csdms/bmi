#include <poisson/bmi.h>
#include <poisson/bmi_poisson.h>

#include <stdio.h>
#include <stdlib.h>

void print_var_info (void *self, const char *var);

int
main (void)
{
  void *self = NULL;

  BMI_POISSON_Initialize (NULL, &self);

  if (!self)
    return EXIT_FAILURE;

  {
    char name[BMI_MAX_COMPONENT_NAME];
    BMI_POISSON_Get_component_name (self, name);
    fprintf (stdout, "%s\n", name);
  }

  { /* Input items */
    int n_names;
    char **names = NULL;
    int i;

    BMI_POISSON_Get_input_var_name_count(self, &n_names);

    names = (char**) malloc (sizeof(char*) * n_names);
    for (i = 0; i<n_names; i++)
      names[i] = (char*) malloc (sizeof (char) * BMI_MAX_VAR_NAME);

    BMI_POISSON_Get_input_var_names (self, names);
    for (i = 0; i<n_names; i++)
      print_var_info (self, names[i]);

    for (i = 0; i<n_names; i++)
      free (names[i]);
    free (names);
  }

  { /* Output items */
    int n_names;
    char **names = NULL;
    int i;

    BMI_POISSON_Get_output_var_name_count(self, &n_names);

    names = (char**) malloc (sizeof(char*) * n_names);
    for (i = 0; i<n_names; i++)
      names[i] = (char*) malloc (sizeof (char) * BMI_MAX_VAR_NAME);

    BMI_POISSON_Get_output_var_names (self, names);
    for (i = 0; i<n_names; i++)
      print_var_info (self, names[i]);

    for (i = 0; i<n_names; i++)
      free (names[i]);
    free (names);
  }

  BMI_POISSON_Finalize (self);

  return EXIT_SUCCESS;
}

void
print_var_info (void *self, const char *var)
{
  BMI_Var_type type;
  char units[BMI_MAX_UNITS_NAME];
  int n_dims;
  int *shape;
  double *spacing;
  double *origin;

  BMI_POISSON_Get_var_type (self, var, &type);
  BMI_POISSON_Get_var_units (self, var, units);
  BMI_POISSON_Get_var_rank (self, var, &n_dims);

  shape = (int*) malloc (sizeof (int)*n_dims);
  spacing = (double*) malloc (sizeof (double)*n_dims);
  origin = (double*) malloc (sizeof (double)*n_dims);

  BMI_POISSON_Get_grid_shape (self, var, shape);
  BMI_POISSON_Get_grid_spacing (self, var, spacing);
  BMI_POISSON_Get_grid_origin (self, var, origin);

  fprintf (stdout, "\n");
  fprintf (stdout, "Variable info\n");
  fprintf (stdout, "=============\n");
  fprintf (stdout, "Name: %s\n", var);
  fprintf (stdout, "Type: %d\n", type);
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
