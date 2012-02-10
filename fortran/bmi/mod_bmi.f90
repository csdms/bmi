! This module defines the Basic Model interface in Fortran. There are more interface
! functions available in the BMI guidlines. Use them as per your model's
! needs.

module mod_bmi
   interface
        subroutine ltrans_initialize(file)
            character(len=30), intent(in) :: file
        end subroutine ltrans_initialize
        
        subroutine ltrans_update(dt)
            double precision, intent(in) :: dt
        end subroutine ltrans_update
                
        subroutine ltrans_finalize()
        end subroutine ltrans_finalize
        
        subroutine get_model_name(model_name)
            character(len=30), intent(out) :: model_name
        end subroutine get_model_name    
        
        subroutine get_time_units()
        end subroutine get_time_units
        
        subroutine get_start_time()
        end subroutine get_start_time
        
        subroutine get_current_time()
        end subroutine get_current_time
        
        subroutine get_end_time()
        end subroutine get_end_time
        
        subroutine get_var_type(long_var_name, value_type)
            character(len=*), intent(in) :: long_var_name
            character(len=*), intent(out) :: value_type
        end subroutine get_var_type
        
        subroutine get_var_units(long_var_name, value_units)
            character(len=*), intent(in) :: long_var_name
            character(len=*), intent(out) :: value_units
        end subroutine get_var_units
        
        subroutine get_var_rank(long_var_name, value_rank)
            character(len=*), intent(in) :: long_var_name
            character(len=*), intent(out) :: value_rank
        end subroutine get_var_rank
        
        subroutine get_var_name(long_var_name, value_name)
            character(len=*), intent(in) :: long_var_name
            character(len=*), intent(out) :: value_name
        end subroutine get_var_name
        
        subroutine roms_get_1D_double(long_var_name, return_value)
            character(len=*), intent(in) :: long_var_name
            double precision, pointer :: return_value(:)
        end subroutine roms_get_1D_double
        
        subroutine set_1D_double(long_var_name, value)
            character(len=*), intent(in) :: long_var_name
            double precision, pointer :: value(:)
        end subroutine set_1D_double
        
        subroutine roms_get_2D_double(long_var_name, return_value)
            character(len=*), intent(in) :: long_var_name
            double precision, pointer :: return_value(:,:)
        end subroutine roms_get_2D_double
        
        subroutine set_2D_double(long_var_name, set_value)
            character(len=*), intent(in) :: long_var_name
            double precision, pointer :: set_value(:, :)
        end subroutine set_2D_double
        
        subroutine roms_get_3D_Double(long_var_name, return_value)
            character(len=*), intent(in) :: long_var_name
            double precision, pointer :: return_value(:,:,:)
        end subroutine roms_get_3D_Double
        
        subroutine set_3D_Double(long_var_name, set_value)
            character(len=*), intent(in) :: long_var_name
            double precision, pointer :: set_value(:,:,:)
        end subroutine set_3D_Double
        
        subroutine roms_get_4D_Double(long_var_name, return_value)
            character(len=*), intent(in) :: long_var_name
            double precision, pointer :: return_value(:,:,:,:)
        end subroutine roms_get_4D_Double

        subroutine set_4D_Double(long_var_name, set_value)
            character(len=*), intent(in) :: long_var_name
            double precision, pointer :: set_value(:,:,:,:)
        end subroutine set_4D_Double
    end interface   
end module mod_bmi
