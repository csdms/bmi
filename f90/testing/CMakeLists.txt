cmake_minimum_required(VERSION 2.6)

project (bmi)
enable_language (Fortran)
include (CTest)

add_test (BMI_IRF irf_test)
add_test (BMI_GET_VALUES get_value_test)
add_test (BMI_SET_VALUES set_value_test)

set (BUILD_SHARED_LIBS ON)

include_directories( ${CMAKE_BINARY_DIR}/bmi )
#link_directories( ${CMAKE_BINARY_DIR}/bmi )

########### BMI main program ###############

set (bmi_irf_SRCS irf_test.f90)
set (bmi_get_value_SRCS get_value_test.f90)
set (bmi_set_value_SRCS set_value_test.f90)

add_executable(irf_test ${bmi_irf_SRCS})
add_executable(get_value_test ${bmi_get_value_SRCS})
add_executable(set_value_test ${bmi_set_value_SRCS})

target_link_libraries(irf_test bmif)
target_link_libraries(get_value_test bmif)
target_link_libraries(set_value_test bmif)

#install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/irf_test
#        DESTINATION bin COMPONENT bmi)
#install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/get_value
#        DESTINATION bin COMPONENT bmi)
#install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/set_value
#        DESTINATION bin COMPONENT bmi)

