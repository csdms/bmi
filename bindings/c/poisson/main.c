#include <stdio.h>

#include "poisson.h"
  
int
main(void)
{
  PoissonModel * p = poisson_from_default ();
  int i, j, t;

  for (t=0; t<10; t++) {
    poisson_advance_in_time (p);

    fprintf (stdout, "Time: %f\n", p->t);

    for (i=0; i<p->shape[0]; i++) {
      for (j=0; j<p->shape[1]; j++)
        fprintf (stdout, "%f ", p->z[i][j]);
      fprintf (stdout, "\n");
    }
    fprintf (stdout, "\n");
  }

  return 0;
}
