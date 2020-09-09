#ifndef UNITS_COMPOUND_UNIT_H
#define UNITS_COMPOUND_UNIT_H

#include <vector>

#include "Unit.h"

class CompoundUnit
{
public:
    CompoundUnit() = default;
    CompoundUnit( const CompoundUnit& ) = default;
    CompoundUnit( const Unit& unit );

    CompoundUnit& operator=( const CompoundUnit& ) = default;
    CompoundUnit& operator*=( const CompoundUnit& rhs );
    CompoundUnit& operator/=( const CompoundUnit& rhs );

    const std::vector<Unit>& Numerator() const { return m_numerator; }
    const std::vector<Unit>& Denominator() const { return m_denominator; }

    CompoundUnit Reduced() const;

    double ToBase( double val ) const;
    double FromBase( double val ) const;
    Dimension GetDimension() const;

private:
    std::vector<Unit> m_numerator;
    std::vector<Unit> m_denominator;
};

CompoundUnit operator*( const CompoundUnit& lhs, const CompoundUnit& rhs );
CompoundUnit operator/( const CompoundUnit& lhs, const CompoundUnit& rhs );

CompoundUnit operator*( const CompoundUnit& lhs, const Unit& rhs )
{
    return lhs * CompoundUnit( rhs );
}

CompoundUnit operator/( const CompoundUnit& lhs, const Unit& rhs )
{
    return lhs / CompoundUnit( rhs );
}

#endif // UNITS_COMPOUND_UNIT_H

