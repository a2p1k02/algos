cmake_minimum_required(VERSION 3.28)
project(algos)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PUBLIC src/main.cpp
)

target_sources(${PROJECT_NAME}
    PUBLIC FILE_SET cxx_modules TYPE CXX_MODULES FILES src/algos.cppm
)
