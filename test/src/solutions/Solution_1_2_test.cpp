#include "MyAoC_2021/solutions/Solution_1_2.h"

#include <gtest/gtest.h>

#define genericInput_1_2 "199\n200\n208\n210\n200\n207\n240\n269\n260\n263"

TEST(Solution_1_2Test, CheckBadInput)
{
    EXPECT_EQ(solutions::CountIncreasingSlidingWindow(""), 0);
    EXPECT_EQ(solutions::CountIncreasingSlidingWindow("1"), 0);
    EXPECT_EQ(solutions::CountIncreasingSlidingWindow("1 2"), 0);
}

TEST(Solution_1_2Test, CheckGenericValues)
{
    EXPECT_EQ(solutions::CountIncreasingSlidingWindow("2\n3\n4\n2\n1\n1"), 0);
    EXPECT_EQ(solutions::CountIncreasingSlidingWindow("1\n2\n3\n4\n5\n1"), 2);
    EXPECT_EQ(solutions::CountIncreasingSlidingWindow(genericInput_1_2), 5);
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
