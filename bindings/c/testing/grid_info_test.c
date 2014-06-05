#include <bmi.h>

#include <stdio.h>
#include <stdlib.h>

void print_var_info (void *self, const char *var);

int
main (void)
{
  BMI_Model *self = NULL;

  BMI_Initialize (NULL, &self);

  if (!self)
    return EXIT_FAILURE;

  {
    char name[BMI_MAX_COMPONENT_NAME];
    BMI_Get_component_name (self, name);
    fprintf (stdout, "%s\n", name);
  }

  {
    const char **vars = NULL;
    char **var = NULL;
    //char names[BMI_INPUT_VAR_NAME_COUNT][BMI_MAX_VAR_NAME];
    char *names[BMI_INPUT_VAR_NAME_COUNT];


    {
      int i;

      for (i = 0; i<BMI_INPUT_VAR_NAME_COUNT; i++)
        names[i] = (char*) malloc (sizeof (char) * BMI_MAX_VAR_NAME);

      BMI_Get_input_var_names (self, names);
      for (i = 0; i<BMI_INPUT_VAR_NAME_COUNT; i++)
        print_var_info (self, names[i]);

      BMI_Get_output_var_names (self, names);
      for (i = 0; i<BMI_OUTPUT_VAR_NAME_COUNT; i++)
        print_var_info (self, names[i]);
    }
  }

  BMI_Finalize (self);

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

  BMI_Get_var_type (self, var, &type);
  BMI_Get_var_units (self, var, units);
  BMI_Get_var_rank (self, var, &n_dims);

  shape = (int*) malloc (sizeof (int)*n_dims);
  spacing = (double*) malloc (sizeof (double)*n_dims);
  origin = (double*) malloc (sizeof (double)*n_dims);

  BMI_Get_grid_shape (self, var, shape);
  BMI_Get_grid_spacing (self, var, spacing);
  BMI_Get_grid_origin (self, var, origin);

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
