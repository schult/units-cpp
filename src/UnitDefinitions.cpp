#include "UnitDefinitions.h"

template<int multiplier, int divisor>
static constexpr double scale( double val )
{
    return val * multiplier / divisor;
}
#define SCALE(a, b) scale<b, a>, scale<a, b>

namespace Units
{

// Length (meters) ============================================================
static constexpr Dimension length = FundamentalDimension::LENGTH;

const Unit miles( length, SCALE( 160934, 100 ) );
const Unit yards( length, SCALE( 9144, 10000 ) );
const Unit feet( length, SCALE( 3048, 10000 ) );
const Unit inches( length, SCALE( 254, 10000 ) );

const Unit kilometers( length, SCALE( 1000, 1 ) );
const Unit meters( length );
const Unit centimeters( length, SCALE( 1, 100 ) );
const Unit millimeters( length, SCALE( 1, 1000 ) );

} // namespace Units

