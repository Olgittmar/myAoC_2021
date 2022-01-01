#include "MyAoC_2021/solutions/Solution_7_1.h"

constexpr const char* genericInput_7_1 = "16,1,2,0,4,2,7,1,2,14";

#include <gtest/gtest.h>

TEST(Solution_7_1Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::CalculateAlignmentOptimalFuelConsumption(genericInput_7_1), 37);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}