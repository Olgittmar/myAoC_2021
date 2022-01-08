#include <solutions/9/day_9_part_1.h>

constexpr const char* genericInput_9_1 = "2199943210\n3987894921\n9856789892\n8767896789\n9899965678";

#include <gtest/gtest.h>

TEST(Solution_9_1Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::SumRiskLevelOfLowPoints(genericInput_9_1), 15); // NOLINT
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}