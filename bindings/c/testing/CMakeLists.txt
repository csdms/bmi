cmake_minimum_required(VERSION 2.6)

project (bmi)
include (CTest)

add_test (BMI_IRF test_irf)
add_test (BMI_VAR_NAMES test_print_var_names)
add_test (BMI_GET_VALUES test_get_value)
add_test (BMI_SET_VALUES test_set_value)
add_test (BMI_GRID_INFO test_grid_info)

set (BUILD_SHARED_LIBS ON)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/.. )

########### BMI main program ###############

set (bmi_irf_SRCS test_irf.c)
set (bmi_var_names_SRCS test_print_var_names.c)
set (bmi_get_value_SRCS test_get_value.c)
set (bmi_set_value_SRCS test_set_value.c)
set (bmi_grid_info_SRCS test_grid_info.c)

add_executable(test_irf ${bmi_irf_SRCS})
add_executable(test_print_var_names ${bmi_var_names_SRCS})
add_executable(test_get_value ${bmi_get_value_SRCS})
add_executable(test_set_value ${bmi_set_value_SRCS})
add_executable(test_grid_info ${bmi_grid_info_SRCS})

target_link_libraries(test_irf bmi_poisson)
target_link_libraries(test_print_var_names bmi_poisson)
target_link_libraries(test_get_value bmi_poisson)
target_link_libraries(test_set_value bmi_poisson)
target_link_libraries(test_grid_info bmi_poisson)
