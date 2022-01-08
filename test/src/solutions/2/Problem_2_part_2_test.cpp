#include <solutions/2/day_2_part_2.h>

constexpr const char* genericInput_2_2 = "forward 5\ndown 5\nforward 8\nup 3\ndown 8\nforward 2";
constexpr const char* genericInput_2_2_b = "forward 5\ndown 5\nforward 5\nup 10\nforward 5";
constexpr const char* badInput_2_2 = "forwar\nup\ndown\nforward";

#include <gtest/gtest.h>

TEST(Solution_2_2Test, CheckGenericValues) // NOLINT
{
  EXPECT_EQ(solutions::SubmarineAdvancedNavigationProduct(genericInput_2_2), 900);
  EXPECT_EQ(solutions::SubmarineAdvancedNavigationProduct(genericInput_2_2_b), 0);
}

TEST(Solution_2_2Test, CheckBadInput) // NOLINT
{
  EXPECT_EQ(solutions::SubmarineAdvancedNavigationProduct(badInput_2_2), 0);
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}