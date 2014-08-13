cmake_minimum_required(VERSION 2.8)
project(Units)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(src)
add_subdirectory(test EXCLUDE_FROM_ALL)

