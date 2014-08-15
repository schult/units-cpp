set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core)
find_package(Qt5LinguistTools)
find_package(Qt5Widgets)

qt5_wrap_cpp(MOC
)

set(HEADERS
)

set(SOURCES
    main.cpp
)

qt5_wrap_ui(UI
)

include_directories(${Units_SOURCE_DIR}/src ${GTEST_INCLUDES})
add_executable(UnitsDemo ${SOURCES} ${HEADERS} ${MOC} ${UI})
target_link_libraries(UnitsDemo Units Qt5::Core Qt5::Widgets)

