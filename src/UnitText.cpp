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

    // Mass (kilograms) =======================================================

    { &grams, "g" },
    { &kilograms, "kg" },

    { &pounds, "lbs" },

    // Time (seconds) =========================================================

    { &milliseconds, "ms" },
    { &seconds, "s" },
    { &minutes, "min" },
    { &hours, "hrs" },

    // Electric Current (amperes) =============================================

    { &amperes, "A" },

    // Temperature (kelvin) ===================================================

    { &kelvin, "K" },
    { &celcius, "°C" },

    { &fahrenheit, "°F" }
};

const char *Abbr( const Unit& u, int n )
{
    (void)n; // This is for doing fancy translation tricks.
    return abbreviation.at( &u );
}

} // namespace Units

