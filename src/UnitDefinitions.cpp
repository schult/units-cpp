#include "UnitDefinitions.h"

#include <cmath>

template<int multiplier, int divisor>
static constexpr double Scale( double val )
{
    return val * multiplier / divisor;
}
#define SCALE(a, b) Scale<a, b>, Scale<b, a>

static constexpr double CelciusToBase( double val )
{
    return val + 273.15;
}

static constexpr double CelciusFromBase( double val )
{
    return val - 273.15;
}

static constexpr double FahrenheitToBase( double val )
{
    return (val + 459.67) * 5.0 / 9.0;
}

static constexpr double FahrenheitFromBase( double val )
{
    return (val * 9.0 / 5.0) - 459.67;
}

static constexpr double DegreesToBase( double val )
{
    return val * M_PI / 180.0;
}

static constexpr double DegreesFromBase( double val )
{
    return val * 180.0 / M_PI;
}

static constexpr double RpmToBase( double val )
{
    return val * (2*M_PI) / 60.0;
}

static constexpr double RpmFromBase( double val )
{
    return val * 60.0 / (2*M_PI);
}

namespace Units
{

// Length (meters) ============================================================
static constexpr Dimension length = FundamentalDimension::LENGTH;

const Unit millimeters( length, SCALE( 1, 1000 ) );
const Unit centimeters( length, SCALE( 1, 100 ) );
const Unit meters( length );
const Unit kilometers( length, SCALE( 1000, 1 ) );

const Unit inches( length, SCALE( 254, 10000 ) );
const Unit feet( length, SCALE( 3048, 10000 ) );
const Unit yards( length, SCALE( 9144, 10000 ) );
const Unit miles( length, SCALE( 160934, 100 ) );

// Mass (kilograms) ===========================================================
static constexpr Dimension mass = FundamentalDimension::MASS;

const Unit grams( mass, SCALE( 1, 1000 ) );
const Unit kilograms( mass );

const Unit pounds( mass, SCALE( 453592, 1000000 ) );

// Time (seconds) =============================================================
static constexpr Dimension time = FundamentalDimension::TIME;

const Unit milliseconds( time, SCALE( 1, 1000 ) );
const Unit seconds( time );
const Unit minutes( time, SCALE( 60, 1 ) );
const Unit hours( time, SCALE( 3600, 1 ) );

// Electric Current (amperes) =================================================
static constexpr Dimension current = FundamentalDimension::ELECTRIC_CURRENT;

const Unit amperes( current );

// Temperature (kelvin) =======================================================
static constexpr Dimension temperature = FundamentalDimension::TEMPERATURE;

const Unit kelvin( temperature );
const Unit celcius( temperature, CelciusToBase, CelciusFromBase );

const Unit fahrenheit( temperature, FahrenheitToBase, FahrenheitFromBase );

// Area (square meters) =======================================================
static constexpr Dimension area = length * length;

const Unit square_meters( area );
const Unit hectares( area, SCALE( 10000, 1 ) );

const Unit acres( area, SCALE( 404686, 100 ) );

// Volume (cubic meters) ======================================================
static constexpr Dimension volume = area * length;

const Unit milliliters( volume, SCALE( 1, 1000000 ) );
const Unit cubic_centimeters( volume, SCALE( 1, 1000000 ) );
const Unit liters( volume, SCALE( 1, 1000 ) );
const Unit cubic_meters( volume );

// Angle (radians) ============================================================
static constexpr Dimension angle;

const Unit radians( angle );
const Unit degrees( angle, DegreesToBase, DegreesFromBase );

// Angular Velocity (radians per second) ======================================
static constexpr Dimension angular_velocity =
    Dimension() / FundamentalDimension::TIME;

const Unit radians_per_second( angular_velocity );
const Unit rpm( angular_velocity, RpmToBase, RpmFromBase );

} // namespace Units

