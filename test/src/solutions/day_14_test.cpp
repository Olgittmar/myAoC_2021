#include <solutions/14/day_14_part_1.h>
#include <solutions/14/day_14_part_2.h>

constexpr const char* genericInput_14 = "NNCB\n\nCH -> B\nHH -> N\nCB -> H\nNH -> C\nHB -> C\nHC -> B\nHN -> C\nNN -> C\nBH -> H\nNC -> B\nNB -> B\nBN -> B\nBB -> N\nBC -> B\nCC -> N\nCN -> C";

#include <gtest/gtest.h>

TEST(Solution_14_1Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::CommonUncommonPolymerDiff(genericInput_14, 10), 1588); // NOLINT
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}