#include <1/part_2.h>

#include <gtest/gtest.h>

constexpr const char* genericInput_1_2 = "199\n200\n208\n210\n200\n207\n240\n269\n260\n263";

TEST(Solution_1_2Test, CheckBadInput) // NOLINT
{
	constexpr std::string_view str1{};
	constexpr std::string_view str2{"1"};
	constexpr std::string_view str3{"1 2"};

    EXPECT_EQ(solutions::CountIncreasingSlidingWindow(str1), 0);
    EXPECT_EQ(solutions::CountIncreasingSlidingWindow(str2), 0);
    EXPECT_EQ(solutions::CountIncreasingSlidingWindow(str3), 0);
}

TEST(Solution_1_2Test, CheckGenericValues) // NOLINT
{
	constexpr std::string_view str1{"2\n3\n4\n2\n1\n1"};
	constexpr std::string_view str2{"1\n2\n3\n4\n5\n1"};

    EXPECT_EQ(solutions::CountIncreasingSlidingWindow(str1), 0);
    EXPECT_EQ(solutions::CountIncreasingSlidingWindow(str2), 2);
    EXPECT_EQ(solutions::CountIncreasingSlidingWindow(genericInput_1_2), 5);
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
