#include "Dimension.h"

static constexpr unsigned int reduced(unsigned int a, unsigned int b )
{
    return (a > b) ? a - b : 0;
}

Dimension& Dimension::operator*=( const Dimension& rhs )
{
    *this = *this * rhs;
    return *this;
}

Dimension& Dimension::operator/=( const Dimension& rhs )
{
    *this = *this / rhs;
    return *this;
}

bool operator==( const Dimension& lhs, const Dimension& rhs )
{
    return lhs.m_numer_length == rhs.m_numer_length &&
        lhs.m_numer_mass == rhs.m_numer_mass &&
        lhs.m_numer_time == rhs.m_numer_time &&
        lhs.m_numer_current == rhs.m_numer_current &&
        lhs.m_numer_temperature == rhs.m_numer_temperature &&
        lhs.m_denom_length == rhs.m_denom_length &&
        lhs.m_denom_mass == rhs.m_denom_mass &&
        lhs.m_denom_time == rhs.m_denom_time &&
        lhs.m_denom_current == rhs.m_denom_current &&
        lhs.m_denom_temperature == rhs.m_denom_temperature;
}

bool operator!=( const Dimension& lhs, const Dimension& rhs )
{
    return !(lhs == rhs);
}

constexpr Dimension operator*( const Dimension& lhs, const Dimension& rhs )
{
    return Dimension(
        lhs.m_numer_length + rhs.m_numer_length,
        lhs.m_numer_mass + rhs.m_numer_mass,
        lhs.m_numer_time + rhs.m_numer_time,
        lhs.m_numer_current + rhs.m_numer_current,
        lhs.m_numer_temperature + rhs.m_numer_temperature,
        lhs.m_denom_length + rhs.m_denom_length,
        lhs.m_denom_mass + rhs.m_denom_mass,
        lhs.m_denom_time + rhs.m_denom_time,
        lhs.m_denom_current + rhs.m_denom_current,
        lhs.m_denom_temperature + rhs.m_denom_temperature );
}

constexpr Dimension operator/( const Dimension& lhs, const Dimension& rhs )
{
    return Dimension(
        lhs.m_numer_length + rhs.m_denom_length,
        lhs.m_numer_mass + rhs.m_denom_mass,
        lhs.m_numer_time + rhs.m_denom_time,
        lhs.m_numer_current + rhs.m_denom_current,
        lhs.m_numer_temperature + rhs.m_denom_temperature,
        lhs.m_denom_length + rhs.m_numer_length,
        lhs.m_denom_mass + rhs.m_numer_mass,
        lhs.m_denom_time + rhs.m_numer_time,
        lhs.m_denom_current + rhs.m_numer_current,
        lhs.m_denom_temperature + rhs.m_numer_temperature );
}

constexpr Dimension::Dimension(
        unsigned int n_length,
        unsigned int n_mass,
        unsigned int n_time,
        unsigned int n_current,
        unsigned int n_temperature,

        unsigned int d_length,
        unsigned int d_mass,
        unsigned int d_time,
        unsigned int d_current,
        unsigned int d_temperature ) :
    m_numer_length( reduced( n_length, d_length ) ),
    m_numer_mass( reduced( n_mass, d_mass ) ),
    m_numer_time( reduced( n_time, d_time ) ),
    m_numer_current( reduced( n_current, d_current ) ),
    m_numer_temperature( reduced( n_temperature, d_temperature ) ),

    m_denom_length( reduced( d_length, n_length ) ),
    m_denom_mass( reduced( d_mass, n_mass ) ),
    m_denom_time( reduced( d_time, n_time ) ),
    m_denom_current( reduced( d_current, n_current ) ),
    m_denom_temperature( reduced( d_temperature, n_temperature ) )
{
}

constexpr Dimension operator*(
    const Dimension& lhs, const FundamentalDimension& rhs )
{
    return lhs * Dimension( rhs );
}

constexpr Dimension operator/(
    const Dimension& lhs, const FundamentalDimension& rhs )
{
    return rhs / Dimension( rhs );
}

