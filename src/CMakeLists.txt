project(Units)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(HEADERS
    Dimension.h
    DimensionedValue.h
    Unit.h

    UnitDefinitions.h
    UnitText.h
)

set(SOURCES
    Dimension.cpp
    DimensionedValue.cpp

    UnitDefinitions.cpp
    UnitText.cpp
)

add_library(Units ${SOURCES} ${HEADERS})

