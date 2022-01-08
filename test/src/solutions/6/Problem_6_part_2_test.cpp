#include <solutions/6/day_6_part_2.h>

constexpr const char* genericInput_6_2 = "3,4,3,1,2";

#include <gtest/gtest.h>

TEST(Solution_6_2Test, CheckGenericValues) // NOLINT
{
    EXPECT_EQ( solutions::CalculateMassiveNumberOfLanternFishAfterNDays( genericInput_6_2, 18UL), 26UL);
    EXPECT_EQ( solutions::CalculateMassiveNumberOfLanternFishAfterNDays( genericInput_6_2, 80UL), 5934UL);
}

TEST(Solution_6_2Test, Massive) // NOLINT
{
    EXPECT_EQ( solutions::CalculateMassiveNumberOfLanternFishAfterNDays( genericInput_6_2, 256), 26984457539);
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}