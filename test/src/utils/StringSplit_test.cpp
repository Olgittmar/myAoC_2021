#include <StringSplit.h>

#include <vector>
#include <string>

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

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
