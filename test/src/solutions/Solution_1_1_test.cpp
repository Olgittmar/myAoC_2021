#include "MyAoC_2021/solutions/Solution_1_1.h"

#define genericInput_1_1 "199\n200\n208\n210\n200\n207\n240\n269\n260\n263"

#include <gtest/gtest.h>

TEST(Solution_1_1Test, CheckGenericValues)
{
  EXPECT_EQ( solutions::CountNumIncreasing("1\n2\n3\n2"), 2 );
  EXPECT_EQ( solutions::CountNumIncreasing("1\n2\n3\n4"), 3 );
  EXPECT_EQ( solutions::CountNumIncreasing("4\n3\n2\n1"), 0 );
  EXPECT_EQ( solutions::CountNumIncreasing("1\n5\n2\n6"), 2 );
  EXPECT_EQ( solutions::CountNumIncreasing(genericInput_1_1), 7 );
}

TEST(Solution_1_1Test, CheckBadInput)
{
  EXPECT_EQ( solutions::CountNumIncreasing(""), 0 );
  EXPECT_EQ( solutions::CountNumIncreasing("1"), 0 );
  EXPECT_EQ( solutions::CountNumIncreasing("1\n2"), 1 );
  EXPECT_EQ( solutions::CountNumIncreasing("2\n1"), 0 );
  EXPECT_EQ( solutions::CountNumIncreasing("3\n3"), 0 );
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
