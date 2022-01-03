#include "MyAoC_2021/solutions/Solution_9_1.h"

constexpr const char* genericInput_9_1 = "2199943210\n3987894921\n9856789892\n8767896789\n9899965678";

#include <gtest/gtest.h>

TEST(Solution_9_1Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::SumRiskLevelOfLowPoints(genericInput_9_1), 15); // NOLINT
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}