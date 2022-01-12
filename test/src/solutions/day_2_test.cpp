#include <solutions/2/day_2_part_1.h>
#include <solutions/2/day_2_part_2.h>

constexpr const char* genericInput_2_a = "forward 5\ndown 5\nforward 8\nup 3\ndown 8\nforward 2";
constexpr const char* genericInput_2_b = "forward 5\ndown 5\nforward 5\nup 10\nforward 5";
constexpr const char* badInput_2 = "forward 0\ndown 0\nforward 0\nup 0";
#include <gtest/gtest.h>

TEST(Solution_2_1Test, CheckGenericValues) // NOLINT
{
    EXPECT_EQ( solutions::SubmarineNavigationProduct(genericInput_2_a), 150 );
}

TEST(Solution_2_1Test, CheckBadInput) // NOLINT
{
    EXPECT_EQ( solutions::SubmarineNavigationProduct(badInput_2), 0 );
}

TEST(Solution_2_2Test, CheckGenericValues) // NOLINT
{
  EXPECT_EQ(solutions::SubmarineAdvancedNavigationProduct(genericInput_2_a), 900);
  EXPECT_EQ(solutions::SubmarineAdvancedNavigationProduct(genericInput_2_b), 0);
}

TEST(Solution_2_2Test, CheckBadInput) // NOLINT
{
  EXPECT_EQ(solutions::SubmarineAdvancedNavigationProduct(badInput_2), 0);
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}