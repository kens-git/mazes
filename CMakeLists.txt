cmake_minimum_required(VERSION 2.8)

project(mazes)

set(CMAKE_CXX_STANDARD 14)
#add_compile_options(-std=c++14)

include_directories(include algos)

file(GLOB sources "source/*.cpp" "algos/*.cpp")

add_executable(${PROJECT_NAME} "main.cpp" ${sources})
