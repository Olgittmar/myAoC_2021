#include <solutions/5/day_5_part_1.h>
#include <solutions/5/day_5_part_2.h>

constexpr const char* genericInput_5 = "0,9 -> 5,9\n8,0 -> 0,8\n9,4 -> 3,4\n2,2 -> 2,1\n7,0 -> 7,4\n6,4 -> 2,0\n0,9 -> 2,9\n3,4 -> 1,4\n0,0 -> 8,8\n5,5 -> 8,2";

#include <gtest/gtest.h>

TEST(Solution5Part1Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ(solutions::NumberOfOverlappingVentlinePoints(genericInput_5), 5);
}

TEST(Solution5Part2Test, CheckGenericValues) // NOLINT
{
  EXPECT_EQ( solutions::NumberOfOverlappingVentlinePointsIncludingDiagonals(genericInput_5), 12);
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}