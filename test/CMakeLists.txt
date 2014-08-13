add_subdirectory(gmock)
set(GTEST_INCLUDES gmock/include gmock/gtest/include)
set(GTEST_LIBS gmock gtest gtest_main)

set(HEADERS
)

set(SOURCES
    DimensionTest.cpp
    UnitTest.cpp
)

include_directories(${Units_SOURCE_DIR}/src ${GTEST_INCLUDES})
add_executable(UnitsTest ${SOURCES} ${HEADERS})
target_link_libraries(UnitsTest Units ${GTEST_LIBS})

add_custom_target(check COMMAND UnitsTest DEPENDS UnitsTest)

