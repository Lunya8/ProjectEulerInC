cmake_minimum_required(VERSION 3.21)
project(ProjectEuler C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjectEulerRun problems/1to100/20/0.c)
target_include_directories(ProjectEulerRun PUBLIC common)
target_link_libraries(ProjectEulerRun m)
