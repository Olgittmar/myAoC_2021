#include <solutions/17/day_17_part_1.h>
#include <solutions/17/day_17_part_2.h>

// constexpr const char* genericInput_11 = "";

#include <gtest/gtest.h>

TEST(Solution17Part1Test, CheckGenericValues) // NOLINT
{
	// EXPECT_EQ( solutions::MiddleCompletedScore(genericInput_11), 0); // NOLINT
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}