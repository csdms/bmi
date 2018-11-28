#define BMI_SUCCESS (0)
#define BMI_FAILURE (1)

#define BMI_MAX_UNITS_NAME (2048)
#define BMI_MAX_COMPONENT_NAME (2048)
#define BMI_MAX_VAR_NAME (2048)

typedef struct {
  void * self;

  int (*initialize)(void *self, char *config_file);	            	
  int (*update)(void *self, double time_interval);	            	
  int (*finalize)(void *self);	            	
              
  int (*get_component_name)(void *self, char *name);
  int (*get_input_item_count)(void *self, int *count);
  int (*get_output_item_count)(void *self, int *count);
  int (*get_input_var_names)(void *self, char **names);
  int (*get_output_var_names)(void *self, char **names);

  int (*get_var_grid)(void *self, char *name, int *grid_id);
  int (*get_var_type)(void *self, char *name, char *type);
  int (*get_var_units)(void *self, char *name, char *units);
  int (*get_var_itemsize)(void *self, char *name, int *size);
  int (*get_var_nbytes)(void *self, char *name, int *nbytes);
  int (*get_var_location)(void *self, char *name, char *location);

  int (*get_current_time)(void *self, double *time);
  int (*get_start_time)(void *self, double *time);
  int (*get_end_time)(void *self, double *time);
  int (*get_time_units)(void *self, char *units);
  int (*get_time_step)(void *self, double *time_step);

  int (*get_value)(void *self, char *name, void *dest);
  int (*get_value_ptr)(void *self, char *name, void **values);
  int (*get_value_at_indices)(void *self, char *name, void *dest, int *inds, int count);

  int (*set_value)(void *self, char *name, void *values);
  int (*set_value_at_indices)(void *self, char *name, void *values, void *inds, int count);

  // Grid information
  int (*get_grid_rank)(void *self, int grid, int *rank);
  int (*get_grid_size)(void *self, int grid, int *size);
  int (*get_grid_type)(void *self, int grid, char *type);

  // Uniform rectilinear
  int (*get_grid_shape)(void *self, int grid, int *shape);
  int (*get_grid_spacing)(void *self, int grid, double *spacing);
  int (*get_grid_origin)(void *self, int grid, double *origin);

  // Non-uniform rectilinear, curvilinear
  int (*get_grid_x)(void *self, int grid, double *x);
  int (*get_grid_y)(void *self, int grid, double *y);
  int (*get_grid_z)(void *self, int grid, double *z);

  int (*get_grid_node_count)(void *self, int grid, int *count);
  int (*get_grid_edge_count)(void *self, int grid, int *count);
  int (*get_grid_face_count)(void *self, int grid, int *count);

  int (*get_grid_edge_nodes)(void *self, int grid, int *edge_nodes);
  int (*get_grid_face_edges)(void *self, int grid, int *face_edges);
  int (*get_grid_face_nodes)(void *self, int grid, int *face_nodes);
  int (*get_grid_nodes_per_face)(void *self, int grid, int *nodes_per_face);
} Bmi;
