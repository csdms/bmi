#ifndef BMI_INCLUDED
#define BMI_INCLUDED

#include <string>

namespace CMI {

  typedef enum {
    STATUS_CREATED,
    STATUS_INITIALIZING,
    STATUS_INITIALIZED,
    STATUS_UPDATING,
    STATUS_UPDATED,
    STATUS_FINALIZING,
    STATUS_FINALIZED
  } CMI_Component_status;

};

namespace BMI {

  typedef enum {
    GRID_TYPE_UNKNOWN = -1,
    GRID_TYPE_UNIFORM,
    GRID_TYPE_RECTILINEAR,
    GRID_TYPE_STRUCTURED,
    GRID_TYPE_UNSTRUCTURED
  } Grid_type;

  class Model {
    private:
      double dt;
      double t;
      double t_end;

      int n_x;
      int n_y;

      double dx;
      double dy;
      double **z;

      double **temp_z;

    public:
      // BMI declarations
      virtual void initialize (std::string);
      void update ();
      void update_until (double);
      void finalize ();
      void run_model ();

      std::string get_component_name ();
      const char **get_input_var_names ();
      const char **get_output_var_names ();

      std::string get_var_type (std::string);
      std::string get_var_units (std::string);
      int get_var_rank (std::string);

      double get_current_time ();
      double get_start_time ();
      double get_end_time ();
      double get_time_step ();
      std::string get_time_units ();

      double *get_double (std::string, double *);
      double *get_double_at_indices (std::string, double *, int *, int);

      void *get_value (std::string, void *);
      void *get_value_ptr (std::string);
      void *get_value_at_indices (std::string, void *, int *, int);

      void set_double (std::string, double *);
      void set_double_at_indices (std::string, int *, int, double *);

      Grid_type get_grid_type (std::string long_var_name);

      void get_grid_shape (std::string, int *);
      void get_grid_spacing (std::string, double *);
      void get_grid_origin (std::string, double *);

      double * get_grid_x (std::string, int&);
      double * get_grid_y (std::string, int&);
      double * get_grid_z (std::string, int&);

      int * get_grid_connectivity (std::string, int &);
      int * get_grid_offset (std::string, int &);
  };
};

#endif

