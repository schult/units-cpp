#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Dimension.h"

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

