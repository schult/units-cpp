#ifndef UNITS_DIMENSIONED_VALUE_H
#define UNITS_DIMENSIONED_VALUE_H

#include "Dimension.h"
#include "Unit.h"

class DimensionedValue
{
public:
    DimensionedValue();
    DimensionedValue( const DimensionedValue& other );
    DimensionedValue( double value, const Unit& units );

    double As( const Unit& units ) const;

    friend bool operator==(
        const DimensionedValue& lhs, const DimensionedValue& rhs );
    friend bool operator<(
        const DimensionedValue& lhs, const DimensionedValue& rhs );
    friend bool operator>(
        const DimensionedValue& lhs, const DimensionedValue& rhs );

    DimensionedValue operator+() const;
    DimensionedValue operator-() const;

    DimensionedValue& operator=( DimensionedValue rhs );
    DimensionedValue& operator+=( DimensionedValue rhs );
    DimensionedValue& operator-=( DimensionedValue rhs );
    DimensionedValue& operator*=( DimensionedValue rhs );
    DimensionedValue& operator/=( DimensionedValue rhs );

private:
    DimensionedValue( double value, Dimension dim );

    double m_value;
    Dimension m_dim;
    bool m_valid;
};

bool operator==( const DimensionedValue& lhs, const DimensionedValue& rhs );
bool operator!=( const DimensionedValue& lhs, const DimensionedValue& rhs );
bool operator<( const DimensionedValue& lhs, const DimensionedValue& rhs );
bool operator>( const DimensionedValue& lhs, const DimensionedValue& rhs );
bool operator<=( const DimensionedValue& lhs, const DimensionedValue& rhs );
bool operator>=( const DimensionedValue& lhs, const DimensionedValue& rhs );

DimensionedValue operator+(
    DimensionedValue lhs, const DimensionedValue& rhs );
DimensionedValue operator-(
    DimensionedValue lhs, const DimensionedValue& rhs );
DimensionedValue operator*(
    DimensionedValue lhs, const DimensionedValue& rhs );
DimensionedValue operator/(
    DimensionedValue lhs, const DimensionedValue& rhs );

#endif // UNITS_DIMENSIONED_VALUE_H

