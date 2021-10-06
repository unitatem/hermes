#include "gmock/gmock.h"
#include "gtest/gtest.h"

class MainTest : public ::testing::Test {
 public:
  void SetUp() override {}
};

TEST_F(MainTest, good_weather) { EXPECT_TRUE(true); }

