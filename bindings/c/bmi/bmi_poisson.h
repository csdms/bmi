#ifndef BMI_POISSON_INCLUDED
#define BMI_POISSON_INCLUDED

#if defined(__cplusplus)
extern "C" {
#endif

#define BMI_POISSON_INPUT_VAR_NAME_COUNT 1
#define BMI_POISSON_OUTPUT_VAR_NAME_COUNT 1

typedef struct _BMI_Model BMI_Model;

/* Model Control functions */
int BMI_POISSON_Initialize (const char *, BMI_Model**);
int BMI_POISSON_Update (BMI_Model *);
int BMI_POISSON_Update_until (BMI_Model *, double);
int BMI_POISSON_Finalize (BMI_Model *);
int BMI_POISSON_Run_model (BMI_Model *);

/* Model information functions */
int BMI_POISSON_Get_component_name (BMI_Model *, char *);
int BMI_POISSON_Get_input_var_name_count (BMI_Model, int *);
int BMI_POISSON_Get_output_var_name_count (BMI_Model, int *);
int BMI_POISSON_Get_input_var_names (BMI_Model *, char **);
int BMI_POISSON_Get_output_var_names (BMI_Model *, char **);

/* Variable information functions */
int BMI_POISSON_Get_var_type (BMI_Model *, const char *, BMI_Var_type *);
int BMI_POISSON_Get_var_units (BMI_Model *, const char *, char *);
int BMI_POISSON_Get_var_rank (BMI_Model *, const char *, int *);
int BMI_POISSON_Get_current_time (BMI_Model *, double *);
int BMI_POISSON_Get_start_time (BMI_Model *, double *);
int BMI_POISSON_Get_end_time (BMI_Model *, double *);
int BMI_POISSON_Get_time_units (BMI_Model *, char *);
int BMI_POISSON_Get_time_step (BMI_Model *, double *);

/* Variable getter and setter functions */
int BMI_POISSON_Get_value (BMI_Model *, const char *, void *);
int BMI_POISSON_Get_value_ptr (BMI_Model *, const char *, void **);
int BMI_POISSON_Get_value_at_indices (BMI_Model *, const char *, void *, int *,
    int);

int BMI_POISSON_Set_value (BMI_Model *, const char *, void *);
int BMI_POISSON_Set_value_ptr (BMI_Model *, const char *, void **);
int BMI_POISSON_Set_value_at_indices (BMI_Model *, const char *, int *, int,
    void *);

/* Grid information functions */
int BMI_POISSON_Get_grid_shape (BMI_Model *, const char *, int *);
int BMI_POISSON_Get_grid_spacing (BMI_Model *, const char *, double *);
int BMI_POISSON_Get_grid_origin (BMI_Model *, const char *, double *);

int BMI_POISSON_Get_grid_x (BMI_Model *, const char *, double *);
int BMI_POISSON_Get_grid_y (BMI_Model *, const char *, double *);
int BMI_POISSON_Get_grid_z (BMI_Model *, const char *, double *);

int BMI_POISSON_Get_grid_cell_count (BMI_Model *, const char *, int *);
int BMI_POISSON_Get_grid_point_count (BMI_Model *, const char *, int *);
int BMI_POISSON_Get_grid_vertex_count (BMI_Model *, const char *, int *);

int BMI_POISSON_Get_grid_connectivity (BMI_Model *, const char *, int *);
int BMI_POISSON_Get_grid_offset (BMI_Model *, const char *, int *);

#if defined(__cplusplus)
}
#endif

#endif
