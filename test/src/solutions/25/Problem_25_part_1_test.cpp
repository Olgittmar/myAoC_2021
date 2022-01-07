#include <25/part_1.h>

// constexpr const char* genericInput_11_1 = "";

#include <gtest/gtest.h>

TEST(Solution_25_1Test, CheckGenericValues) // NOLINT
{
	// EXPECT_EQ( solutions::MiddleCompletedScore(genericInput_11_1), 0); // NOLINT
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}