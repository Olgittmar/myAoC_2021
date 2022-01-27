#include <utils.h>

#include <string>
#include <vector>

#include <gtest/gtest.h>


TEST(SplitStringTest, CheckEmptyString) // NOLINT
{
  EXPECT_EQ( utils::SplitString("", '\n'), std::vector<std::string_view>() );
}

TEST(SplitStringTest, CheckGenericValues) // NOLINT
{
  EXPECT_EQ( utils::SplitString("1\n2\n3\n2", '\n'), std::vector<std::string_view>({"1", "2", "3", "2"}) );
  EXPECT_EQ( utils::SplitString("1 2 3 2", ' '), std::vector<std::string_view>({"1", "2", "3", "2"}) );
  EXPECT_EQ( utils::SplitString("1,2,3,2", ','), std::vector<std::string_view>({"1", "2", "3", "2"}) );
  EXPECT_EQ( utils::SplitString(",1,2,3,2", ',', false), std::vector<std::string_view>({"", "1", "2", "3", "2"}) );
  EXPECT_EQ( utils::SplitString(",1,2,3,2", ',', true), std::vector<std::string_view>({"1", "2", "3", "2"}) );
  EXPECT_EQ( utils::SplitString("1, 2,\n3, 2", ','), std::vector<std::string_view>({"1", " 2", "\n3", " 2"}) );
}


TEST(SplitStringStringDelimiterTest, CheckEmptyString) // NOLINT
{
  EXPECT_EQ( utils::SplitString("", " fisk "), std::vector<std::string_view>({""}) );
}

TEST(SplitStringStringDelimiterTest, CheckGenericValues) // NOLINT
{
  EXPECT_EQ( utils::SplitString("1\n\n2\n\n3\n\n2", "\n\n"), std::vector<std::string_view>({"1", "2", "3", "2"}) );
  EXPECT_EQ( utils::SplitString("1 fisk 2 fisk 3 fisk 2", " fisk "), std::vector<std::string_view>({"1", "2", "3", "2"}) );
  EXPECT_EQ( utils::SplitString("1,,,2,,,3,,,2", ",,,"), std::vector<std::string_view>({"1", "2", "3", "2"}) );
  EXPECT_EQ( utils::SplitString(",1,2,3,2", ","), std::vector<std::string_view>({"", "1", "2", "3", "2"}) );
  EXPECT_EQ( utils::SplitString("1\t  \n, 2,\t  \n,\n3, \t 2\n,", "\t  \n,"), std::vector<std::string_view>({"1", " 2,", "\n3, \t 2\n,"}) );
}

TEST(SplitStringToIntTest, CheckEmptyString) // NOLINT
{
  EXPECT_EQ( utils::SplitStringToInt("", '\n'), std::vector<int>() );
}

TEST(SplitStringToIntTest, CheckGenericValues) // NOLINT
{
  EXPECT_EQ( utils::SplitStringToInt("1\n2\n3\n2", '\n'), std::vector<int>({1,2,3,2}) );
  EXPECT_EQ( utils::SplitStringToInt("1 2 3 2", ' '), std::vector<int>({1,2,3,2}) );
  EXPECT_EQ( utils::SplitStringToInt("1,2,3,2", ','), std::vector<int>({1,2,3,2}) );
  EXPECT_EQ( utils::SplitStringToInt("1 , 2,\n3,\n2", ','), std::vector<int>({1,2,3,2}) );
}


TEST(SplitStringToULongTest, CheckGenericValues) // NOLINT
{
  EXPECT_EQ( utils::SplitStringToULong("1\n2\n3\n2", '\n'), std::vector<ulong>({1UL, 2UL, 3UL, 2UL}) );
  EXPECT_EQ( utils::SplitStringToULong("1 2 3 2", ' '), std::vector<ulong>({1UL, 2UL, 3UL, 2UL}) );
  EXPECT_EQ( utils::SplitStringToULong("1,2,3,2", ','), std::vector<ulong>({1UL, 2UL, 3UL, 2UL}) );
  EXPECT_EQ( utils::SplitStringToULong("1 , 2,\n3,\n2", ','), std::vector<ulong>({1UL, 2UL, 3UL, 2UL}) );
}


TEST(StringViewToIntTest, CheckBase10) // NOLINT
{
  EXPECT_EQ( utils::StringViewToInt("1234567890"), int(1234567890) );
  EXPECT_EQ( utils::StringViewToInt("1234567890", 10), int(1234567890) );
  EXPECT_EQ( utils::StringViewToInt("1", 10), int(1) );
  EXPECT_EQ( utils::StringViewToInt("0000000", 10), int(0) );
}

TEST(StringViewToIntTest, CheckBase2) // NOLINT
{
  EXPECT_EQ( utils::StringViewToInt("1", 2), int(1) );
  EXPECT_EQ( utils::StringViewToInt("10", 2), int(2) );
  EXPECT_EQ( utils::StringViewToInt("101", 2), int(5) );
  EXPECT_EQ( utils::StringViewToInt("1011011010111010101010110101011", 2), int(1532843435) );
  EXPECT_EQ( utils::StringViewToInt("0000000", 2), int(0) );
}

TEST(StringViewToULongTest, CheckBase10) // NOLINT
{
  EXPECT_EQ( utils::StringViewToULong("1234567890"), ulong(1234567890) );
  EXPECT_EQ( utils::StringViewToULong("1234567890", 10), ulong(1234567890) );
  EXPECT_EQ( utils::StringViewToULong("1", 10), ulong(1) );
  EXPECT_EQ( utils::StringViewToULong("0000000", 10), ulong(0) );
}

TEST(StringViewToULongTest, CheckBase2) // NOLINT
{
  EXPECT_EQ( utils::StringViewToULong("1", 2), ulong(1) );
  EXPECT_EQ( utils::StringViewToULong("10", 2), ulong(2) );
  EXPECT_EQ( utils::StringViewToULong("101", 2), ulong(5) );
  EXPECT_EQ( utils::StringViewToULong("1011011010111010101010110101011", 2), ulong(1532843435) );
  EXPECT_EQ( utils::StringViewToULong("0000000", 2), ulong(0) );
}


auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
