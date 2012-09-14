#include <bmi.hxx>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void print_var_names (BMI::Model model);

int
main (void)
{
  int i;
  const int n_steps = 10;
  BMI::Model model;

  model.initialize ("");

  std::cout << model.get_component_name () << std::endl;

  print_var_names (model);

  model.finalize ();

  return EXIT_SUCCESS;
}

void
print_var_names (BMI::Model model)
{
  char **var_names = NULL;
  char **name;

  var_names = (char**)model.get_input_var_names ();
  fprintf (stdout, "Input var names\n");
  fprintf (stdout, "===============\n");
  for (name = var_names; *name; name++)
    fprintf (stdout, "%s\n", *name);
  fprintf (stdout, "\n");

  var_names = (char**)model.get_output_var_names ();
  fprintf (stdout, "Output var names\n");
  fprintf (stdout, "================\n");
  for (name = var_names; *name; name++)
    fprintf (stdout, "%s\n", *name);
  fprintf (stdout, "\n");

  return;
}
