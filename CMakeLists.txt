cmake_minimum_required(VERSION 2.8)
project(Units)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

enable_testing()
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})

add_subdirectory(src)
add_subdirectory(test EXCLUDE_FROM_ALL)

