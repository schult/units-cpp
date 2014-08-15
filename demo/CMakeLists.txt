set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core)
find_package(Qt5LinguistTools)
find_package(Qt5Widgets)

set(LANG
    translations/units.es_AR.ts
)

qt5_wrap_cpp(MOC
)

set(HEADERS
)

set(SOURCES
    main.cpp
)

qt5_wrap_ui(UI
)

add_custom_target(lupdate COMMAND lupdate . -ts ${LANG}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${Units_SOURCE_DIR}/src)
qt5_add_translation(TRANSLATIONS ${LANG})
add_executable(UnitsDemo ${SOURCES} ${HEADERS} ${MOC} ${UI} ${TRANSLATIONS})
target_link_libraries(UnitsDemo Units Qt5::Core Qt5::Widgets)

