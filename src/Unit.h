#ifndef UNITS_UNIT_H
#define UNITS_UNIT_H

#include "Dimension.h"

class Unit {
public:
    typedef double (*Conversion)( double );

    constexpr Unit( Dimension dim, Conversion to_base, Conversion from_base );

    const Dimension dimension;
    const Conversion ToBase;
    const Conversion FromBase;
};

constexpr Unit operator*( const Unit& lhs, const Unit& rhs );
constexpr Unit operator/( const Unit& lhs, const Unit& rhs );

#endif // UNITS_UNIT_H

