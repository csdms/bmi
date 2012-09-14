cmake_minimum_required(VERSION 2.6)

project (bmi)

set (BMI_VERSION 0.1)

configure_file (${CMAKE_CURRENT_SOURCE_DIR}/bmicxx.pc.cmake
                ${CMAKE_CURRENT_SOURCE_DIR}/bmicxx.pc)

set (BUILD_SHARED_LIBS ON)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

set (bmi_lib_SRCS
  bmi_impl.cxx)

add_library (bmicxx ${bmi_lib_SRCS} )

install(TARGETS bmicxx DESTINATION lib COMPONENT bmicxx)

########### Install files ###############

install(FILES bmi.hxx
        DESTINATION include
        COMPONENT bmi)

install(FILES bmicxx.pc DESTINATION lib/pkgconfig)

