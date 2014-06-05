cmake_minimum_required(VERSION 2.6)

project (bmi)
enable_language (Fortran)

set (BMI_VERSION 0.1)

configure_file (${CMAKE_CURRENT_SOURCE_DIR}/bmif.pc.cmake
                ${CMAKE_CURRENT_SOURCE_DIR}/bmif.pc)

              #set (CMAKE_FORTRAN_MODULE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/lib)
set (BUILD_SHARED_LIBS ON)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

set (bmi_lib_SRCS
  bmi_impl.f90)

add_library (bmif ${bmi_lib_SRCS} )

install(TARGETS bmif DESTINATION lib COMPONENT bmi)

########### Install files ###############

install(FILES  bmif.pc DESTINATION lib/pkgconfig)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/bmif.mod DESTINATION lib)

