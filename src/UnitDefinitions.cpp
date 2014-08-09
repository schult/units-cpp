#include "UnitDefinitions.h"

static constexpr double identity( double val ) { return val; }

template<int multiplier, int divisor>
static constexpr double scale( double val )
{
    return val * multiplier / divisor;
}

namespace Units
{

// Length =====================================================================
static constexpr Dimension length = FundamentalDimension::LENGTH;

Unit miles( length, scale<160934, 100>, scale<100, 160934> );
Unit yards( length, scale<9144, 10000>, scale<10000, 9144> );
Unit feet( length, scale<3048, 10000>, scale<10000, 3048> );
Unit inches( length, scale<254, 10000>, scale<10000, 254> );

Unit kilometers( length, scale<1000, 1>, scale<1, 1000> );
Unit meters( length, identity, identity );
Unit centimeters( length, scale<1, 100>, scale<100, 1> );
Unit millimeters( length, scale<1, 1000>, scale<1000, 1> );

} // namespace Units

