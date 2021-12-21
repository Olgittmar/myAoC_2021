#include "MyAoC_2021/solutions/Solution_3_2.h"

constexpr const char* genericInput_3_2 = "00100\n11110\n10110\n10111\n10101\n01111\n00111\n11100\n10000\n11001\n00010\n01010";

#include <gtest/gtest.h>

TEST(Solution_3_2Test, CheckGenericValues) // NOLINT
{
  EXPECT_EQ( solutions::SubmarineLifeSupportRating(genericInput_3_2), 230);
}

TEST(Solution_3_2Test, CheckBadInput) // NOLINT
{
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}