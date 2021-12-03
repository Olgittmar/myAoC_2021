#include "MyAoC_2021/utils/StringSplit.h"

#include <vector>
#include <string>

#include <gtest/gtest.h>


TEST(SplitStringTest, CheckEmptyString)
{
  EXPECT_EQ( utils::SplitString("", '\n'), std::vector<std::string>() );
}

TEST(SplitStringTest, CheckGenericValues)
{
  EXPECT_EQ( utils::SplitString("1\n2\n3\n2", '\n'), std::vector<std::string>({"1", "2", "3", "2"}) );
  EXPECT_EQ( utils::SplitString("1 2 3 2", ' '), std::vector<std::string>({"1", "2", "3", "2"}) );
  EXPECT_EQ( utils::SplitString("1,2,3,2", ','), std::vector<std::string>({"1", "2", "3", "2"}) );
}

TEST(SplitStringToIntTest, CheckEmptyString)
{
  EXPECT_EQ( utils::SplitStringToInt("", '\n'), std::vector<int>() );
}

TEST(SplitStringToIntTest, CheckGenericValues)
{
  EXPECT_EQ( utils::SplitStringToInt("1\n2\n3\n2", '\n'), std::vector<int>({1,2,3,2}) );
  EXPECT_EQ( utils::SplitStringToInt("1 2 3 2", ' '), std::vector<int>({1,2,3,2}) );
  EXPECT_EQ( utils::SplitStringToInt("1,2,3,2", ','), std::vector<int>({1,2,3,2}) );
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
