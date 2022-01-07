#include <2/part_1.h>

constexpr const char* genericInput_2_1 = "forward 5\ndown 5\nforward 8\nup 3\ndown 8\nforward 2";
constexpr const char* badInput_2_1 = "forward 0\ndown 0\nforward 0\nup 0";
#include <gtest/gtest.h>

TEST(Solution_2_1Test, CheckGenericValues) // NOLINT
{
    EXPECT_EQ( solutions::SubmarineNavigationProduct(genericInput_2_1), 150 );
}

TEST(Solution_2_1Test, CheckBadInput) // NOLINT
{
    EXPECT_EQ( solutions::SubmarineNavigationProduct(badInput_2_1), 0 );
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}