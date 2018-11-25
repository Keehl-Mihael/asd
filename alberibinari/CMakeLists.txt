cmake_minimum_required(VERSION 3.3)
project(test_build)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
set(BUILD_1 main)
set(SOURCE_FILES_1 main.cpp color_bin_tree.cpp color_bin_tree.h)
add_executable(${BUILD_1} ${SOURCE_FILES_1})