      program test
      use bmif
      implicit none

      type (BMI_Model) :: m
      integer :: rank
      integer, allocatable, dimension (:) :: shape
      real, allocatable, dimension (:) :: spacing
      real, allocatable, dimension (:) :: origin
      integer :: i
      real :: time
      character (len=22), pointer :: names(:)
      character (len=component_name_length), pointer :: name

      write (*,"(A)",advance="no") "Initializing..."
      call BMI_Initialize (m, "")
      write (*,*) "Done."

      write (*,"(A)") "Component info:"

      call BMI_Get_component_name (m, name)
      write (*,"(a30, a30)") "Component name: ", name

      call BMI_Get_start_time (m, time)
      write (*,"(A30, f8.2)") "Start time: ", time
      call BMI_Get_end_time (m, time)
      write (*,"(A30, f8.2)") "End time: ", time
      call BMI_Get_current_time (m, time)
      write (*,"(A30, f8.2)") "Current time: ", time

      call BMI_Get_var_rank (m, "surface_elevation", rank)
      write (*,"(A30, f8.2)") "Var rank: ", time

      allocate (shape (rank))
      call BMI_Get_grid_shape (m, "surface_elevation", shape)
      write (*,"(A30, i3, A, i3)") "Grid shape is: ", &
        shape(1), " x ", shape(2)

      allocate (spacing (rank))
      call BMI_Get_grid_spacing (m, "surface_elevation", spacing)
      write (*,"(A30, f8.3, A, f8.3)") "Grid spacing is: ", &
        spacing(1), " x ", spacing(2)

      allocate (origin (rank))
      call BMI_Get_grid_origin (m, "surface_elevation", origin)
      write (*,"(A30, f8.3, A, f8.3)") "Grid origin is: ", &
        origin(1), " x ", origin(2)

      write (*,"(A)") "Running..."
      do i = 1, 10
        write (*,"(A30, i3)") "Time step:", i
        call BMI_Update (m)
      end do
      write (*,"(A)") "Done."

      time = 1000.5
      write (*,"(a, f8.3, a, X)", advance="no") &
        "Running until ", time, "..."
      call BMI_Update_until (m, time)
      write (*,"(A)") "Done."

      call BMI_Get_current_time (m, time)
      write (*,"(A30, f8.3)") "Time:", time

      write (*,"(A)", advance="no") "Finalizing..."
      call BMI_Finalize (m)
      write (*,*) "Done"

      end program test

