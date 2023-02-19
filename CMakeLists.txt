cmake_minimum_required(VERSION 3.24)
project(TechnicCraft)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()

add_subdirectory(T3D)
add_subdirectory(Game)
add_subdirectory(Test)
