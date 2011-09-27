#ifndef BMI_INCLUDED
#define BMI_INCLUDED

#if defined(__cplusplus)
extern "C" {
#endif

void *BMI_Initialize (const char *);
void BMI_Update (void *);
void BMI_Finalize (void *);
void BMI_Run_model (void *);

const char *BMI_Get_var_type (void *, const char *);
const char *BMI_Get_var_units (void *, const char *);
int BMI_Get_var_rank (void *, const char *);
const char *BMI_Get_var_name (void *, const char *);

// Assumes arrays start at 0, and have contiguous elements (unit stride).
double BMI_Get_0d_double (void *, const char *);
double *BMI_Get_1d_double (void *, const char *, int [1]);
double *BMI_Get_2d_double (void *, const char *, int [2]);
double *BMI_Get_3d_double (void *, const char *, int [3]);
double *BMI_Get_1d_double_at_indices (void *, const char *, int *,
    int , double *);
double *BMI_Get_2d_double_at_indices (void *, const char *, int *, int);
// A more general getter
double *BMI_Get_double (void *, const char *, int *, int **);

void BMI_Set_0d_double (void *, const char *, double);
void BMI_Set_1d_double (void *, const char *, const double *);
void BMI_Set_2d_double (void *, const char *, const double *);
void BMI_Set_3d_double (void *, const char *, const double *);
void BMI_Set_2d_double_at_indices (void *, const char *, int *,
    const double *, int);

int BMI_Get_0d_int (void *, const char *);
int *BMI_Get_1d_int (void *, const char *, int [1]);
int *BMI_Get_2d_int (void *, const char *, int [2]);
int *BMI_Get_3d_int (void *, const char *, int [3]);
int *BMI_Get_2d_int_at_indices (void *, const char *, int *, int);

void BMI_Set_0d_int (void *, const char *, int);
void BMI_Set_1d_int (void *, const char *, const int *);
void BMI_Set_2d_int (void *, const char *, const int *);
void BMI_Set_3d_int (void *, const char *, const int *);
void BMI_Set_2d_int_at_indices (void *, const char *, int *,
    const int *, int);

// Assume string arrays are NULL-terminated
const char *BMI_Get_component_name (void *);
const char **BMI_Get_input_var_names (void *);
const char **BMI_Get_output_var_names (void *);

int *BMI_Get_grid_dimen (void *, const char *, int *);
double *BMI_Get_grid_res (void *, const char *, int *);
double *BMI_Get_grid_corner (void *, const char *, int *);

/*
  IElementSet get_Element_Set (void *handle);
  IValueSet get_Value_Set (void *handle, char *long_var_name, ITimeStamp);
*/

// Since these are just wrappers for other BMI functions, I don't
// think they should be included in the interface definition. They
// could be CMI functions.
int BMI_Is_scalar (void *, const char *);
int BMI_Is_vector (void *, const char *);
int BMI_Is_grid (void *, const char *);
int BMI_Has_var (void *, const char *);

// However, something that indicates if the grid is raster, or
// uniform rectilinear would be needed.
int BMI_Is_raster_grid (void *, const char *);

#if defined(__cplusplus)
}
#endif

#endif
