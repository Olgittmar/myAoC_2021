#include <3/part_1.h>

constexpr const char* genericInput_3_1 = "00100\n11110\n10110\n10111\n10101\n01111\n00111\n11100\n10000\n11001\n00010\n01010";

#include <gtest/gtest.h>

TEST(Solution_3_1Test, CheckGenericValues) // NOLINT
{
  EXPECT_EQ( solutions::SubmarinePowerConsumption(genericInput_3_1), 198);
}

TEST(Solution_3_1Test, CheckBadInput) // NOLINT
{
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}