#include "UnitDefinitions.h"

#include <cmath>

#include <QCoreApplication>
#include <QtGlobal>

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

QString Translate( const Unit& u )
{
    return QCoreApplication::translate( "Units", u.symbol );
}

// Length (meters) ============================================================
static constexpr Dimension length = FundamentalDimension::LENGTH;

//: The symbol for millimeters (length)
const Unit millimeters( QT_TRANSLATE_NOOP_UTF8( "Units", "mm" ), length, SCALE( 1, 1000 ) );
//: The symbol for centimeters (length)
const Unit centimeters( QT_TRANSLATE_NOOP_UTF8( "Units", "cm" ), length, SCALE( 1, 100 ) );
//: The symbol for meters (length)
const Unit meters( QT_TRANSLATE_NOOP_UTF8( "Units", "m" ), length );
//: The symbol for kilometers (length)
const Unit kilometers( QT_TRANSLATE_NOOP_UTF8( "Units", "km" ), length, SCALE( 1000, 1 ) );

//: The symbol for inches (length)
const Unit inches( QT_TRANSLATE_NOOP_UTF8( "Units", "in" ), length, SCALE( 254, 10000 ) );
//: The symbol for feet (length)
const Unit feet( QT_TRANSLATE_NOOP_UTF8( "Units", "ft" ), length, SCALE( 3048, 10000 ) );
//: The symbol for yards (length)
const Unit yards( QT_TRANSLATE_NOOP_UTF8( "Units", "yd" ), length, SCALE( 9144, 10000 ) );
//: The symbol for miles (length)
const Unit miles( QT_TRANSLATE_NOOP_UTF8( "Units", "mi" ), length, SCALE( 160934, 100 ) );

// Mass (kilograms) ===========================================================
static constexpr Dimension mass = FundamentalDimension::MASS;

//: The symbol for grams (mass)
const Unit grams( QT_TRANSLATE_NOOP_UTF8( "Units", "g" ), mass, SCALE( 1, 1000 ) );
//: The symbol for kilograms (mass)
const Unit kilograms( QT_TRANSLATE_NOOP_UTF8( "Units", "kg" ), mass );

//: The symbol for pounds (mass)
const Unit pounds( QT_TRANSLATE_NOOP_UTF8( "Units", "lbs" ), mass, SCALE( 453592, 1000000 ) );

// Time (seconds) =============================================================
static constexpr Dimension time = FundamentalDimension::TIME;

//: The symbol for milliseconds (time)
const Unit milliseconds( QT_TRANSLATE_NOOP_UTF8( "Units", "ms" ), time, SCALE( 1, 1000 ) );
//: The symbol for seconds (time)
const Unit seconds( QT_TRANSLATE_NOOP_UTF8( "Units", "s" ), time );
//: The symbol for minutes (time)
const Unit minutes( QT_TRANSLATE_NOOP_UTF8( "Units", "min" ), time, SCALE( 60, 1 ) );
//: The symbol for hours (time)
const Unit hours( QT_TRANSLATE_NOOP_UTF8( "Units", "hrs" ), time, SCALE( 3600, 1 ) );

// Electric Current (amperes) =================================================
static constexpr Dimension current = FundamentalDimension::ELECTRIC_CURRENT;

//: The symbol for amperes (electric current)
const Unit amperes( QT_TRANSLATE_NOOP_UTF8( "Units", "A" ), current );

// Temperature (kelvin) =======================================================
static constexpr Dimension temperature = FundamentalDimension::TEMPERATURE;

//: The symbol for kelvin (temperature)
const Unit kelvin( QT_TRANSLATE_NOOP_UTF8( "Units", "K" ), temperature );
//: The symbol for degrees Celcius (temperature)
const Unit celcius( QT_TRANSLATE_NOOP_UTF8( "Units", "°C" ), temperature, CelciusToBase, CelciusFromBase );

//: The symbol for degrees Fahrenheit (temperature)
const Unit fahrenheit( QT_TRANSLATE_NOOP_UTF8( "Units", "°F" ), temperature, FahrenheitToBase, FahrenheitFromBase );

// Area (square meters) =======================================================
static constexpr Dimension area = length * length;

//: The symbol for square meters (area)
const Unit square_meters( QT_TRANSLATE_NOOP_UTF8( "Units", "m²" ), area );
//: The symbol for hectares (area)
const Unit hectares( QT_TRANSLATE_NOOP_UTF8( "Units", "ha" ), area, SCALE( 10000, 1 ) );

//: The symbol for acres (area)
const Unit acres( QT_TRANSLATE_NOOP_UTF8( "Units", "ac" ), area, SCALE( 404686, 100 ) );

// Volume (cubic meters) ======================================================
static constexpr Dimension volume = area * length;

//: The symbol for milliliters (volume)
const Unit milliliters( QT_TRANSLATE_NOOP_UTF8( "Units", "mL" ), volume, SCALE( 1, 1000000 ) );
//: The symbol for cubic centimeters (volume)
const Unit cubic_centimeters( QT_TRANSLATE_NOOP_UTF8( "Units", "cm³" ), volume, SCALE( 1, 1000000 ) );
//: The symbol for liters (volume)
const Unit liters( QT_TRANSLATE_NOOP_UTF8( "Units", "L" ), volume, SCALE( 1, 1000 ) );
//: The symbol for cubic meters (volume)
const Unit cubic_meters( QT_TRANSLATE_NOOP_UTF8( "Units", "m³" ), volume );

// Angle (radians) ============================================================
static constexpr Dimension angle;

//: The symbol for radians (angle)
const Unit radians( QT_TRANSLATE_NOOP_UTF8( "Units", "rad" ), angle );
//: The symbol for degrees (angle)
const Unit degrees( QT_TRANSLATE_NOOP_UTF8( "Units", "°" ), angle, DegreesToBase, DegreesFromBase );

// Angular Velocity (radians per second) ======================================
static constexpr Dimension angular_velocity =
    Dimension() / FundamentalDimension::TIME;

//: The symbol for radians per second (angular velocity)
const Unit radians_per_second( QT_TRANSLATE_NOOP_UTF8( "Units", "rad/s" ), angular_velocity );
//: The symbol for rotations per minute (angular velocity)
const Unit rpm( QT_TRANSLATE_NOOP_UTF8( "Units", "rpm" ), angular_velocity, RpmToBase, RpmFromBase );

// Ratio ======================================================================
static constexpr Dimension ratio;

//: The symbol for percent
const Unit percent( QT_TRANSLATE_NOOP_UTF8( "Units", "%" ), ratio, SCALE( 100, 1 ) );

} // namespace Units

