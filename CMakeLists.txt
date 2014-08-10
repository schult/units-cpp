project(UnitsTest)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(UnitsTest test.cpp)
target_link_libraries(UnitsTest ${CMAKE_SOURCE_DIR}/build/libUnits.a)

