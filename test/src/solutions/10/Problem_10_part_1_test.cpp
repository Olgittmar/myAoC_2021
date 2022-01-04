#include "MyAoC_2021/solutions/10/part_1.h"

constexpr const char* genericInput_10_1 = "[({(<(())[]>[[{[]{<()<>>\n[(()[<>])]({[<{<<[]>>(\n{([(<{}[<>[]}>{[]{[(<()>\n(((({<>}<{<{<>}{[]{[]{}\n[[<[([]))<([[{}[[()]]]\n[{[{({}]{}}([{[{{{}}([]\n{<[[]]>}<{[{[{[]{()[[[]\n[<(<(<(<{}))><([]([]()\n<{([([[(<>()){}]>(<<{{\n<{([{{}}[<[[[<>{}]]]>[]]";

#include <gtest/gtest.h>

TEST(Solution_10_1Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::SyntaxErrorScoreCorrupted(genericInput_10_1), 26397); // NOLINT
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}