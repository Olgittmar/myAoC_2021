#include "MyAoC_2021/solutions/9/part_2.h"

constexpr const char* genericInput_9_2 = "2199943210\n3987894921\n9856789892\n8767896789\n9899965678";

#include <gtest/gtest.h>

TEST(Solution_9_2Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::ProductOfLargestBasinSizes(genericInput_9_2, 3), 1134); // NOLINT
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}