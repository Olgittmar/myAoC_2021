#include <solutions/8/day_8_part_1.h>
#include <solutions/8/day_8_part_2.h>

constexpr const char* genericInput_8_small = "acedgfb cdfbe gcdfa fbcad dab cefabd cdfgeb eafb cagedb ab | cdfeb fcadb cdfeb cdbaf";
constexpr const char* genericInput_8 =
	"be cfbegad cbdgef fgaecd cgeb fdcge agebfd fecdb fabcd edb | fdgacbe cefdb cefbgd gcbe\n"
	"edbfga begcd cbg gc gcadebf fbgde acbgfd abcde gfcbed gfec | fcgedb cgb dgebacf gc\n"
	"fgaebd cg bdaec gdafb agbcfd gdcbef bgcad gfac gcb cdgabef | cg cg fdcagb cbg\n"
	"fbegcd cbd adcefb dageb afcb bc aefdc ecdab fgdeca fcdbega | efabcd cedba gadfec cb\n"
	"aecbfdg fbg gf bafeg dbefa fcge gcbea fcaegb dgceab fcbdga | gecf egdcabf bgf bfgea\n"
	"fgeab ca afcebg bdacfeg cfaedg gcfdb baec bfadeg bafgc acf | gebdcfa ecba ca fadegcb\n"
	"dbcfg fgd bdegcaf fgec aegbdf ecdfab fbedc dacgb gdcebf gf | cefg dcbef fcge gbcadfe\n"
	"bdfegc cbegaf gecbf dfcage bdacg ed bedf ced adcbefg gebcd | ed bcgafe cdgba cbgef\n"
	"egadfb cdbfeg cegd fecab cgb gbdefca cg fgcdab egfdb bfceg | gbdfcae bgc cg cgb\n"
	"gcafb gcf dcaebfg ecagb gf abcdeg gaef cafbge fdbac fegbdc | fgae cfgab fg bagce";

#include <gtest/gtest.h>

TEST(Solution8Part1Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::GetNumberOfCodesOfUniqueLengthInOutput(genericInput_8_small), 0); // NOLINT
	EXPECT_EQ( solutions::GetNumberOfCodesOfUniqueLengthInOutput(genericInput_8), 26); // NOLINT
}

TEST(Solution8Part2Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::SumOfJumbledCodes(genericInput_8_small), 5353); // NOLINT
	EXPECT_EQ( solutions::SumOfJumbledCodes(genericInput_8), 61229); // NOLINT
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}