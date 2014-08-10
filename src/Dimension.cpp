#include "Dimension.h"

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

