set(HEADERS
    Dimension.h
    DimensionedValue.h
    Unit.h
)

set(SOURCES
    Dimension.cpp
    DimensionedValue.cpp
)

add_library(Units ${SOURCES} ${HEADERS})

