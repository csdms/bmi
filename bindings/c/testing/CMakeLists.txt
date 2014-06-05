cmake_minimum_required(VERSION 2.6)

project (bmi)
include (CTest)

add_test (BMI_IRF irf_test)
add_test (BMI_VAR_NAMES print_var_names_test)
add_test (BMI_GET_VALUES get_value_test)
add_test (BMI_SET_VALUES set_value_test)
add_test (BMI_GRID_INFO grid_info_test)

set (BUILD_SHARED_LIBS ON)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../bmi )

########### BMI main program ###############

set (bmi_irf_SRCS irf_test.c)
set (bmi_var_names_SRCS print_var_names_test.c)
set (bmi_get_value_SRCS get_value_test.c)
set (bmi_set_value_SRCS set_value_test.c)
set (bmi_grid_info_SRCS grid_info_test.c)

add_executable(irf_test ${bmi_irf_SRCS})
add_executable(print_var_names_test ${bmi_var_names_SRCS})
add_executable(get_value_test ${bmi_get_value_SRCS})
add_executable(set_value_test ${bmi_set_value_SRCS})
add_executable(grid_info_test ${bmi_grid_info_SRCS})

target_link_libraries(irf_test bmi)
target_link_libraries(print_var_names_test bmi)
target_link_libraries(get_value_test bmi)
target_link_libraries(set_value_test bmi)
target_link_libraries(grid_info_test bmi)

#install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/bmi
#        DESTINATION bin COMPONENT bmi)
#install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/print_var_names
#        DESTINATION bin COMPONENT bmi)
#install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/get_value
#        DESTINATION bin COMPONENT bmi)
#install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/set_value
#        DESTINATION bin COMPONENT bmi)
#install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/grid_info
#        DESTINATION bin COMPONENT bmi)

