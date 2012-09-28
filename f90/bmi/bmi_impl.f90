      module bmif
      use, intrinsic :: iso_c_binding, only: c_ptr, c_loc, c_f_pointer
      implicit none

      integer, parameter :: BMI_VAR_TYPE_UNKNOWN = 0
      integer, parameter :: BMI_VAR_TYPE_CHAR = 1
      integer, parameter :: BMI_VAR_TYPE_UNSIGNED_CHAR = 2
      integer, parameter :: BMI_VAR_TYPE_INT = 3
      integer, parameter :: BMI_VAR_TYPE_LONG = 4
      integer, parameter :: BMI_VAR_TYPE_UNSIGNED_INT = 5
      integer, parameter :: BMI_VAR_TYPE_UNSIGNED_LONG = 6
      integer, parameter :: BMI_VAR_TYPE_FLOAT = 7
      integer, parameter :: BMI_VAR_TYPE_DOUBLE = 8
      integer, parameter :: BMI_VAR_TYPE_NUMBER = 9

      integer, parameter :: BMI_GRID_TYPE_UNKNOWN = 0
      integer, parameter :: BMI_GRID_TYPE_UNIFORM = 1
      integer, parameter :: BMI_GRID_TYPE_RECTILINEAR = 2
      integer, parameter :: BMI_GRID_TYPE_STRUCTURED = 3
      integer, parameter :: BMI_GRID_TYPE_UNSTRUCTURED = 4
      integer, parameter :: BMI_GRID_TYPE_NUMBER = 5

      type :: BMI_Model
        private
          real :: dt
          real :: t
          real :: t_end

          integer :: n_x
          integer :: n_y

          real :: dx
          real :: dy

          real, pointer :: z(:,:)
          real, pointer :: z_temp(:,:)
      end type BMI_Model

      integer, parameter :: component_name_length = 22
      character (len=component_name_length), target :: &
        component_name = "Fortran test component"

      ! start exchange item list
      integer, parameter :: input_item_count = 1
      integer, parameter :: output_item_count = 1
      integer, parameter :: item_name_length = 22
      character (len=item_name_length), target, &
        dimension (input_item_count) :: &
        input_items = (/'surface_elevation    '/)

      character (len=item_name_length), target, &
        dimension (output_item_count) :: &
        output_items = (/'surface_elevation   '/)
      ! end exchange item list

      contains
          subroutine BMI_Initialize (self, config_file)
            type (BMI_Model), intent (out) :: self
            character (len=*), intent (in) :: config_file
            ! end declaration section

            if (len (config_file)>0) then
              open (15, file=config_file)
              read (15, *) self%dt, self%t_end, self%n_x, self%n_y
              close (15)
            else
              self%dt = 1.
              self%t_end = 10000.
              self%n_x = 10
              self%n_y = 20
            end if

            self%t = 0.
            self%dx = 1.
            self%dy = 1.

            allocate (self%z(self%n_x, self%n_y))
            allocate (self%z_temp(self%n_x, self%n_y))

            self%z = 0.
            self%z_temp = 0.

            call set_bc (self%z)
            call set_bc (self%z_temp)

          end subroutine BMI_Initialize

          subroutine set_bc (z)
            real, dimension (:,:), intent (out) :: z

            integer :: i
            real :: top_x

            top_x = size(z, 1)-1
            
            do i = 0, size(z, 1)-1
              z(i+1,1) = top_x**2*.25 - (i-top_x*.5)**2
            end do

          end subroutine set_bc


          subroutine BMI_Finalize (self)
            implicit none
            type (BMI_Model), intent (inout) :: self
            ! end declaration section

            deallocate (self%z)
            deallocate (self%z_temp)
          end subroutine BMI_Finalize

          subroutine BMI_Update (self)
            implicit none
            type (BMI_Model), intent (inout) :: self
            ! end declaration section

            real, parameter :: rho = 0.
            real :: dx2
            real :: dy2
            real :: dx2_dy2_rho
            real :: coef
            integer :: i, j

            dx2 = self%dx**2
            dy2 = self%dy**2
            dx2_dy2_rho = dx2 * dy2 * rho
            coef = self%dt / (2. * (dx2 + dy2))

            do j = 2, self%n_y-1
              do i = 2, self%n_x-1
                self%z_temp(i,j) = &
                  coef * (dx2 * (self%z(i-1,j) + self%z(i+1,j)) + &
                          dy2 * (self%z(i,j-1) + self%z(i,j+1)) - &
                          dx2_dy2_rho)
              end do
            end do

            self%t = self%t + self%dt

            self%z = self%z_temp
          end subroutine BMI_Update

          subroutine BMI_Update_until (self, t)
            implicit none
            type (BMI_Model), intent (inout) :: self
            real, intent (in) :: t
            ! end declaration section

            integer :: n
            integer :: n_steps
            real :: saved_dt

            n_steps = (t-self%t)/self%dt

            do n = 1, n_steps
              call BMI_Update (self)
            end do

            if (t>self%t) then
              saved_dt = self%dt
              self%dt = t - self%t

              call BMI_Update (self)

              self%dt = saved_dt
            endif

          end subroutine BMI_Update_until

          subroutine BMI_Get_start_time (self, start)
            implicit none
            type (BMI_Model), intent (inout) :: self
            real, intent (out) :: start
            ! end declaration BMI_Get_start_time

            start = 0.
          end subroutine BMI_Get_start_time

          subroutine BMI_Get_end_time (self, end)
            implicit none
            type (BMI_Model), intent (inout) :: self
            real, intent (out) :: end
            ! end declaration BMI_Get_end_time

            end = self%t_end
          end subroutine BMI_Get_end_time

          subroutine BMI_Get_current_time (self, time)
            implicit none
            type (BMI_Model), intent (inout) :: self
            real, intent (out) :: time
            ! end declaration BMI_Get_current_time

            time = self%t
          end subroutine BMI_Get_current_time

          subroutine BMI_Get_time_step (self, dt)
            implicit none
            type (BMI_Model), intent (inout) :: self
            real, intent (out) :: dt
            ! end declaration section

            dt = self%dt
          end subroutine BMI_Get_time_step

          subroutine BMI_Get_time_units (self, units)
            implicit none
            type (BMI_Model), intent (inout) :: self
            character (len=*), intent (out) :: units
            ! end declaration section

            units = "-"
          end subroutine BMI_Get_time_units

          subroutine BMI_Get_var_type (self, var_name, type)
            implicit none
            type (BMI_Model), intent (inout) :: self
            character (len=*), intent (in) :: var_name
            integer, intent (out) :: type
            ! end declaration section

            type = BMI_VAR_TYPE_DOUBLE
          end subroutine BMI_Get_var_type

          subroutine BMI_Get_var_units (self, var_name, units)
            implicit none
            type (BMI_Model), intent (inout) :: self
            character (len=*), intent (in) :: var_name
            character (len=*), intent (out) :: units
            ! end declaration section

            units = "meter"
          end subroutine BMI_Get_var_units

          subroutine BMI_Get_var_rank (self, var_name, rank)
            implicit none
            type (BMI_Model), intent (inout) :: self
            character (len=*), intent (in) :: var_name
            integer, intent (out) :: rank
            ! end declaration section

            rank = 2
          end subroutine BMI_Get_var_rank

          subroutine BMI_Get_grid_type (self, var_name, type)
            implicit none
            type (BMI_Model), intent (inout) :: self
            character (len=*), intent (in) :: var_name
            integer, intent (out) :: type
            ! end declaration section

            type = BMI_GRID_TYPE_UNIFORM
          end subroutine BMI_Get_grid_type

          subroutine BMI_Get_grid_shape (self, var_name, shape)
            implicit none
            type (BMI_Model), intent (inout) :: self
            character (len=*), intent (in) :: var_name
            integer, dimension (:), intent (out) :: shape
            ! end declaration section

            shape(1) = self%n_x
            shape(2) = self%n_y
          end subroutine BMI_Get_grid_shape

          subroutine BMI_Get_grid_spacing (self, var_name, spacing)
            implicit none
            type (BMI_Model), intent (inout) :: self
            character (len=*), intent (in) :: var_name
            real, dimension (:), intent (out) :: spacing
            ! end declaration section

            spacing(1) = self%dx
            spacing(2) = self%dy
          end subroutine BMI_Get_grid_spacing

          subroutine BMI_Get_grid_origin (self, var_name, origin)
            implicit none
            type (BMI_Model), intent (inout) :: self
            character (len=*), intent (in) :: var_name
            real, dimension (:), intent (out) :: origin
            ! end declaration section

            origin(1) = 0.
            origin(2) = 0.
          end subroutine BMI_Get_grid_origin

          subroutine BMI_Get_double (self, var_name, dest)
            implicit none
            type (BMI_Model), intent (in) :: self
            character (len=*), intent (in) :: var_name
            real, pointer, intent (inout) :: dest(:)
            ! end declaration section

            real, pointer :: src_as_1d (:)
            type (c_ptr) :: src

            select case (var_name)
              case ('surface_elevation')
                src = c_loc (self%z(1,1))
            end select

            if (associated (dest)) then
              call C_F_POINTER (src, src_as_1d, [self%n_x*self%n_y])
              dest = src_as_1d
            else
              call C_F_POINTER (src, dest, [self%n_x*self%n_y])
            endif

          end subroutine BMI_Get_double

          subroutine BMI_Get_double_copy (self, var_name, dest)
            implicit none
            type (BMI_Model), intent (in) :: self
            character (len=*), intent (in) :: var_name
            real, intent (out) :: dest (*)
            ! end declaration section

            select case (var_name)
              case ('surface_elevation')
                call copy_array (dest, self%z, self%n_x * self%n_y)
            end select

          end subroutine BMI_Get_double_copy

          subroutine BMI_Get_double_at_indices (self, var_name, dest, inds)
            implicit none
            type (BMI_Model), intent (in) :: self
            character (len=*), intent (in) :: var_name
            real, pointer, intent (inout) :: dest(:)
            integer, intent (in) :: inds(:)
            ! end declaration section

            real, pointer :: src_as_1d (:)
            type (c_ptr) :: src
            integer :: i

            select case (var_name)
              case ('surface_elevation')
                src = c_loc (self%z(1,1))
            end select

            call C_F_POINTER (src, src_as_1d, [self%n_x*self%n_y])

            do i = 1, size (inds)
              dest(i) = src_as_1d(inds(i))
            end do

          end subroutine BMI_Get_double_at_indices

          subroutine BMI_Set_double (self, var_name, src)
            implicit none
            type (BMI_Model), intent (inout) :: self
            character (len=*), intent (in) :: var_name
            real, intent (in) :: src (*)
            ! end declaration section

            call copy_array (self%z, src, self%n_x * self%n_y)

          end subroutine BMI_Set_double

          subroutine BMI_Set_double_at_indices (self, var_name, inds, src)
            implicit none
            type (BMI_Model), intent (inout) :: self
            character (len=*), intent (in) :: var_name
            integer, intent (in) :: inds(:)
            real, intent (in) :: src (*)
            ! end declaration section

            real, pointer :: dest_as_1d (:)
            type (c_ptr) :: dest
            integer :: i

            select case (var_name)
              case ('surface_elevation')
                dest = c_loc (self%z(1,1))
            end select

            call C_F_POINTER (dest, dest_as_1d, [self%n_x*self%n_y])

            do i = 1, size (inds)
              dest_as_1d(inds(i)) = src(i)
            end do

          end subroutine BMI_Set_double_at_indices

          subroutine copy_array (dest, src, n)
            real, intent (out) :: dest(n)
            real, intent (in) :: src(n)
            integer, intent (in) :: n
            dest = src
          end subroutine copy_array

          subroutine BMI_Get_input_var_names (self, names)
            implicit none
            type (BMI_Model), intent (in) :: self
            character (*), pointer, intent (out) :: names(:)
            ! end declaration section

            names => input_items
          end subroutine BMI_Get_input_var_names

          subroutine BMI_Get_output_var_names (self, names)
            implicit none
            type (BMI_Model), intent (in) :: self
            character (*), pointer, intent (out) :: names(:)
            ! end declaration section

            names => output_items
          end subroutine BMI_Get_output_var_names

          subroutine BMI_Get_component_name (self, name)
            implicit none
            type (BMI_Model), intent (in) :: self
            character (len=*), pointer, intent (out) :: name
            ! end declaration section

            name => component_name
          end subroutine BMI_Get_component_name
      end module

