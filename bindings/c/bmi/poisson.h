#ifndef POISSON_H_INCLUDED
#define POISSON_H_INCLUDED

#if defined(__cplusplus)
extern "C" {
#endif


typedef struct {
  double dt;
  double t;
  double t_end;

  int shape[2];
  double spacing[2];
  double **z;

  double **temp_z;
} PoissonModel;


extern PoissonModel * poisson_from_input_file (const char * filename);
extern PoissonModel * poisson_from_default (void);
extern int poisson_advance_in_time (PoissonModel * self);
extern int poisson_solve_2d (double ** z, int shape[2], double spacing[2], double ** out);

#if defined(__cplusplus)
}
#endif

#endif
