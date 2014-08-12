#include "gtest/gtest.h"

#include <type_traits>

#include "Dimension.h"

TEST(DimensionTest, IsLiteralType)
{
    EXPECT_EQ( std::is_literal_type<Dimension>::value, 1 );
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

