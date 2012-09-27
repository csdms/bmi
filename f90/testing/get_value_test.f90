      program test
      use bmif
      implicit none

      type (BMI_Model) :: m
      integer :: rank
      integer, allocatable, dimension (:) :: shape
      real, allocatable, dimension (:) :: spacing
      real, allocatable, dimension (:) :: origin
      integer :: i, j
      real :: time
      character (len=22), pointer :: names(:)
      character (len=component_name_length), pointer :: name
      real, pointer, dimension(:) :: z

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

      call BMI_Get_double (m, "surface_elevation", z)

      write (*,"(A)") "Running..."
      do j = 1, 10
        call BMI_Update (m)

        write (*,*) "Values at time ", j
        write (*,*) "==================="
        do i = 1, shape(2)
          write (*,*) z(i*shape(1)-shape(1)+1:i*shape(1))
        end do

      end do
      write (*,"(A)") "Done."

      call BMI_Update_until (m, 1000.5)
      write (*,*) "Values at time ", 1000.5
      write (*,*) "==================="
      do i = 1, shape(2)
          write (*,*) z(i*shape(1)-shape(1)+1:i*shape(1))
      end do

      write (*,"(A)", advance="no") "Finalizing..."
      call BMI_Finalize (m)
      write (*,*) "Done"

      end program test

