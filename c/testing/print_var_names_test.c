#include <bmi.h>

#include <stdio.h>
#include <stdlib.h>

void print_var_names (void *self);

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

  print_var_names (self);

  BMI_Finalize (self);

  return EXIT_SUCCESS;
}

void
print_var_names (void *self)
{
  const char **var_names = NULL;
  const char **name;

  var_names = BMI_Get_input_var_names (self);
  fprintf (stdout, "Input var names\n");
  fprintf (stdout, "===============\n");
  for (name = var_names; *name; name++)
    fprintf (stdout, "%s\n", *name);
  fprintf (stdout, "\n");

  var_names = BMI_Get_output_var_names (self);
  fprintf (stdout, "Output var names\n");
  fprintf (stdout, "================\n");
  for (name = var_names; *name; name++)
    fprintf (stdout, "%s\n", *name);
  fprintf (stdout, "\n");

  return;
}
