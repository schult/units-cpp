#include <iostream>
#include <type_traits>

#include "src/Unit.h"

// TODO: class DimensionedValue
// TODO: Label text
// TODO: Translation?
// TODO: Unit tests (gmock?)
// TODO: Build system (cmake+ninja)


constexpr double AtoB(double val) { return val * 3; }
constexpr double BtoA(double val) { return val / 3; }

constexpr Dimension d =
        FundamentalDimension::LENGTH *
        FundamentalDimension::LENGTH *
        FundamentalDimension::LENGTH /
        FundamentalDimension::TIME;

constexpr Unit bar(d, AtoB, BtoA);

int main() {
    std::cout << std::is_literal_type<Unit>::value << std::endl;

    return 0;
}

