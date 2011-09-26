#include <bmi.h>

#include <stdio.h>
#include <stdlib.h>

void print_var_values (void *self, const char *var_name);

int
main (void)
{
  int i;
  const int n_steps = 10;
  void *self = NULL;
  double *new_vals = NULL;

  self = BMI_Initialize (NULL);

  if (!self)
    return EXIT_FAILURE;

  fprintf (stdout, "%s\n", BMI_Get_component_name (self));

  {     /* Get grid information */
    int rank = 0;
    int *dimen = NULL;
    int len = 0;
    int i;

    dimen = BMI_Get_grid_dimen (self, "height_above_sea_floor", &rank);
    len = dimen[0];

    new_vals = (double *)malloc (sizeof (double) * len);
    for (i = 0; i < len; i++)
      new_vals[i] = -1;

    free (dimen);
  }

  fprintf (stdout, "Values before set\n");
  fprintf (stdout, "=================\n");
  print_var_values (self, "height_above_sea_floor");

  BMI_Set_1d_double (self, "height_above_sea_floor", new_vals);

  fprintf (stdout, "Values after set\n");
  fprintf (stdout, "================\n");
  print_var_values (self, "height_above_sea_floor");

  free (new_vals);

  BMI_Finalize (self);

  return EXIT_SUCCESS;
}

void
print_var_values (void *self, const char *var_name)
{
  double *var = NULL;
  int len;
  int i;

  fprintf (stdout, "Variable: %s\n\n", var_name);
  var = BMI_Get_1d_double (self, var_name, &len);
  for (i = 0; i < len; i++)
    fprintf (stdout, "%f\n", var[i]);
  fprintf (stdout, "\n");

  return;
}
