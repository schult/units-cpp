#ifndef UNITS_UNIT_H
#define UNITS_UNIT_H

#include "Dimension.h"

class Unit {
private:
    static constexpr double identity( double val ) { return val; }

public:
    typedef double (*Conversion)( double );

    // Base units.
    explicit constexpr Unit( Dimension dim ) :
        dimension( dim ),
        ToBase( identity ),
        FromBase( identity )
    {
    }

    // Units that conversion.
    constexpr Unit( Dimension dim, Conversion to_base, Conversion from_base ) :
        dimension( dim ),
        ToBase( to_base ),
        FromBase( from_base )
    {
    }

    Unit( const Unit& ) = delete;
    Unit& operator=( const Unit& ) = delete;

    const Dimension dimension;
    const Conversion ToBase;
    const Conversion FromBase;
};

#endif // UNITS_UNIT_H

