! This defines the implementation of Basic Model Interface for LTRANS

subroutine ltrans_initialize(file)
    !<Add the required modules>
    implicit none
    character(len=30), intent(in) :: file
    print *, 'LTRANS_BMI> Begin Initialize'
    call bmi_ini_LTRANS()
end subroutine ltrans_initialize

subroutine ltrans_update(dt)
    !<Add the required modules>
    implicit none
    double precision, intent(in) :: dt
    call update()
    print *, 'Finished:', time_interval
end subroutine ltrans_update

subroutine ltrans_finalize()
    !<Add the required modules>
    implicit none
    call fin_LTRANS()
end subroutine ltrans_finalize
        
subroutine get_model_name(model_name)
    implicit none
    character(len=30), intent(out) :: model_name
    model_name = "LTRANS"
end subroutine get_model_name

subroutine get_var_type(long_var_name, value_type)
    character(len=*), intent(in) :: long_var_name
    character(len=*), intent(out) :: value_type
    character(len=100) :: req_val="type"
    print *, 'LTRANS_BMI> Fetching value type for the long variable name: ', trim(long_var_name)
    call get_value_definitions(trim(long_var_name), req_val, value_type)
end subroutine get_var_type

subroutine get_var_units(long_var_name, value_units)
    character(len=*), intent(in) :: long_var_name
    character(len=*), intent(out) :: value_units
    character(len=100) :: req_val="unit"    
    print *, 'LTRANS_BMI> Fetching value units for the long variable name: ', trim(long_var_name)
    call get_value_definitions(trim(long_var_name), req_val, value_units)
end subroutine get_var_units

subroutine get_var_rank(long_var_name, value_rank)
    character(len=*), intent(in) :: long_var_name
    character(len=*), intent(out) :: value_rank
    character(len=100) :: req_val="rank"    
    print *, 'LTRANS_BMI> Fetching value rank for the long variable name: ', trim(long_var_name)
    call get_value_definitions(trim(long_var_name), req_val, value_rank)
end subroutine get_var_rank

subroutine get_var_name(long_var_name, value_name)
    character(len=*), intent(in) :: long_var_name
    character(len=*), intent(out) :: value_name
    character(len=100) :: req_val="name"    
    print *, 'LTRANS_BMI> Fetching value name for the long variable name: ', trim(long_var_name)
    call get_value_definitions(trim(long_var_name), req_val, value_name)
end subroutine get_var_name

subroutine ltrans_get_1D_double(input_value, return_value)
    !<Add the required modules>
    implicit none
    character(len=*), intent(in) :: input_value
    double precision, pointer :: return_value(:)
    double precision, dimension(:), pointer :: ptr1, ptr2, ptr3, ptr4, ptr5
    print *, 'ltrans_BMI> Fetching value for the input parameter: ', trim(input_value)
    select case(trim(input_value) )
        case('Cs_r')
            return_value => SCALARS(1)%Cs_r(:)
        case default
        	print *, 'Error in fetching the value for the requested parameter'
    end select
end subroutine ltrans_get_1D_double

subroutine ltrans_set_1D_double(input_value, value)
    !<Add the required modules>
    implicit none
    character(len=*), intent(in) :: input_value
    double precision, pointer :: value(:)
    print *, 'Setting value for the input parameter: ', trim(input_value)
    select case( trim(input_value)  )
        case('Cs_r')
            ALLOCATE(CS(us))
            CS = value
        case default
            print *, 'Error in fetching the value for the requested parameter'
    end select
end subroutine ltrans_set_1D_double

subroutine ltrans_get_2D_double(input_value, return_value)
    !<Add the required modules>
    implicit none
    character(len=*) :: input_value
    double precision, pointer :: return_value(:,:)
    print *, 'ltrans_BMI> Fetching value for the input parameter: ', trim(input_value)
    select case( trim(input_value) )
        case('angler')
            return_value => GRID(1)%angler
        case default
            print *, 'Error in fetching the value for the requested parameter, returning -1'
            return_value = -1
    end select
end subroutine ltrans_get_2D_double

subroutine ltrans_set_2D_double(input_value, set_value)
    !<Add the required modules>
    implicit none
    character(len=*) :: input_value
    double precision, pointer :: set_value(:, :)
    print *, 'Setting value for the input parameter: ', trim(input_value)
    select case( trim(input_value) )
        case('angler')
            cmi_angle = set_value
        case default
            print *, 'Error in fetching the value for the requested parameter'
    end select
end subroutine ltrans_set_2D_double

subroutine ltrans_get_3D_Double(input_value, return_value)
    !<Add the required modules>
    implicit none
    character(len=*) :: input_value
    double precision, pointer :: return_value(:,:,:)
    print *, 'ltrans_BMI> Fetching value for the input parameter: ', trim(input_value)
    select case( trim(input_value) )
        case('zeta')
            return_value => OCEAN(1)%zeta
        case default
            print *, 'Error in fetching the value for the requested parameter, returning -1'
            return_value = -1
    end select
end subroutine ltrans_get_3D_Double

subroutine ltrans_set_3D_Double(input_value, set_value)
    !<Add the required modules>
    implicit none
    character(len=*) :: input_value
    double precision, pointer :: set_value(:,:,:)
    integer :: dimen, istat
    print *, 'Setting value for the input parameter: ', trim(input_value)
    select case( trim(input_value) )
        case('zeta')
        	ALLOCATE(romZ(vi,uj,dimen), STAT=istat)
            romZ(t_ijruv(1):t_ijruv(2),t_ijruv(3):t_ijruv(4),:) = set_value
        case default
            print *, 'Error in fetching the value for the requested parameter'
    end select
end subroutine ltrans_set_3D_Double

subroutine ltrans_get_4D_Double(input_value, return_value)
    !<Add the required modules>
    implicit none
    character(len=*) :: input_value
    real(r8), pointer :: return_value(:,:,:,:)
    print *, 'ltrans_BMI> Fetching value for the input parameter: ', trim(input_value)
    select case( trim(input_value) )
        case('salt')
            return_value => OCEAN(1)%t(:,:,:,:,isalt)
        case default
            print *, 'Error in fetching the value for the requested parameter'
            return_value = -1
    end select
end subroutine ltrans_get_4D_Double

subroutine ltrans_set_4D_Double(input_value, set_value)
    !<Add the required modules>
    implicit none
    character(len=*) :: input_value
    double precision, pointer :: set_value(:,:,:,:)
    integer :: dimen,istat
    print *, 'Setting value for the input parameter: ', trim(input_value)
    select case( input_value )
        case('salt')
            ALLOCATE(ltrans(vi,uj,us,dimen), STAT=istat)
            ltrans(t_ijruv(1):t_ijruv(2),t_ijruv(3):t_ijruv(4),:,:) = set_value
        case default
            print *, 'Error in fetching the value for the requested parameter'
    end select
end subroutine ltrans_set_4D_Double

subroutine get_value_definitions(long_var_name, req_val, ret_val)
    implicit none
    character(len=*), intent(in) :: long_var_name
    character(len=*), intent(in) :: req_val
    character(len=*), intent(out) :: ret_val
    print *, 'LTRANS_BMI> Fetching definition for the long variable name: ', trim(long_var_name)
    select case( trim(long_var_name) )
        case('s_coordinate_stretching_curves_at_rho_points')
            if(trim(req_val) == "type")then
                ret_val = 'double'
            else if(trim(req_val) == "rank")then
                ret_val = "1"
            else if(trim(req_val) == "units")then
                ret_val = 'nondimensional'
            else if(trim(req_val) == "name")then
                ret_val = 'Cs_r'
            endif
        case default
            print *, 'LTRANS_BMI> Error in fetching the value for the requested long name'
            ret_val = "-1"
    end select
end subroutine get_value_definitions
