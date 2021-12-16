#include "MyAoC_2021/solutions/Solution_5_1.h"

#define genericInput_5_1 "0,9 -> 5,9\n8,0 -> 0,8\n9,4 -> 3,4\n2,2 -> 2,1\n7,0 -> 7,4\n6,4 -> 2,0\n0,9 -> 2,9\n3,4 -> 1,4\n0,0 -> 8,8\n5,5 -> 8,2"

#include <gtest/gtest.h>

TEST(Solution_5_1Test, CheckGenericValues)
{
	EXPECT_EQ(solutions::NumberOfOverlappingVentlinePoints(genericInput_5_1), 5);
}

TEST(Solution_5_1Test, CheckBadInput)
{
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}