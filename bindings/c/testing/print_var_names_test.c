#include <bmi.h>

#include <stdio.h>
#include <stdlib.h>

void print_var_names (void *self);

int
main (void)
{
  int i;
  const int n_steps = 10;
  BMI_Model *self = NULL;

  if (BMI_Initialize (NULL, &self)!=0 || !self)
    return EXIT_FAILURE;

  {
    char name[BMI_MAX_COMPONENT_NAME];
    BMI_Get_component_name (self, name);
    fprintf (stdout, "%s\n", name);
  }

  print_var_names (self);

  if (BMI_Finalize (self) != 0)
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}

void
print_var_names (void *self)
{
  {
    int i;
    char *inputs[BMI_INPUT_VAR_NAME_COUNT];
    char *outputs[BMI_OUTPUT_VAR_NAME_COUNT];

    for (i = 0; i<BMI_INPUT_VAR_NAME_COUNT; i++)
      inputs[i] = (char*) malloc (sizeof (char) * BMI_MAX_VAR_NAME);
    for (i = 0; i<BMI_OUTPUT_VAR_NAME_COUNT; i++)
      outputs[i] = (char*) malloc (sizeof (char) * BMI_MAX_VAR_NAME);

    BMI_Get_input_var_names (self, inputs);
    BMI_Get_output_var_names (self, outputs);

    fprintf (stdout, "Input var names\n");
    fprintf (stdout, "===============\n");
    for (i = 0; i<BMI_INPUT_VAR_NAME_COUNT; i++)
      fprintf (stdout, "%s\n", inputs[i]);

    fprintf (stdout, "\n");

    fprintf (stdout, "Output var names\n");
    fprintf (stdout, "================\n");
    for (i = 0; i<BMI_OUTPUT_VAR_NAME_COUNT; i++)
      fprintf (stdout, "%s\n", outputs[i]);
  }
}
