#include "MyAoC_2021/solutions/Solution_4_2.h"


constexpr const char* genericInput_4_2 = "7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1\n\n22 13 17 11  0\n 8  2 23  4 24\n21  9 14 16  7\n 6 10  3 18  5\n 1 12 20 15 19\n\n 3 15  0  2 22\n 9 18 13 17  5\n19  8  7 25 23\n20 11 10 24  4\n14 21 16 12  6\n\n14 21 17 24  4\n10 16 15  9 19\n18  8 23 26 20\n22 11 13  6  5\n 2  0 12  3  7";

#include <gtest/gtest.h>

TEST(Solution_4_2Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::LoseBingo(genericInput_4_2), 1924);
}

TEST(Solution_4_2Test, CheckBadInput) // NOLINT
{
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}