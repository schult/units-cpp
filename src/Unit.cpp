#include "Unit.h"

constexpr Unit::Unit(
        Dimension dim,
        Conversion to_base,
        Conversion from_base ) :
    dimension( dim ),
    ToBase( to_base ),
    FromBase( from_base )
{
}

/*
constexpr Unit operator*( const Unit& lhs, const Unit& rhs )
{
    // TODO
    return Unit(
        lhs.dimension * rhs.dimension,
        composite<lhs.ToBase, rhs.ToBase>,
        composite<lhs.FromBase, rhs.ToBase>);
}

constexpr Unit operator/( const Unit& lhs, const Unit& rhs )
{
    // TODO
    return Unit(
        lhs.dimension / rhs.dimension,
        composite<lhs.ToBase, rhs.ToBase>,
        composite<lhs.FromBase, rhs.ToBase>);
}
*/

