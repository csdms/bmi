#include <poisson/bmi_poisson.h>
#include <poisson/bmi.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main (void)
{
  void *self = NULL;
  int status = BMI_SUCCESS;

  {
    fprintf (stdout, "Initializing... ");

    status = BMI_POISSON_Initialize (NULL, &self);
    if (status == BMI_FAILURE || !self)
      return EXIT_FAILURE;

    fprintf (stdout, "PASS\n");
  }

  {
    char name[BMI_MAX_COMPONENT_NAME];

    status = BMI_POISSON_Get_component_name (self, name);
    if (status == BMI_FAILURE)
      return EXIT_FAILURE;

    fprintf (stdout, "%s\n", name);
  }

  {
    int i;
    const int n_steps = 10;
    double time;

    for (i = 0; i < n_steps; i++)
    {
      fprintf (stdout, "Running until t = %d... ", i+1);

      status = BMI_POISSON_Update (self);
      if (status == BMI_FAILURE)
        return EXIT_FAILURE;

      
      status = BMI_POISSON_Get_current_time (self, &time);
      if (status == BMI_FAILURE)
        return EXIT_FAILURE;

      if (fabs (time - (i + 1)) < 1e-6)
        fprintf (stdout, "PASS\n");
      else
        return EXIT_FAILURE;
    }

    fprintf (stdout, "Running until t = %f... ", 1000.5);

    status = BMI_POISSON_Update_until (self, 1000.5);
    if (status == BMI_FAILURE)
      return EXIT_FAILURE;

    status = BMI_POISSON_Get_current_time (self, &time);
    if (status == BMI_FAILURE)
      return EXIT_FAILURE;

    if (fabs (time-1000.5) < 1e-6)
      fprintf (stdout, "PASS\n");
    else {
      fprintf (stdout, "%f\n", time);
      return EXIT_FAILURE;
    }
  }

  fprintf (stdout, "Finalizing... ");

  status = BMI_POISSON_Finalize (self);
  if (status == BMI_FAILURE)
    return EXIT_FAILURE;

  fprintf (stdout, "PASS\n");

  return EXIT_SUCCESS;
}
