#include <solutions/14/day_14_part_1.h>
#include <solutions/14/day_14_part_2.h>

constexpr const char* genericInput_14 = "NNCB\n\nCH -> B\nHH -> N\nCB -> H\nNH -> C\nHB -> C\nHC -> B\nHN -> C\nNN -> C\nBH -> H\nNC -> B\nNB -> B\nBN -> B\nBB -> N\nBC -> B\nCC -> N\nCN -> C";

#include <gtest/gtest.h>

TEST(Solution14Part1Test, CheckAfterOneStep) // NOLINT
{
	EXPECT_EQ( solutions::CommonUncommonPolymerDiff(genericInput_14, 1), 1); // NOLINT
}

TEST(Solution14Part1Test, CheckAfterTwoSteps) // NOLINT
{
	EXPECT_EQ( solutions::CommonUncommonPolymerDiff(genericInput_14, 2), 5); // NOLINT
}

TEST(Solution14Part1Test, CheckAfterThreeSteps) // NOLINT
{
	EXPECT_EQ( solutions::CommonUncommonPolymerDiff(genericInput_14, 3), 7); // NOLINT
}

TEST(Solution14Part1Test, CheckAfterFourSteps) // NOLINT
{
	EXPECT_EQ( solutions::CommonUncommonPolymerDiff(genericInput_14, 4), 18); // NOLINT
}

TEST(Solution14Part1Test, CheckAfterTenSteps) // NOLINT
{
	EXPECT_EQ( solutions::CommonUncommonPolymerDiff(genericInput_14, 10), 1588); // NOLINT
}

TEST(Solution14Part2Test, CheckAfterFortySteps) // NOLINT
{
	EXPECT_EQ( solutions::CommonUncommonPolymerDiff(genericInput_14, 40), 2188189693529L); // NOLINT
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}