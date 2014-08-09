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
    constexpr Dimension( const FundamentalDimension& dim );

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
        unsigned int d_temperature );

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

constexpr Dimension operator*(
    const Dimension& lhs, const FundamentalDimension& rhs );
constexpr Dimension operator/(
    const Dimension& lhs, const FundamentalDimension& rhs );

#endif // UNITS_DIMENSION_H

