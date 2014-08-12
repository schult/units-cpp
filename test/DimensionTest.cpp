#include "gtest/gtest.h"

#include <type_traits>

#include "Dimension.h"

TEST(DimensionTest, IsLiteralType)
{
    EXPECT_TRUE( std::is_literal_type<Dimension>::value );
}

TEST(DimensionTest, Reduction)
{
    Dimension n =
        FundamentalDimension::MASS *
        FundamentalDimension::MASS *
        FundamentalDimension::MASS;
    Dimension d =
        FundamentalDimension::MASS *
        FundamentalDimension::MASS;

    EXPECT_EQ( n/d, Dimension( FundamentalDimension::MASS ) );
}

