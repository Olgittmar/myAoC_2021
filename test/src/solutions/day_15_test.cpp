#include <solutions/15/day_15_part_1.h>
#include <solutions/15/day_15_part_2.h>

constexpr const char* genericInput_15 = "1163751742\n1381373672\n2136511328\n3694931569\n7463417111\n1319128137\n1359912421\n3125421639\n1293138521\n2311944581";

#include <gtest/gtest.h>

TEST(Solution15Part1Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::RiskValueOfLeastRiskyPath(genericInput_15), 40); // NOLINT
}

TEST(Solution15Part2Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::RiskValueOfLeastRiskyPathThroughLargeMap(genericInput_15), 315); // NOLINT
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}