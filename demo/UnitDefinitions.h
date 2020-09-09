#ifndef UNITS_UNIT_DEFINITIONS_H
#define UNITS_UNIT_DEFINITIONS_H

#include <QString>

#include "CompoundUnit.h"
#include "Unit.h"

namespace Units
{

// Get a unit's symbol translated into the current locale.
QString Translate( const Unit& u );
QString Translate( const CompoundUnit& u );

// Length (meters) ============================================================

extern const Unit millimeters;
extern const Unit centimeters;
extern const Unit meters;
extern const Unit kilometers;

extern const Unit inches;
extern const Unit feet;
extern const Unit yards;
extern const Unit miles;

// Mass (kilograms) ===========================================================

extern const Unit grams;
extern const Unit kilograms;

extern const Unit pounds;

// Time (seconds) =============================================================

extern const Unit milliseconds;
extern const Unit seconds;
extern const Unit minutes;
extern const Unit hours;

// Electric Current (amperes) =================================================

extern const Unit amperes;

// Temperature (kelvin) =======================================================

extern const Unit kelvin;
extern const Unit celcius;

extern const Unit fahrenheit;

// Area (square meters) =======================================================

extern const Unit square_meters;
extern const Unit hectares;

extern const Unit acres;

// Volume (cubic meters) ======================================================

extern const Unit milliliters;
extern const Unit cubic_centimeters;
extern const Unit liters;
extern const Unit cubic_meters;

// Angle (radians) ============================================================

extern const Unit radians;
extern const Unit degrees;

// Angular Velocity (radians per second) ======================================

extern const Unit radians_per_second;
extern const Unit rpm;

// Ratio ======================================================================

extern const Unit percent;

} // namespace Units

#endif // UNITS_UNIT_DEFINITIONS_H

