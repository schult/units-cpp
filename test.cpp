#include <iostream>
#include <type_traits>

#include "src/UnitDefinitions.h"

// TODO: class DimensionedValue
// TODO: Label text
// TODO: Translation?
// TODO: Unit tests (gmock?)
// TODO: Build system (cmake+ninja)

constexpr double ToBase( double val ) { return val * 1000.0; }
constexpr double FromBase( double val ) { return val / 1000.0; }

constexpr Dimension length =
    FundamentalDimension::LENGTH *
    FundamentalDimension::LENGTH;
constexpr Unit foo( length, ToBase, FromBase );

int main()
{
    std::cout << std::is_literal_type<Unit>::value << std::endl;

    return 0;
}

