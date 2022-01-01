#include "MyAoC_2021/utils/myMath.h"

#include <gtest/gtest.h>

TEST(MyMathTest, PowerOfTen) // NOLINT
{
	EXPECT_EQ( utils::IntPowBase10(0), 1);
	EXPECT_EQ( utils::IntPowBase10(1), 10);
	EXPECT_EQ( utils::IntPowBase10(2), 100);
	EXPECT_EQ( utils::IntPowBase10(3), 1000);
	EXPECT_EQ( utils::IntPowBase10(4), 10000);
	EXPECT_EQ( utils::IntPowBase10(5), 100000);
	EXPECT_EQ( utils::IntPowBase10(6), 1000000);
	EXPECT_EQ( utils::IntPowBase10(7), 10000000);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
