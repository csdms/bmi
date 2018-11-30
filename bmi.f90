module bmif

  implicit none

  integer, parameter :: BMI_MAX_COMPONENT_NAME = 2048
  integer, parameter :: BMI_MAX_VAR_NAME = 2048
  integer, parameter :: BMI_MAX_TYPE_NAME = 2048
  integer, parameter :: BMI_MAX_UNITS_NAME = 2048

  integer, parameter :: BMI_FAILURE = 1
  integer, parameter :: BMI_SUCCESS = 0

  type, abstract :: bmi
     contains
       procedure (bmif_get_component_name), deferred :: get_component_name
       procedure (bmif_get_input_var_names), deferred :: get_input_var_names
       procedure (bmif_get_output_var_names), deferred :: get_output_var_names
       procedure (bmif_initialize), deferred :: initialize
       procedure (bmif_finalize), deferred :: finalize
       procedure (bmif_get_start_time), deferred :: get_start_time
       procedure (bmif_get_end_time), deferred :: get_end_time
       procedure (bmif_get_current_time), deferred :: get_current_time
       procedure (bmif_get_time_step), deferred :: get_time_step
       procedure (bmif_get_time_units), deferred :: get_time_units
       procedure (bmif_update), deferred :: update
       procedure (bmif_update_frac), deferred :: update_frac
       procedure (bmif_update_until), deferred :: update_until
       procedure (bmif_get_var_grid), deferred :: get_var_grid
       procedure (bmif_get_grid_type), deferred :: get_grid_type
       procedure (bmif_get_grid_rank), deferred :: get_grid_rank
       procedure (bmif_get_grid_shape), deferred :: get_grid_shape
       procedure (bmif_get_grid_size), deferred :: get_grid_size
       procedure (bmif_get_grid_spacing), deferred :: get_grid_spacing
       procedure (bmif_get_grid_origin), deferred :: get_grid_origin
       procedure (bmif_get_grid_x), deferred :: get_grid_x
       procedure (bmif_get_grid_y), deferred :: get_grid_y
       procedure (bmif_get_grid_z), deferred :: get_grid_z
       procedure (bmif_get_grid_connectivity), deferred :: get_grid_connectivity
       procedure (bmif_get_grid_offset), deferred :: get_grid_offset
       procedure (bmif_get_var_type), deferred :: get_var_type
       procedure (bmif_get_var_units), deferred :: get_var_units
       procedure (bmif_get_var_itemsize), deferred :: get_var_itemsize
       procedure (bmif_get_var_nbytes), deferred :: get_var_nbytes
       procedure (bmif_get_value_int), deferred :: get_value_int
       procedure (bmif_get_value_float), deferred :: get_value_float
       procedure (bmif_get_value_double), deferred :: get_value_double
       procedure (bmif_get_value_ptr_int), deferred :: get_value_ptr_int
       procedure (bmif_get_value_ptr_float), deferred :: get_value_ptr_float
       procedure (bmif_get_value_ptr_double), deferred :: get_value_ptr_double
       procedure (bmif_get_value_at_indices_int), deferred :: get_value_at_indices_int
       procedure (bmif_get_value_at_indices_float), deferred :: get_value_at_indices_float
       procedure (bmif_get_value_at_indices_double), deferred :: get_value_at_indices_double
       procedure (bmif_set_value_int), deferred :: set_value_int
       procedure (bmif_set_value_float), deferred :: set_value_float
       procedure (bmif_set_value_double), deferred :: set_value_double
       procedure (bmif_set_value_at_indices_int), deferred :: set_value_at_indices_int
       procedure (bmif_set_value_at_indices_float), deferred :: set_value_at_indices_float
       procedure (bmif_set_value_at_indices_double), deferred :: set_value_at_indices_double
  end type bmi

  abstract interface

     function bmif_get_component_name(this, name) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), pointer, intent(out) :: name
       integer :: bmi_status
     end function bmif_get_component_name

     function bmif_get_input_var_names(this, names) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), pointer, intent(out) :: names(:)
       integer :: bmi_status
     end function bmif_get_input_var_names

     function bmif_get_output_var_names(this, names) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), pointer, intent(out) :: names(:)
       integer :: bmi_status
     end function bmif_get_output_var_names

     function bmif_initialize(this, config_file) result(bmi_status)
       import :: bmi
       class (bmi), intent(out) :: this
       character (len=*), intent(in) :: config_file
       integer :: bmi_status
     end function bmif_initialize

     function bmif_finalize(this) result(bmi_status)
       import :: bmi
       class (bmi), intent(inout) :: this
       integer :: bmi_status
     end function bmif_finalize

     function bmif_get_start_time(this, time) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       double precision, intent(out) :: time
       integer :: bmi_status
     end function bmif_get_start_time

     function bmif_get_end_time(this, time) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       double precision, intent(out) :: time
       integer :: bmi_status
     end function bmif_get_end_time

     function bmif_get_current_time(this, time) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       double precision, intent(out) :: time
       integer :: bmi_status
     end function bmif_get_current_time

     function bmif_get_time_step(this, time_step) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       double precision, intent(out) :: time_step
       integer :: bmi_status
     end function bmif_get_time_step

     function bmif_get_time_units(this, time_units) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), intent(out) :: time_units
       integer :: bmi_status
     end function bmif_get_time_units

     function bmif_update(this) result(bmi_status)
       import :: bmi
       class (bmi), intent(inout) :: this
       integer :: bmi_status
     end function bmif_update

     function bmif_update_frac(this, time_frac) result(bmi_status)
       import :: bmi
       class (bmi), intent(inout) :: this
       double precision, intent(in) :: time_frac
       integer :: bmi_status
     end function bmif_update_frac

     function bmif_update_until(this, time) result(bmi_status)
       import :: bmi
       class (bmi), intent(inout) :: this
       double precision, intent(in) :: time
       integer :: bmi_status
     end function bmif_update_until

     function bmif_get_var_grid(this, var_name, grid_id) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), intent(in) :: var_name
       integer, intent(out) :: grid_id
       integer :: bmi_status
     end function bmif_get_var_grid

     function bmif_get_grid_type(this, grid_id, grid_type) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       integer, intent(in) :: grid_id
       character (len=*), intent(out) :: grid_type
       integer :: bmi_status
     end function bmif_get_grid_type

     function bmif_get_grid_rank(this, grid_id, grid_rank) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       integer, intent(in) :: grid_id
       integer, intent(out) :: grid_rank
       integer :: bmi_status
     end function bmif_get_grid_rank

     function bmif_get_grid_shape(this, grid_id, grid_shape) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       integer, intent(in) :: grid_id
       integer, dimension(:), intent(out) :: grid_shape
       integer :: bmi_status
     end function bmif_get_grid_shape

     function bmif_get_grid_size(this, grid_id, grid_size) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       integer, intent(in) :: grid_id
       integer, intent(out) :: grid_size
       integer :: bmi_status
     end function bmif_get_grid_size

     function bmif_get_grid_spacing(this, grid_id, grid_spacing) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       integer, intent(in) :: grid_id
       double precision, dimension(:), intent(out) :: grid_spacing
       integer :: bmi_status
     end function bmif_get_grid_spacing

     function bmif_get_grid_origin(this, grid_id, grid_origin) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       integer, intent(in) :: grid_id
       double precision, dimension(:), intent(out) :: grid_origin
       integer :: bmi_status
     end function bmif_get_grid_origin

     function bmif_get_grid_x(this, grid_id, grid_x) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       integer, intent(in) :: grid_id
       double precision, dimension(:), intent(out) :: grid_x
       integer :: bmi_status
     end function bmif_get_grid_x

     function bmif_get_grid_y(this, grid_id, grid_y) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       integer, intent(in) :: grid_id
       double precision, dimension(:), intent(out) :: grid_y
       integer :: bmi_status
     end function bmif_get_grid_y

     function bmif_get_grid_z(this, grid_id, grid_z) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       integer, intent(in) :: grid_id
       double precision, dimension(:), intent(out) :: grid_z
       integer :: bmi_status
     end function bmif_get_grid_z

     function bmif_get_grid_connectivity(this, grid_id, grid_conn) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       integer, intent(in) :: grid_id
       integer, dimension(:), intent(out) :: grid_conn
       integer :: bmi_status
     end function bmif_get_grid_connectivity

     function bmif_get_grid_offset(this, grid_id, grid_offset) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       integer, intent(in) :: grid_id
       integer, dimension(:), intent(out) :: grid_offset
       integer :: bmi_status
     end function bmif_get_grid_offset

     function bmif_get_var_type(this, var_name, var_type) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), intent(in) :: var_name
       character (len=*), intent(out) :: var_type
       integer :: bmi_status
     end function bmif_get_var_type

     function bmif_get_var_units(this, var_name, var_units) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), intent(in) :: var_name
       character (len=*), intent(out) :: var_units
       integer :: bmi_status
     end function bmif_get_var_units

     function bmif_get_var_itemsize(this, var_name, var_size) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), intent(in) :: var_name
       integer, intent(out) :: var_size
       integer :: bmi_status
     end function bmif_get_var_itemsize

     function bmif_get_var_nbytes(this, var_name, var_nbytes) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), intent(in) :: var_name
       integer, intent(out) :: var_nbytes
       integer :: bmi_status
     end function bmif_get_var_nbytes

     function bmif_get_value_int(this, var_name, dest) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), intent(in) :: var_name
       integer, intent(inout) :: dest(:)
       integer :: bmi_status
     end function bmif_get_value_int

     function bmif_get_value_float(this, var_name, dest) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), intent(in) :: var_name
       real, intent(inout) :: dest(:)
       integer :: bmi_status
     end function bmif_get_value_float

     function bmif_get_value_double(this, var_name, dest) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), intent(in) :: var_name
       double precision, intent(inout) :: dest(:)
       integer :: bmi_status
     end function bmif_get_value_double

     function bmif_get_value_ptr_int(this, var_name, dest) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), intent(in) :: var_name
       integer, pointer, intent(inout) :: dest(:)
       integer :: bmi_status
     end function bmif_get_value_ptr_int

     function bmif_get_value_ptr_float(this, var_name, dest) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), intent(in) :: var_name
       real, pointer, intent(inout) :: dest(:)
       integer :: bmi_status
     end function bmif_get_value_ptr_float

     function bmif_get_value_ptr_double(this, var_name, dest) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), intent(in) :: var_name
       double precision, pointer, intent(inout) :: dest(:)
       integer :: bmi_status
     end function bmif_get_value_ptr_double

     function bmif_get_value_at_indices_int(this, var_name, dest, indices) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), intent(in) :: var_name
       integer, intent(inout) :: dest(:)
       integer, intent(in) :: indices(:)
       integer :: bmi_status
     end function bmif_get_value_at_indices_int

     function bmif_get_value_at_indices_float(this, var_name, dest, indices) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), intent(in) :: var_name
       real, intent(inout) :: dest(:)
       integer, intent(in) :: indices(:)
       integer :: bmi_status
     end function bmif_get_value_at_indices_float

     function bmif_get_value_at_indices_double(this, var_name, dest, indices) result(bmi_status)
       import :: bmi
       class (bmi), intent(in) :: this
       character (len=*), intent(in) :: var_name
       double precision, intent(inout) :: dest(:)
       integer, intent(in) :: indices(:)
       integer :: bmi_status
     end function bmif_get_value_at_indices_double

     function bmif_set_value_int(this, var_name, src) result(bmi_status)
       import :: bmi
       class (bmi), intent(inout) :: this
       character (len=*), intent(in) :: var_name
       integer, intent(in) :: src(:)
       integer :: bmi_status
     end function bmif_set_value_int

     function bmif_set_value_float(this, var_name, src) result(bmi_status)
       import :: bmi
       class (bmi), intent(inout) :: this
       character (len=*), intent(in) :: var_name
       real, intent(in) :: src(:)
       integer :: bmi_status
     end function bmif_set_value_float

     function bmif_set_value_double(this, var_name, src) result(bmi_status)
       import :: bmi
       class (bmi), intent(inout) :: this
       character (len=*), intent(in) :: var_name
       double precision, intent(in) :: src(:)
       integer :: bmi_status
     end function bmif_set_value_double

     function bmif_set_value_at_indices_int(this, var_name, indices, src) result(bmi_status)
       import :: bmi
       class (bmi), intent(inout) :: this
       character (len=*), intent(in) :: var_name
       integer, intent(in) :: indices(:)
       integer, intent(in) :: src(:)
       integer :: bmi_status
     end function bmif_set_value_at_indices_int

     function bmif_set_value_at_indices_float(this, var_name, indices, src) result(bmi_status)
       import :: bmi
       class (bmi), intent(inout) :: this
       character (len=*), intent(in) :: var_name
       integer, intent(in) :: indices(:)
       real, intent(in) :: src(:)
       integer :: bmi_status
     end function bmif_set_value_at_indices_float

     function bmif_set_value_at_indices_double(this, var_name, indices, src) result(bmi_status)
       import :: bmi
       class (bmi), intent(inout) :: this
       character (len=*), intent(in) :: var_name
       integer, intent(in) :: indices(:)
       double precision, intent(in) :: src(:)
       integer :: bmi_status
     end function bmif_set_value_at_indices_double

  end interface

end module bmif
