project(Units)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(Units test.cpp)
target_link_libraries(Units ${CMAKE_SOURCE_DIR}/build/libUnits.a)

