#include "MyAoC_2021/solutions/Solution_2_2.h"

#define genericInput_2_2 "forward 5\ndown 5\nforward 8\nup 3\ndown 8\nforward 2"
#define genericInput_2_2_b "forward 5\ndown 5\nforward 5\nup 10\nforward 5"

#include <gtest/gtest.h>

TEST(Solution_2_2Test, CheckGenericValues)
{
  EXPECT_EQ(solutions::SubmarineAdvancedNavigationProduct(genericInput_2_2), 900);
  EXPECT_EQ(solutions::SubmarineAdvancedNavigationProduct(genericInput_2_2_b), 0);
}

TEST(Solution_2_2Test, CheckBadInput)
{
  EXPECT_EQ(solutions::SubmarineAdvancedNavigationProduct("forwar\nup\ndown\nforward"), 0);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}