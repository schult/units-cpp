#include "gtest/gtest.h"

#include <type_traits>

#include "Dimension.h"

TEST(DimensionTest, IsLiteralType)
{
    EXPECT_TRUE( std::is_literal_type<Dimension>::value );
}

TEST(DimensionTest, Reduction)
{
    const Dimension length = FundamentalDimension::LENGTH;
    const Dimension time = FundamentalDimension::TIME;
    const Dimension hertz = Dimension() / FundamentalDimension::TIME;
    const Dimension velocity =
        FundamentalDimension::LENGTH / FundamentalDimension::TIME;

    EXPECT_EQ( velocity / velocity, Dimension() );
    EXPECT_EQ( velocity * time, length );
    EXPECT_EQ( velocity / length, hertz );
    EXPECT_EQ( velocity / hertz, length );
}

