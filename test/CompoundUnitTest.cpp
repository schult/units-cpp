#include "gtest/gtest.h"

#include <cmath>

#include "CompoundValue.h"

TEST(CompoundUnitTest, Dimension)
{
    const CompoundUnit compound1 = simple1 / simple2;
    const CompoundUnit compound2 = simple1 * simple2;

    EXPECT_EQ( compound1.GetDimension(),
        simple1.dimension / simple2.dimension );
    EXPECT_EQ( compound2.GetDimension(),
        simple1.dimension * simple2.dimension );
}

TEST(CompoundUnitTest, Conversion)
{
    const CompoundUnit compound = simple1 / simple2;

    const double base = 1.0;

    const double converted_compound = compound.FromBase( base );
    const double converted_simple = ???;

    const double round_trip_compound = compound.ToBase( converted_compound );
    const double round_trip_simple = ???;

    EXPECT_EQ( converted_compound, converted_simple );
    EXPECT_EQ( round_trip_compound, base );
    EXPECT_EQ( ???, base );
}

TEST(CompoundUnitTest, Foo)
{
    CompoundUnit compound1 = simple1 / simple2;
    CompoundUnit compound2 = simple1 * simple2;
}

