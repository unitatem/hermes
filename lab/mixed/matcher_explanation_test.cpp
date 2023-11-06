#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Solution {
 public:
};

class MatcherTest : public ::testing::Test {
 public:
  void SetUp() override {}
};

TEST_F(MatcherTest, DISABLED_good_weather) { EXPECT_TRUE(false); }
