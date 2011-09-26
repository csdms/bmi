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

  self = BMI_Initialize (NULL);

  if (!self)
    return EXIT_FAILURE;

  fprintf (stdout, "%s\n", BMI_Get_component_name (self));

  for (i = 0; i < n_steps; i++)
  {
    fprintf (stdout, "Values at time %d\n", i);
    fprintf (stdout, "==============\n");
    print_var_values (self, "height_above_sea_floor");

    BMI_Update (self);
  }

  fprintf (stdout, "Values at time %d\n", i);
  fprintf (stdout, "==============\n");
  print_var_values (self, "height_above_sea_floor");

  BMI_Finalize (self);

  return EXIT_SUCCESS;
}

void
print_var_values (void *self, const char *var_name)
{
  double *var = NULL;
  int len;
  int i;

  fprintf (stdout, "Variable: %s\n", var_name);
  fprintf (stdout, "================\n");
  var = BMI_Get_1d_double (self, var_name, &len);
  for (i = 0; i < len; i++)
    fprintf (stdout, "%f\n", var[i]);
  fprintf (stdout, "\n");

  return;
}
