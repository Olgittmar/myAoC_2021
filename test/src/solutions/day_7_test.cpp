#include <solutions/7/day_7_part_1.h>
#include <solutions/7/day_7_part_2.h>

constexpr const char* genericInput_7 = "16,1,2,0,4,2,7,1,2,14";

#include <gtest/gtest.h>

TEST(Solution7Part1Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::CalculateAlignmentOptimalFuelConsumption(genericInput_7), 37);
}

TEST(Solution7Part2Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::CalculateExpensiveAlignmentOptimalFuelConsumption(genericInput_7), 168); // NOLINT
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}