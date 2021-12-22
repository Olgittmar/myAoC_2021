#include "MyAoC_2021/solutions/Solution_6_1.h"

constexpr const char* genericInput_6_1 = "3,4,3,1,2";

#include <gtest/gtest.h>

TEST(Solution_6_1Test, CheckGenericValues) // NOLINT
{
    EXPECT_EQ( solutions::CalculateNumberOfLanternFishAfterNDays( genericInput_6_1, 18), 26);
    EXPECT_EQ( solutions::CalculateNumberOfLanternFishAfterNDays( genericInput_6_1, 80), 5934);
}

TEST(Solution_6_1Test, CheckBadInput) // NOLINT
{
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}