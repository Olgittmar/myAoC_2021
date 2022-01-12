#include <solutions/10/day_10_part_1.h>
#include <solutions/10/day_10_part_2.h>

constexpr const char* genericInput_10 = "[({(<(())[]>[[{[]{<()<>>\n[(()[<>])]({[<{<<[]>>(\n{([(<{}[<>[]}>{[]{[(<()>\n(((({<>}<{<{<>}{[]{[]{}\n[[<[([]))<([[{}[[()]]]\n[{[{({}]{}}([{[{{{}}([]\n{<[[]]>}<{[{[{[]{()[[[]\n[<(<(<(<{}))><([]([]()\n<{([([[(<>()){}]>(<<{{\n<{([{{}}[<[[[<>{}]]]>[]]";

#include <gtest/gtest.h>

TEST(Solution_10_1Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::SyntaxErrorScoreCorrupted(genericInput_10), 26397); // NOLINT
}

TEST(Solution_10_2Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::MiddleCompletedScore(genericInput_10), 288957ULL); // NOLINT
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}