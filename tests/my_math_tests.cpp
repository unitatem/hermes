#include "gtest/gtest.h"
#include "my_math.h"

TEST(my_math, success)
{
    ASSERT_TRUE(true);
}

TEST(my_math, add_positive_numbers)
{
    ASSERT_EQ(8.0, add(5.0, 3.0));
}

TEST(my_math, add_real_numbers)
{
    ASSERT_EQ(3.0, add(-4.0, 7.0));
    ASSERT_EQ(0.0, add(0.0, 0.0));
    ASSERT_EQ(-3.0, add(-4.0, 1.0));
    ASSERT_EQ(-3.0, add(-2.0, -1.0));
}