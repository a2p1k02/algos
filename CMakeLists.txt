cmake_minimum_required(VERSION 3.28)
project(algos)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} src/main.cpp src/algos.hpp src/structures.hpp src/hash_table.hpp)
