#include "poisson.h"
  
int
main(void)
{
  PoissonModel * p = poisson_from_default ();

  poisson_advance_in_time (p);

  return 0;
}
