#include <iostream>
#include <type_traits>

#include "src/DimensionedValue.h"
#include "src/UnitDefinitions.h"

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
    std::cout << std::is_literal_type<Dimension>::value << std::endl;
    std::cout << std::is_literal_type<Unit>::value << std::endl;

    DimensionedValue d1( 1.0, Units::feet );
    DimensionedValue d2( 1.0, Units::yards );
    DimensionedValue d3 = d1 + d2;

    std::cout << d3.As( Units::feet ) << std::endl;

    return 0;
}

