cmake_minimum_required(VERSION 3.0.0)
project(tour_lib)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-g -fprofile-arcs -ftest-coverage -fPIC -O0")

file(GLOB SOURCES src/*.c)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)

message("INCLUDE_DIRS = ${INCLUDE_DIRS}")

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})

set(TOUR_LIB_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(TOUR_LIB_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)