#include <poisson/bmi.h>
#include <poisson/bmi_poisson.h>

#include <stdio.h>
#include <stdlib.h>

void print_var_names (void *self);

int
main (void)
{
  int i;
  const int n_steps = 10;
  void *self = NULL;

  if (BMI_POISSON_Initialize (NULL, &self)!=0 || !self)
    return EXIT_FAILURE;

  {
    char name[BMI_MAX_COMPONENT_NAME];
    BMI_POISSON_Get_component_name (self, name);
    fprintf (stdout, "%s\n", name);
  }

  print_var_names (self);

  if (BMI_POISSON_Finalize (self) != 0)
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}

void
print_var_names (void *self)
{
  { /* Print the input var names */
    int n_names;
    char **names = NULL;
    int i;

    BMI_POISSON_Get_input_var_name_count(self, &n_names);

    names = (char**) malloc (sizeof(char *) * n_names);
    for (i=0; i<n_names; i++)
      names[i] = (char*) malloc (sizeof(char) * BMI_MAX_VAR_NAME);

    BMI_POISSON_Get_input_var_names (self, names);

    fprintf (stdout, "Input var names\n");
    fprintf (stdout, "===============\n");
    for (i = 0; i<n_names; i++)
      fprintf (stdout, "%s\n", names[i]);

    for (i=0; i<n_names; i++)
      free (names[i]);
    free (names);

  }

  fprintf (stdout, "\n");

  { /* Print the output var names */
    int n_names;
    char **names = NULL;
    int i;

    BMI_POISSON_Get_output_var_name_count(self, &n_names);

    names = (char**) malloc (sizeof(char *) * n_names);
    for (i=0; i<n_names; i++)
      names[i] = (char*) malloc (sizeof(char) * BMI_MAX_VAR_NAME);

    BMI_POISSON_Get_output_var_names (self, names);

    fprintf (stdout, "Output var names\n");
    fprintf (stdout, "===============\n");
    for (i = 0; i<n_names; i++)
      fprintf (stdout, "%s\n", names[i]);

    for (i=0; i<n_names; i++)
      free (names[i]);
    free (names);

  }
}
