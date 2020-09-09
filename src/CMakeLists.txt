set(HEADERS
    Dimension.h
    DimensionedValue.h
    Unit.h
    CompoundUnit.h
)

set(SOURCES
    Dimension.cpp
    DimensionedValue.cpp
)

add_library(Units ${SOURCES} ${HEADERS})

