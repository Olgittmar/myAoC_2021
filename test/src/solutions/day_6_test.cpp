#include <solutions/6/day_6_part_1.h>
#include <solutions/6/day_6_part_2.h>

constexpr const char* genericInput_6 = "3,4,3,1,2";

#include <gtest/gtest.h>

TEST(Solution_6_1Test, CheckGenericValues) // NOLINT
{
    EXPECT_EQ( solutions::CalculateNumberOfLanternFishAfterNDays( genericInput_6, 18), 26);
    EXPECT_EQ( solutions::CalculateNumberOfLanternFishAfterNDays( genericInput_6, 80), 5934);
}

TEST(Solution_6_2Test, CheckGenericValues) // NOLINT
{
    EXPECT_EQ( solutions::CalculateMassiveNumberOfLanternFishAfterNDays( genericInput_6, 18UL), 26UL);
    EXPECT_EQ( solutions::CalculateMassiveNumberOfLanternFishAfterNDays( genericInput_6, 80UL), 5934UL);
}

TEST(Solution_6_2Test, Massive) // NOLINT
{
    EXPECT_EQ( solutions::CalculateMassiveNumberOfLanternFishAfterNDays( genericInput_6, 256UL), 26984457539);
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}