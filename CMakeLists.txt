cmake_minimum_required(VERSION 3.0.0)
project(tournament)

add_subdirectory(tour_lib)

message("TOUR_LIB_INCLUDE_DIRS = ${TOUR_LIB_INCLUDE_DIRS}")
message("TOUR_LIB_LIBRARIES = ${TOUR_LIB_LIBRARIES}")

add_executable(${PROJECT_NAME} main.c)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

target_include_directories(${PROJECT_NAME} PUBLIC ${TOUR_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${TOUR_LIB_LIBRARIES})

add_subdirectory(test)