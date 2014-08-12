#include "gtest/gtest.h"

#include <type_traits>

#include "Unit.h"

TEST(UnitTest, IsLiteralType)
{
    EXPECT_TRUE( std::is_literal_type<Unit>::value );
}

