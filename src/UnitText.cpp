#include "UnitText.h"

#include <unordered_map>

#include "UnitDefinitions.h"

namespace Units
{

static const std::unordered_map<const Unit *, const char *> abbreviation = {
    // Length =================================================================
    { &miles, "mi" },
    { &yards, "yd" },
    { &feet, "ft" },
    { &inches, "in" },
    { &kilometers, "km" },
    { &meters, "m" },
    { &centimeters, "cm" },
    { &millimeters, "mm" }
};

const char *Abbr( const Unit& u, int n )
{
    (void)n; // This is for doing fancy translation tricks.
    return abbreviation.at( &u );
}

} // namespace Units

