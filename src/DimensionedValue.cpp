#include "DimensionedValue.h"

#include <cmath>
#include <utility>

DimensionedValue::DimensionedValue() :
    m_value( NAN ),
    m_dim( FundamentalDimension::TIME ),
    m_valid( false )
{
}

DimensionedValue::DimensionedValue( const DimensionedValue& other ) :
    m_value( other.m_value ),
    m_dim( other.m_dim ),
    m_valid( other.m_valid )
{
}

DimensionedValue::DimensionedValue( double value, const Unit& units ) :
    DimensionedValue( units.ToBase( value ), units.dimension )
{
}

DimensionedValue::DimensionedValue( double value, Dimension dim ) :
    m_value( value ),
    m_dim( dim ),
    m_valid( !std::isnan( m_value ) )
{
}

double DimensionedValue::As( const Unit& units ) const
{
    if ( !m_valid || (units.dimension != m_dim) )
    {
        return NAN;
    }

    return units.FromBase( m_value );
}

DimensionedValue DimensionedValue::operator+() const
{
    return *this;
}

DimensionedValue DimensionedValue::operator-() const
{
    return DimensionedValue( -m_value, m_dim );
}

DimensionedValue& DimensionedValue::operator+=( DimensionedValue rhs )
{
    m_valid = m_valid && rhs.m_valid && (m_dim == rhs.m_dim);
    if ( m_valid )
    {
        m_value += rhs.m_value;
    }
    return *this;
}

DimensionedValue& DimensionedValue::operator-=( DimensionedValue rhs )
{
    m_valid = m_valid && rhs.m_valid && (m_dim == rhs.m_dim);
    if ( m_valid )
    {
        m_value -= rhs.m_value;
    }
    return *this;
}

DimensionedValue& DimensionedValue::operator*=( DimensionedValue rhs )
{
    m_valid = m_valid && rhs.m_valid;
    if ( m_valid )
    {
        m_value *= rhs.m_value;
        m_dim *= rhs.m_dim;
    }
    return *this;
}

DimensionedValue& DimensionedValue::operator/=( DimensionedValue rhs )
{
    m_valid = m_valid && rhs.m_valid;
    if ( m_valid )
    {
        m_value /= rhs.m_value;
        m_dim /= rhs.m_dim;
    }
    return *this;
}

bool operator==( const DimensionedValue& lhs, const DimensionedValue& rhs )
{
    return (lhs.m_valid && rhs.m_valid) &&
        (lhs.m_dim == rhs.m_dim) &&
        (lhs.m_value == rhs.m_value);
}

bool operator!=( const DimensionedValue& lhs, const DimensionedValue& rhs )
{
    return !(lhs == rhs);
}

bool operator<( const DimensionedValue& lhs, const DimensionedValue& rhs )
{
    return (lhs.m_valid && rhs.m_valid) &&
        (lhs.m_dim == rhs.m_dim) &&
        (lhs.m_value < rhs.m_value);
}

bool operator>( const DimensionedValue& lhs, const DimensionedValue& rhs )
{
    return (lhs.m_valid && rhs.m_valid) &&
        (lhs.m_dim == rhs.m_dim) &&
        (lhs.m_value > rhs.m_value);
}

bool operator<=( const DimensionedValue& lhs, const DimensionedValue& rhs )
{
    return (lhs < rhs) || (lhs == rhs);
}

bool operator>=( const DimensionedValue& lhs, const DimensionedValue& rhs )
{
    return (lhs > rhs) || (lhs == rhs);
}

DimensionedValue operator+( DimensionedValue lhs, const DimensionedValue& rhs )
{
    lhs += rhs;
    return lhs;
}

DimensionedValue operator-( DimensionedValue lhs, const DimensionedValue& rhs )
{
    lhs -= rhs;
    return lhs;
}

DimensionedValue operator*( DimensionedValue lhs, const DimensionedValue& rhs )
{
    lhs *= rhs;
    return lhs;
}

DimensionedValue operator/( DimensionedValue lhs, const DimensionedValue& rhs )
{
    lhs /= rhs;
    return lhs;
}

