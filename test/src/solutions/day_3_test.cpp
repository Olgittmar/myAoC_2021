#include <solutions/3/day_3_part_1.h>
#include <solutions/3/day_3_part_2.h>

constexpr const char* genericInput_3 = "00100\n11110\n10110\n10111\n10101\n01111\n00111\n11100\n10000\n11001\n00010\n01010";

#include <gtest/gtest.h>

TEST(Solution_3_1Test, CheckGenericValues) // NOLINT
{
  EXPECT_EQ( solutions::SubmarinePowerConsumption(genericInput_3), 198);
}

TEST(Solution_3_2Test, CheckGenericValues) // NOLINT
{
  EXPECT_EQ( solutions::SubmarineLifeSupportRating(genericInput_3), 230);
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}