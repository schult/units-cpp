#include "UnitText.h"

#include <unordered_map>

#include "UnitDefinitions.h"

namespace Units
{

static const std::unordered_map<const Unit *, const char *> abbreviation = {
    // Length =================================================================

    { &millimeters, "mm" },
    { &centimeters, "cm" },
    { &meters, "m" },
    { &kilometers, "km" },

    { &inches, "in" },
    { &feet, "ft" },
    { &yards, "yd" },
    { &miles, "mi" },

    // Mass ===================================================================

    { &grams, "g" },
    { &kilograms, "kg" },

    { &pounds, "lbs" },

    // Time ===================================================================

    { &milliseconds, "ms" },
    { &seconds, "s" },
    { &minutes, "min" },
    { &hours, "hrs" },

    // Electric Current =======================================================

    { &amperes, "A" },

    // Temperature ============================================================

    { &kelvin, "K" },
    { &celcius, "°C" },

    { &fahrenheit, "°F" },

    // Area ===================================================================

    { &square_meters, "m²" },
    { &hectares, "ha" },

    { &acres, "ac" },

    // Volume =================================================================

    { &milliliters, "mL" },
    { &cubic_centimeters, "cm³" },
    { &liters, "L" },
    { &cubic_meters, "m³" },

    // Angle ==================================================================

    { &radians, "rad" },
    { &degrees, "°" },

    // Angular Velocity =======================================================

    { &radians_per_second, "rad/s" },
    { &rpm, "rpm" }
};

const char *Abbr( const Unit& u, int n )
{
    (void)n; // This is for doing fancy translation tricks.
    return abbreviation.at( &u );
}

} // namespace Units

