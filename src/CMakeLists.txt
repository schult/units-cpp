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

