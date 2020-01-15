#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <vector>
#include <string>

using ::testing::UnorderedElementsAre;

TEST(mtest, success)
{
    ASSERT_TRUE(true);
}

TEST(mtest, elementsAre_int)
{
    // Set
    std::vector<int> v{5, 10, 15};

    // Test
    EXPECT_THAT(v, UnorderedElementsAre(15, 10, 5));
}


TEST(mtest, elementsAre_string)
{
    // Set
    std::vector<std::string> names{"Alan", "Bart", "Charlie"};

    // Test
    EXPECT_THAT(names, UnorderedElementsAre("Alan", "Bart"));
}
