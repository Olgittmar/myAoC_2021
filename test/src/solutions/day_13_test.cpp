#include <solutions/13/day_13_part_1.h>
#include <solutions/13/day_13_part_2.h>

constexpr const char* genericInput_13 = "6,10\n0,14\n9,10\n0,3\n10,4\n4,11\n6,0\n6,12\n4,1\n0,13\n10,12\n3,4\n3,0\n8,4\n1,10\n2,14\n8,10\n9,0\n\nfold along y=7\nfold along x=5";

#include <gtest/gtest.h>

TEST(Solution13Part1Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::DotsVisibleAfterNFolds(genericInput_13, 1), 17); // NOLINT
}

// No idea how to test this?
TEST(Solution13Part2Test, CheckGenericValues) // NOLINT
{
	std::string _ret{};
	EXPECT_NO_FATAL_FAILURE( _ret = solutions::PrintCodeFromDottedPaper(genericInput_13, 0) ); // NOLINT
	std::cout << _ret;
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}