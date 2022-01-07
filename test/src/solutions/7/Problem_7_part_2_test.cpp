#include <7/part_2.h>

constexpr const char* genericInput_7_2 = "16,1,2,0,4,2,7,1,2,14";

#include <gtest/gtest.h>

TEST(Solution_7_2Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::CalculateExpensiveAlignmentOptimalFuelConsumption(genericInput_7_2), 168); // NOLINT
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}