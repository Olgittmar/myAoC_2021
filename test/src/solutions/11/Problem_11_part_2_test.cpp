#include <solutions/11/day_11_part_2.h>

constexpr const char* genericInput_11_2 = "5483143223\n2745854711\n5264556173\n6141336146\n6357385478\n4167524645\n2176841721\n6882881134\n4846848554\n5283751526";

#include <gtest/gtest.h>

TEST(Solution_11_2Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::PredictSynchronizedFlash(genericInput_11_2, 1000), 195); // NOLINT
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}