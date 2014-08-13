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

std::ostream& operator<<( std::ostream& stream, const Dimension& dim )
{
    auto repeat = [](std::ostream& s, const char *str, int n) {
        for ( int i = 0; i < n; ++i )
        {
            s << str;
        }
    };

    stream << "< ";

    if ( dim.m_numer_length > 0 ||
        dim.m_numer_mass > 0 ||
        dim.m_numer_time > 0 ||
        dim.m_numer_current > 0 ||
        dim.m_numer_temperature > 0 )
    {
        repeat( stream, "Length ", dim.m_numer_length );
        repeat( stream, "Mass ", dim.m_numer_mass );
        repeat( stream, "Time ", dim.m_numer_time );
        repeat( stream, "Current ", dim.m_numer_current );
        repeat( stream, "Temperature ", dim.m_numer_temperature );
    }
    else
    {
        stream << "1 ";
    }

    if ( dim.m_denom_length > 0 ||
        dim.m_denom_mass > 0 ||
        dim.m_denom_time > 0 ||
        dim.m_denom_current > 0 ||
        dim.m_denom_temperature > 0 )
    {
        stream << "/ ";

        repeat( stream, "Length ", dim.m_denom_length );
        repeat( stream, "Mass ", dim.m_denom_mass );
        repeat( stream, "Time ", dim.m_denom_time );
        repeat( stream, "Current ", dim.m_denom_current );
        repeat( stream, "Temperature ", dim.m_denom_temperature );
    }

    stream << ">";
}

