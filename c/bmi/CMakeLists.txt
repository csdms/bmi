cmake_minimum_required(VERSION 2.6)

project (bmi)

set (BUILD_SHARED_LIBS ON)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

set (bmi_lib_SRCS
  bmi_impl.c)

add_library (bmi ${bmi_lib_SRCS} )

install(TARGETS bmi DESTINATION lib COMPONENT bmi)

########### Install files ###############

install(FILES bmi.h
        DESTINATION include
        COMPONENT bmi)

