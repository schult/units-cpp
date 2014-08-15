set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core)
find_package(Qt5LinguistTools)
find_package(Qt5Widgets)

set(LANG
    translations/units_es-AR.ts
)

qt5_wrap_cpp(MOC
)

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

qt5_wrap_ui(UI
)

add_custom_target(lupdate COMMAND lupdate . -ts ${LANG}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

qt5_add_translation(TRANSLATIONS ${LANG})
add_library(Units ${SOURCES} ${HEADERS} ${MOC} ${UI} ${TRANSLATIONS})
target_link_libraries(Units Qt5::Core Qt5::Widgets)

