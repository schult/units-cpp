#include "gtest/gtest.h"

#include <cmath>

#include "DimensionedValue.h"

template<int multiplier, int divisor>
static constexpr double Scale( double val )
{
    return val * multiplier / divisor;
}
#define SCALE(a, b) Scale<a, b>, Scale<b, a>

class DimensionedValueTest : public ::testing::Test {
protected:
    DimensionedValueTest() :
        length_units1( FundamentalDimension::LENGTH ),
        length_units2( FundamentalDimension::LENGTH, SCALE( 2, 1 ) ),
        time_units1( FundamentalDimension::TIME ),
        area_units2(
            FundamentalDimension::LENGTH * FundamentalDimension::LENGTH,
            SCALE( 2, 1 ) ),
        velocity_units2(
            FundamentalDimension::LENGTH / FundamentalDimension::TIME,
            SCALE( 2, 1 ) )
    {
    }

    const Unit length_units1;
    const Unit length_units2;

    const Unit time_units1;

    const Unit area_units2;
    const Unit velocity_units2;
};

TEST_F(DimensionedValueTest, Conversion)
{
    const double n = 5;
    DimensionedValue val_a( n, length_units1 );
    EXPECT_EQ( val_a.As( length_units1 ), n );
    EXPECT_EQ( val_a.As( length_units2 ), n / 2.0 );

    DimensionedValue val_b( n, length_units2 );
    EXPECT_EQ( val_b.As( length_units2 ), n );
    EXPECT_EQ( val_b.As( length_units1 ), 2.0 * n );
}

TEST_F(DimensionedValueTest, IncompatibleDimensions)
{
    DimensionedValue val_a( 1, length_units1 );
    DimensionedValue val_b( 1, time_units1 );

    EXPECT_TRUE( val_a != val_b );
    EXPECT_FALSE( val_a == val_b );
    EXPECT_FALSE( val_a < val_b );
    EXPECT_FALSE( val_a > val_b );
    EXPECT_FALSE( val_a <= val_b );
    EXPECT_FALSE( val_a >= val_b );

    EXPECT_TRUE( std::isnan( val_a.As( time_units1 ) ) );
    EXPECT_TRUE( std::isnan( (val_a + val_b).As( length_units1 ) ) );
    EXPECT_TRUE( std::isnan( (val_a + val_b).As( time_units1 ) ) );
    EXPECT_TRUE( std::isnan( (val_a - val_b).As( length_units1 ) ) );
    EXPECT_TRUE( std::isnan( (val_a - val_b).As( time_units1 ) ) );
    EXPECT_TRUE( std::isnan( (val_a * val_b).As( length_units1 ) ) );
    EXPECT_TRUE( std::isnan( (val_a * val_b).As( time_units1 ) ) );
    EXPECT_TRUE( std::isnan( (val_a / val_b).As( length_units1 ) ) );
    EXPECT_TRUE( std::isnan( (val_a / val_b).As( time_units1 ) ) );
}

TEST_F(DimensionedValueTest, Arithmetic)
{
    const double a = 5;
    const double b = 2;
    const double c = 2;
    DimensionedValue val_a( a, length_units1 );
    DimensionedValue val_b( b, length_units2 );
    DimensionedValue val_c( c, time_units1 );

    EXPECT_EQ( (-val_b).As( length_units1 ), -(2.0 * b) );
    EXPECT_EQ( (val_a + val_a).As( length_units2 ), (a+a) / 2.0 );
    EXPECT_EQ( (val_a - val_b).As( length_units1 ), a - (2.0 * b) );
    EXPECT_EQ( (val_a * val_a).As( area_units2 ), (a*a) / 2.0 );
    EXPECT_EQ( (val_a / val_c).As( velocity_units2 ), (a/c) / 2.0 );
}

