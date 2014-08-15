#include "UnitText.h"

#include <unordered_map>

#include <QCoreApplication>
#include <QtGlobal>

#include "UnitDefinitions.h"

namespace Units
{

static const std::unordered_map<const Unit *, const char *> abbreviation = {
    // Length =================================================================

    //: The symbol for millimeters (length)
    { &millimeters, QT_TRANSLATE_NOOP_UTF8( "Units", "mm" ) },
    //: The symbol for centimeters (length)
    { &centimeters, QT_TRANSLATE_NOOP_UTF8( "Units", "cm" ) },
    //: The symbol for meters (length)
    { &meters, QT_TRANSLATE_NOOP_UTF8( "Units", "m" ) },
    //: The symbol for kilometers (length)
    { &kilometers, QT_TRANSLATE_NOOP_UTF8( "Units", "km" ) },

    //: The symbol for inches (length)
    { &inches, QT_TRANSLATE_NOOP_UTF8( "Units", "in" ) },
    //: The symbol for feet (length)
    { &feet, QT_TRANSLATE_NOOP_UTF8( "Units", "ft" ) },
    //: The symbol for yards (length)
    { &yards, QT_TRANSLATE_NOOP_UTF8( "Units", "yd" ) },
    //: The symbol for miles (length)
    { &miles, QT_TRANSLATE_NOOP_UTF8( "Units", "mi" ) },

    // Mass ===================================================================

    //: The symbol for grams (mass)
    { &grams, QT_TRANSLATE_NOOP_UTF8( "Units", "g" ) },
    //: The symbol for kilograms (mass)
    { &kilograms, QT_TRANSLATE_NOOP_UTF8( "Units", "kg" ) },

    //: The symbol for pounds (mass)
    { &pounds, QT_TRANSLATE_NOOP_UTF8( "Units", "lbs" ) },

    // Time ===================================================================

    //: The symbol for milliseconds (time)
    { &milliseconds, QT_TRANSLATE_NOOP_UTF8( "Units", "ms" ) },
    //: The symbol for seconds (time)
    { &seconds, QT_TRANSLATE_NOOP_UTF8( "Units", "s" ) },
    //: The symbol for minutes (time)
    { &minutes, QT_TRANSLATE_NOOP_UTF8( "Units", "min" ) },
    //: The symbol for hours (time)
    { &hours, QT_TRANSLATE_NOOP_UTF8( "Units", "hrs" ) },

    // Electric Current =======================================================

    //: The symbol for amperes (electric current)
    { &amperes, QT_TRANSLATE_NOOP_UTF8( "Units", "A" ) },

    // Temperature ============================================================

    //: The symbol for kelvin (temperature)
    { &kelvin, QT_TRANSLATE_NOOP_UTF8( "Units", "K" ) },
    //: The symbol for degrees Celcius (temperature)
    { &celcius, QT_TRANSLATE_NOOP_UTF8( "Units", "°C" ) },

    //: The symbol for degrees Fahrenheit (temperature)
    { &fahrenheit, QT_TRANSLATE_NOOP_UTF8( "Units", "°F" ) },

    // Area ===================================================================

    //: The symbol for square meters (area)
    { &square_meters, QT_TRANSLATE_NOOP_UTF8( "Units", "m²" ) },
    //: The symbol for hectares (area)
    { &hectares, QT_TRANSLATE_NOOP_UTF8( "Units", "ha" ) },

    //: The symbol for acres (area)
    { &acres, QT_TRANSLATE_NOOP_UTF8( "Units", "ac" ) },

    // Volume =================================================================

    //: The symbol for milliliters (volume)
    { &milliliters, QT_TRANSLATE_NOOP_UTF8( "Units", "mL" ) },
    //: The symbol for cubic centimeters (volume)
    { &cubic_centimeters, QT_TRANSLATE_NOOP_UTF8( "Units", "cm³" ) },
    //: The symbol for liters (volume)
    { &liters, QT_TRANSLATE_NOOP_UTF8( "Units", "L" ) },
    //: The symbol for cubic meters (volume)
    { &cubic_meters, QT_TRANSLATE_NOOP_UTF8( "Units", "m³" ) },

    // Angle ==================================================================

    //: The symbol for radians (angle)
    { &radians, QT_TRANSLATE_NOOP_UTF8( "Units", "rad" ) },
    //: The symbol for degrees (angle)
    { &degrees, QT_TRANSLATE_NOOP_UTF8( "Units", "°" ) },

    // Angular Velocity =======================================================

    //: The symbol for radians per second (angular velocity)
    { &radians_per_second, QT_TRANSLATE_NOOP_UTF8( "Units", "rad/s" ) },
    //: The symbol for rotations per minute (angular velocity)
    { &rpm, QT_TRANSLATE_NOOP_UTF8( "Units", "rpm" ) },

    // Ratio ==================================================================

    //: The symbol for percent
    { &percent, QT_TRANSLATE_NOOP_UTF8( "Units", "%" ) }
};

QString Abbr( const Unit& u )
{
    return QCoreApplication::translate( "Units", abbreviation.at( &u ) );
}

} // namespace Units

