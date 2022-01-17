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


auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
