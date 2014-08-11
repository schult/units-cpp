#include <iostream>
#include <type_traits>

#include "src/DimensionedValue.h"
#include "src/UnitDefinitions.h"
#include "src/UnitText.h"

// TODO: Translation?
// TODO: Unit tests (gmock?)

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

    std::cout << d3.As( Units::feet ) << " " << Units::Abbr( Units::feet ) << std::endl;

    DimensionedValue d4( 1.0, Units::kilograms );

    std::cout << d4.As( Units::pounds ) << " " << Units::Abbr( Units::pounds) << std::endl;

    return 0;
}

