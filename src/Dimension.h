#ifndef UNITS_DIMENSION_H
#define UNITS_DIMENSION_H

enum class FundamentalDimension
{
    LENGTH,
    MASS,
    TIME,
    ELECTRIC_CURRENT,
    TEMPERATURE
};

class Dimension
{
public:
    Dimension() = delete;
    constexpr Dimension( const Dimension& ) = default;

    constexpr Dimension( const FundamentalDimension& dim ) :
        m_numer_length( dim == FundamentalDimension::LENGTH ? 1 : 0 ),
        m_numer_mass( dim == FundamentalDimension::MASS ? 1 : 0 ),
        m_numer_time( dim == FundamentalDimension::TIME ? 1 : 0 ),
        m_numer_current( dim == FundamentalDimension::ELECTRIC_CURRENT ? 1 : 0),
        m_numer_temperature( dim == FundamentalDimension::TEMPERATURE ? 1 : 0),
        m_denom_length( 0 ),
        m_denom_mass( 0 ),
        m_denom_time( 0 ),
        m_denom_current( 0 ),
        m_denom_temperature( 0 )
    {
    }

    Dimension& operator=( const Dimension& ) = default;
    Dimension& operator*=( const Dimension& rhs );
    Dimension& operator/=( const Dimension& rhs );

    friend bool operator==( const Dimension& lhs, const Dimension& rhs );
    friend bool operator!=( const Dimension& lhs, const Dimension& rhs );

    friend constexpr Dimension operator*(
        const Dimension& lhs, const Dimension& rhs );
    friend constexpr Dimension operator/(
        const Dimension& lhs, const Dimension& rhs );

private:
    static constexpr unsigned int Reduced(unsigned int a, unsigned int b )
    {
        return (a > b) ? a - b : 0;
    }

    constexpr Dimension(
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
        m_numer_length( Reduced( n_length, d_length ) ),
        m_numer_mass( Reduced( n_mass, d_mass ) ),
        m_numer_time( Reduced( n_time, d_time ) ),
        m_numer_current( Reduced( n_current, d_current ) ),
        m_numer_temperature( Reduced( n_temperature, d_temperature ) ),

        m_denom_length( Reduced( d_length, n_length ) ),
        m_denom_mass( Reduced( d_mass, n_mass ) ),
        m_denom_time( Reduced( d_time, n_time ) ),
        m_denom_current( Reduced( d_current, n_current ) ),
        m_denom_temperature( Reduced( d_temperature, n_temperature ) )
    {
    }

    unsigned int m_numer_length;
    unsigned int m_numer_mass;
    unsigned int m_numer_time;
    unsigned int m_numer_current;
    unsigned int m_numer_temperature;

    unsigned int m_denom_length;
    unsigned int m_denom_mass;
    unsigned int m_denom_time;
    unsigned int m_denom_current;
    unsigned int m_denom_temperature;
};

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

#endif // UNITS_DIMENSION_H

