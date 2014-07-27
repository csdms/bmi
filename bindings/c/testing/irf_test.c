#include <bmi.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main (void)
{
  int err = BMI_SUCCESS;

  {
    fprintf (stdout, "Initializing... ");

    err = initialize (NULL);
    if (err)
      return EXIT_FAILURE;

    fprintf (stdout, "PASS\n");
  }

  {
    char name[BMI_MAX_NAME];
    get_component_name (name);
    fprintf (stdout, "%s\n", name);
  }

  {
    int i;
    const int n_steps = 10;
    double time;

    for (i = 0; i < n_steps; i++)
    {
      fprintf (stdout, "Running until t = %d... ", i+1);
      if (update (-1)==0 && get_current_time (&time)==0) {
        if (fabs (time-(i+1)) < 1e-6)
          fprintf (stdout, "PASS\n");
        else {
          return EXIT_FAILURE;
        }
      }
      else
        return EXIT_FAILURE;
    }

    fprintf (stdout, "Running until t = %f... ", 1000.5);
    if (update_until (1000.5)==0 && get_current_time (&time)==0) {
        if (fabs (time-1000.5) < 1e-6)
          fprintf (stdout, "PASS\n");
        else {
          fprintf (stdout, "%f\n", time);
          return EXIT_FAILURE;
        }
    }
    else
      return EXIT_FAILURE;
  }

  fprintf (stdout, "Finalizing... ");
  err = finalize ();
  if (err)
    return EXIT_FAILURE;
  fprintf (stdout, "PASS\n");

  return EXIT_SUCCESS;
}
