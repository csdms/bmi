#include <bmi.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT_VAR_NAME_COUNT 1
#define OUTPUT_VAR_NAME_COUNT 1


void print_var_names ();

int
main (void)
{
  int i;
  const int n_steps = 10;

  if (initialize (NULL)!=0 )
    return EXIT_FAILURE;

  {
    char name[BMI_MAX_NAME];
    get_component_name (name);
    fprintf (stdout, "%s\n", name);
  }

  print_var_names ();

  if (finalize () != 0)
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}

void
print_var_names (void *self)
{
  {
    int i;

    int n;
    char name[BMI_MAX_NAME];
    char role[BMI_MAX_NAME];

    fprintf (stdout, "Input var names\n");
    fprintf (stdout, "================\n");
    get_var_count(&n);
    for (i = 0; i < n; i++) {
      get_var_name(i, name);
      get_var_role(name, role);
      if (strstr(role, "in")) {
        fprintf (stdout, "%s\n", name);
      }
    }
    fprintf (stdout, "\n");

    fprintf (stdout, "Output var names\n");
    fprintf (stdout, "================\n");
    for (i = 0; i < n; i++) {
      get_var_role(name, role);
      if (strstr(role, "out")) {
        fprintf (stdout, "%s\n", name);
      }
    }
  }
}
