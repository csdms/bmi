#include <bmi.hxx>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void print_var_info (BMI::Model model, const char *var);

int
main (void)
{
  BMI::Model model;

  model.initialize ("");

  std::cout << model.get_component_name () << std::endl;

  {
    const char **vars = NULL;
    char **var = NULL;

    vars = model.get_input_var_names ();
    for (var = (char **)vars; *var; var++)
      print_var_info (model, *var);

    vars = model.get_output_var_names ();
    for (var = (char **)vars; *var; var++)
      print_var_info (model, *var);

  }

  model.finalize ();

  return EXIT_SUCCESS;
}

void
print_var_info (BMI::Model model, const char *var)
{
  std::string type = model.get_var_type (std::string (var));
  std::string units = model.get_var_units (std::string (var));
  int n_dims = model.get_var_rank (std::string (var));
  int *shape = new int[n_dims];
  double *spacing = new double[n_dims];
  double *origin = new double[n_dims];

  model.get_grid_shape (var, shape);
  model.get_grid_spacing (var, spacing);
  model.get_grid_origin (var, origin);

  fprintf (stdout, "\n");
  fprintf (stdout, "Variable info\n");
  fprintf (stdout, "=============\n");
  fprintf (stdout, "Name: %s\n", var);
  fprintf (stdout, "Type: %s\n", type.c_str ());
  fprintf (stdout, "Units: %s\n", units.c_str ());
  fprintf (stdout, "Rank: %d\n", n_dims);
  fprintf (stdout, "Dimension: %d x %d\n", shape[0], shape[1]);
  fprintf (stdout, "Resolution: %f x %f\n", spacing[0], spacing[1]);
  fprintf (stdout, "Corner: %f x %f\n", origin[0], origin[1]);

  delete origin;
  delete spacing;
  delete shape;

  return;
}
