#include <bmi.h>

#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
  void *self = NULL;

  fprintf (stdout, "Initializing... ");
  self = BMI_Initialize (NULL);
  fprintf (stdout, "Done\n");

  fprintf (stdout, "%s\n", BMI_Get_component_name (self));

  if (!self)
    return EXIT_FAILURE;

  {
    int i;
    const int n_steps = 10;

    fprintf (stdout, "Running...\n");
    for (i = 0; i < n_steps; i++)
    {
      fprintf (stdout, "Time step: %d\n", i);
      BMI_Update (self);
    }
    fprintf (stdout, "Done\n\n");
  }

  fprintf (stdout, "Finalizing... ");
  BMI_Finalize (self);
  fprintf (stdout, "Done\n");

  return EXIT_SUCCESS;
}
