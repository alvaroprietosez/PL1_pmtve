cmake_minimum_required(VERSION 3.20)

project(primitive)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)

add_library(matrix_lib primitive.cpp primitive.hpp)

add_executable(primitive main.cpp primitive.cpp primitive.hpp)

target_link_libraries(primitive GTest::GTest GTest::Main)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

target_link_libraries(primitive matrix_lib)

add_subdirectory(u_test)

