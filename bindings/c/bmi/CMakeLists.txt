cmake_minimum_required(VERSION 2.6)

project (poisson)

set (POISSON_VERSION 0.1)

configure_file (${CMAKE_CURRENT_SOURCE_DIR}/poisson.pc.cmake
                ${CMAKE_CURRENT_SOURCE_DIR}/poisson.pc)

set (BUILD_SHARED_LIBS ON)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

set (bmi_poisson_lib_SRCS bmi_poisson.c poisson.c)
add_library (bmi_poisson ${bmi_poisson_lib_SRCS} )

########### Poisson main ###############

set (poisson_sources main.c poisson.c)
add_executable (poisson ${poisson_sources})

########### Install files ###############

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/poisson DESTINATION bin
        COMPONENT poisson)
install(TARGETS poisson DESTINATION lib COMPONENT poisson)
install(TARGETS bmi_poisson DESTINATION lib COMPONENT poisson)
install(FILES bmi_poisson.h bmi.h
        DESTINATION include/poisson
        COMPONENT poisson)
install(FILES poisson.pc DESTINATION lib/pkgconfig)

