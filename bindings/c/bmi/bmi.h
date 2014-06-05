#ifndef BMI_INCLUDED
#define BMI_INCLUDED

#if defined(__cplusplus)
extern "C" {
#endif

typedef enum
{
  CMI_STATUS_CREATED,
  CMI_STATUS_INITIALIZING,
  CMI_STATUS_INITIALIZED,
  CMI_STATUS_UPDATING,
  CMI_STATUS_UPDATED,
  CMI_STATUS_FINALIZING,
  CMI_STATUS_FINALIZED
}
CMI_Component_status;

typedef enum {
  BMI_GRID_TYPE_UNKNOWN = 0,
  BMI_GRID_TYPE_UNIFORM,
  BMI_GRID_TYPE_RECTILINEAR,
  BMI_GRID_TYPE_STRUCTURED,
  BMI_GRID_TYPE_UNSTRUCTURED,
  BMI_GRID_TYPE_NUMBER
}
BMI_Grid_type;

typedef enum {
  BMI_VAR_TYPE_UNKNOWN = 0,
  BMI_VAR_TYPE_CHAR,
  BMI_VAR_TYPE_UNSIGNED_CHAR,
  BMI_VAR_TYPE_INT,
  BMI_VAR_TYPE_LONG,
  BMI_VAR_TYPE_UNSIGNED_INT,
  BMI_VAR_TYPE_UNSIGNED_LONG,
  BMI_VAR_TYPE_FLOAT,
  BMI_VAR_TYPE_DOUBLE,
  BMI_VAR_TYPE_NUMBER
}
BMI_Var_type;

#define BMI_SUCCESS (0)
#define BMI_FAILURE (1)

#define BMI_MAX_UNITS_NAME 2048
#define BMI_MAX_COMPONENT_NAME 2048
#define BMI_MAX_VAR_NAME 2048

#define BMI_INPUT_VAR_NAME_COUNT 1
#define BMI_OUTPUT_VAR_NAME_COUNT 1

typedef struct _BMI_Model BMI_Model;

/* Model Control functions */
int BMI_Initialize (const char *, BMI_Model**);
int BMI_Update (BMI_Model *);
int BMI_Update_until (BMI_Model *, double);
int BMI_Finalize (BMI_Model *);
int BMI_Run_model (BMI_Model *);

/* Model information functions */
int BMI_Get_component_name (BMI_Model *, char *);
int BMI_Get_input_var_name_count (BMI_Model, int *);
int BMI_Get_output_var_name_count (BMI_Model, int *);
int BMI_Get_input_var_names (BMI_Model *, char **);
int BMI_Get_output_var_names (BMI_Model *, char **);

/* Variable information functions */
int BMI_Get_var_type (BMI_Model *, const char *, BMI_Var_type *);
int BMI_Get_var_units (BMI_Model *, const char *, char *);
int BMI_Get_var_rank (BMI_Model *, const char *, int *);
int BMI_Get_current_time (BMI_Model *, double *);
int BMI_Get_start_time (BMI_Model *, double *);
int BMI_Get_end_time (BMI_Model *, double *);
int BMI_Get_time_units (BMI_Model *, char *);
int BMI_Get_time_step (BMI_Model *, double *);

/* Variable getter and setter functions */
int BMI_Get_double (BMI_Model *, const char *, double *);
int BMI_Get_double_ptr (BMI_Model *, const char *, double **);
int BMI_Get_double_at_indices (BMI_Model *, const char *, double *, int *, int);

int BMI_Set_double (BMI_Model *, const char *, double *);
int BMI_Set_double_ptr (BMI_Model *, const char *, double **);
int BMI_Set_double_at_indices (BMI_Model *, const char *, int *, int, double *);

/* Grid information functions */
int BMI_Get_grid_shape (BMI_Model *, const char *, int *);
int BMI_Get_grid_spacing (BMI_Model *, const char *, double *);
int BMI_Get_grid_origin (BMI_Model *, const char *, double *);

int BMI_Get_grid_x (BMI_Model *, const char *, double *);
int BMI_Get_grid_y (BMI_Model *, const char *, double *);
int BMI_Get_grid_z (BMI_Model *, const char *, double *);

int BMI_Get_grid_cell_count (BMI_Model *, const char *, int *);
int BMI_Get_grid_point_count (BMI_Model *, const char *, int *);
int BMI_Get_grid_vertex_count (BMI_Model *, const char *, int *);

int BMI_Get_grid_connectivity (BMI_Model *, const char *, int *);
int BMI_Get_grid_offset (BMI_Model *, const char *, int *);






// Assumes arrays start at 0, and have contiguous elements (unit stride).
double BMI_Get_0d_double (BMI_Model *, const char *);
double *BMI_Get_1d_double (BMI_Model *, const char *, int [1]);
double *BMI_Get_2d_double (BMI_Model *, const char *, int [2]);
double *BMI_Get_3d_double (BMI_Model *, const char *, int [3]);
double *BMI_Get_1d_double_at_indices (BMI_Model *, const char *, int *,
    int , double *);
double *BMI_Get_2d_double_at_indices (BMI_Model *, const char *, int *, int);
// A more general getter
//double *BMI_Get_double (BMI_Model *, const char *, int *, int **);

void BMI_Set_0d_double (BMI_Model *, const char *, double);
void BMI_Set_1d_double (BMI_Model *, const char *, const double *);
void BMI_Set_2d_double (BMI_Model *, const char *, const double *);
void BMI_Set_3d_double (BMI_Model *, const char *, const double *);
void BMI_Set_2d_double_at_indices (BMI_Model *, const char *, int *,
    const double *, int);

int BMI_Get_0d_int (BMI_Model *, const char *);
int *BMI_Get_1d_int (BMI_Model *, const char *, int [1]);
int *BMI_Get_2d_int (BMI_Model *, const char *, int [2]);
int *BMI_Get_3d_int (BMI_Model *, const char *, int [3]);
int *BMI_Get_2d_int_at_indices (BMI_Model *, const char *, int *, int);

void BMI_Set_0d_int (BMI_Model *, const char *, int);
void BMI_Set_1d_int (BMI_Model *, const char *, const int *);
void BMI_Set_2d_int (BMI_Model *, const char *, const int *);
void BMI_Set_3d_int (BMI_Model *, const char *, const int *);
void BMI_Set_2d_int_at_indices (BMI_Model *, const char *, int *,
    const int *, int);

/*
int *BMI_Get_grid_dimen (BMI_Model *, const char *, int *);
double *BMI_Get_grid_res (BMI_Model *, const char *, int *);
double *BMI_Get_grid_corner (BMI_Model *, const char *, int *);
 */

/*
  IElementSet get_Element_Set (BMI_Model *handle);
  IValueSet get_Value_Set (BMI_Model *handle, char *long_var_name, ITimeStamp);
*/

// Since these are just wrappers for other BMI functions, I don't
// think they should be included in the interface definition. They
// could be CMI functions.
int BMI_Is_scalar (BMI_Model *, const char *);
int BMI_Is_vector (BMI_Model *, const char *);
int BMI_Is_grid (BMI_Model *, const char *);
int BMI_Has_var (BMI_Model *, const char *);

// However, something that indicates if the grid is raster, or
// uniform rectilinear would be needed.
int BMI_Is_raster_grid (BMI_Model *, const char *);

#if defined(__cplusplus)
}
#endif

#endif
