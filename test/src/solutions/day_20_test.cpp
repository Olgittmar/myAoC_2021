#include <solutions/20/day_20_part_1.h>
#include <solutions/20/day_20_part_2.h>

// constexpr const char* genericInput_11 = "";

#include <gtest/gtest.h>

TEST(Solution_20_1Test, CheckGenericValues) // NOLINT
{
	// EXPECT_EQ( solutions::MiddleCompletedScore(genericInput_11), 0); // NOLINT
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}