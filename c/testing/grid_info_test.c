#include <bmi.h>

#include <stdio.h>
#include <stdlib.h>

void print_var_info (void *self, const char *var);

int
main (void)
{
  void *self = NULL;

  self = BMI_Initialize (NULL);

  if (!self)
    return EXIT_FAILURE;

  fprintf (stdout, "%s\n", BMI_Get_component_name (self));

  {
    const char **vars = NULL;
    char **var = NULL;

    vars = BMI_Get_input_var_names (self);
    for (var = (char **)vars; *var; var++)
      print_var_info (self, *var);

    vars = BMI_Get_output_var_names (self);
    for (var = (char **)vars; *var; var++)
      print_var_info (self, *var);

  }

  BMI_Finalize (self);

  return EXIT_SUCCESS;
}

void
print_var_info (void *self, const char *var)
{
  const char *type = BMI_Get_var_type (self, var);
  const char *units = BMI_Get_var_units (self, var);
  int rank = 0;
  int *dimen = NULL;
  double *res = NULL;
  double *corner = NULL;
  int is_raster;

  dimen = BMI_Get_grid_dimen (self, var, &rank);
  res = BMI_Get_grid_res (self, var, &rank);
  corner = BMI_Get_grid_corner (self, var, &rank);
  is_raster = BMI_Is_raster_grid (self, var);

  fprintf (stdout, "\n");
  fprintf (stdout, "Variable info\n");
  fprintf (stdout, "=============\n");
  fprintf (stdout, "Name: %s\n", var);
  fprintf (stdout, "Type: %s\n", type);
  fprintf (stdout, "Units: %s\n", units);
  fprintf (stdout, "Rank: %d\n", rank);
  fprintf (stdout, "Dimension: %d\n", dimen[0]);
  fprintf (stdout, "Resolution: %f\n", res[0]);
  fprintf (stdout, "Corner: %f\n", corner[0]);
  if (is_raster)
    fprintf (stdout, "Grid type: %s\n", "Uniform");
  else
    fprintf (stdout, "Grid type: %s\n", "Non-uniform");

  free (corner);
  free (res);
  free (dimen);

  return;
}
