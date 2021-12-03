#include "MyAoC_2021/solutions/Solution_2_1.h"

#define genericInput_2_1 "forward 5\ndown 5\nforward 8\nup 3\ndown 8\nforward 2"

#include <gtest/gtest.h>

TEST(Solution_2_1Test, CheckGenericValues)
{
    EXPECT_EQ( solutions::SubmarineNavigationProduct(genericInput_2_1), 150 );
}

TEST(Solution_2_1Test, CheckBadInput)
{
    EXPECT_EQ( solutions::SubmarineNavigationProduct("forward 0\ndown 0\nforward 0\nup 0"), 0 );
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}