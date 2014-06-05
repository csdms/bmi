#include <bmi.hxx>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
  BMI::Model model;

  fprintf (stdout, "Initializing... ");
  model.initialize ("");
  fprintf (stdout, "Done\n");

  std::cout << model.get_component_name () << std::endl;

  {
    const int n_steps = 10;

    fprintf (stdout, "Running...\n");
    for (int i = 0; i < n_steps; i++)
    {
      model.update ();
      fprintf (stdout, "Time: %f\n", model.get_current_time ());
    }
    model.update_until (model.get_end_time ());
    fprintf (stdout, "Time: %f\n", model.get_current_time ());
    fprintf (stdout, "Done\n");
  }

  fprintf (stdout, "Finalizing... ");
  model.finalize ();
  fprintf (stdout, "Done\n");

  return EXIT_SUCCESS;
}
