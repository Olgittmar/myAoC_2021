#include <solutions/1/day_1_part_1.h>
#include <solutions/1/day_1_part_2.h>

constexpr const char* genericInput_1 = "199\n200\n208\n210\n200\n207\n240\n269\n260\n263";

#include <gtest/gtest.h>

#include <utils/utils.h>

TEST(Solution_1_1Test, CheckGenericValues) // NOLINT
{
  constexpr std::string_view str1{"1\n2\n3\n2"};
  constexpr std::string_view str2{"1\n2\n3\n4"};
  constexpr std::string_view str3{"4\n3\n2\n1"};
  constexpr std::string_view str4{"1\n5\n2\n6"};

  EXPECT_EQ( solutions::CountNumIncreasing(str1), 2 );
  EXPECT_EQ( solutions::CountNumIncreasing(str2), 3 );
  EXPECT_EQ( solutions::CountNumIncreasing(str3), 0 );
  EXPECT_EQ( solutions::CountNumIncreasing(str4), 2 );
  EXPECT_EQ( solutions::CountNumIncreasing(genericInput_1), 7 );
}

TEST(Solution_1_1Test, CheckBadInput) // NOLINT
{
  constexpr std::string_view str1{};
  constexpr std::string_view str2{"1"};
  constexpr std::string_view str3{"1\n2"};
  constexpr std::string_view str4{"2\n1"};
  constexpr std::string_view str5{"3\n3"};
  
  EXPECT_EQ( solutions::CountNumIncreasing(str1), 0 );
  EXPECT_EQ( solutions::CountNumIncreasing(str2), 0 );
  EXPECT_EQ( solutions::CountNumIncreasing(str3), 1 );
  EXPECT_EQ( solutions::CountNumIncreasing(str4), 0 );
  EXPECT_EQ( solutions::CountNumIncreasing(str5), 0 );
}

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
    EXPECT_EQ(solutions::CountIncreasingSlidingWindow(genericInput_1), 5);
}


auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
