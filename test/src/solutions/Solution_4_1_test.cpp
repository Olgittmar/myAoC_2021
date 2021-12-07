#include "MyAoC_2021/solutions/Solution_4_1.h"

#define genericInput_4_1 "7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1\n\n22 13 17 11  0\n 8  2 23  4 24\n21  9 14 16  7\n 6 10  3 18  5\n 1 12 20 15 19\n\n 3 15  0  2 22\n 9 18 13 17  5\n19  8  7 25 23\n20 11 10 24  4\n14 21 16 12  6\n\n14 21 17 24  4\n10 16 15  9 19\n18  8 23 26 20\n22 11 13  6  5\n 2  0 12  3  7"
#define declareTestBoard solutions::BingoBoard testBoard({\
		"22 13 17 11  0",\
		"8  2 23  4 24",\
		"21  9 14 16  7",\
		"6 10  3 18  5",\
		"1 12 20 15 19"})

#include <gtest/gtest.h>

TEST(Solution_4_1Test, CheckGenericValues)
{
	EXPECT_EQ( solutions::WinBingo(genericInput_4_1), 4512);
}

TEST(BingoBoardTest, HaveWonHorizontal)
{
	declareTestBoard;
	testBoard.MarkIfOnBoard(22);
	testBoard.MarkIfOnBoard(13);
	testBoard.MarkIfOnBoard(17);
	testBoard.MarkIfOnBoard(11);
	testBoard.MarkIfOnBoard(0);
	EXPECT_TRUE(testBoard.HaveWon());
	testBoard.MarkIfOnBoard(23);
	testBoard.MarkIfOnBoard(14);
	testBoard.MarkIfOnBoard(3);
	testBoard.MarkIfOnBoard(25);
	testBoard.MarkIfOnBoard(20);
	EXPECT_TRUE(testBoard.HaveWon());
}

TEST(BingoBoardTest, HaveWonVertical)
{
	declareTestBoard;
	testBoard.MarkIfOnBoard(22);
	testBoard.MarkIfOnBoard(8);
	testBoard.MarkIfOnBoard(21);
	testBoard.MarkIfOnBoard(6);
	testBoard.MarkIfOnBoard(1);
	EXPECT_TRUE(testBoard.HaveWon());
	testBoard.MarkIfOnBoard(23);
	testBoard.MarkIfOnBoard(4);
	testBoard.MarkIfOnBoard(17);
	EXPECT_TRUE(testBoard.HaveWon());
}

TEST(BingoBoardTest, HaveNotWon)
{
	declareTestBoard;
	testBoard.MarkIfOnBoard(22);
	testBoard.MarkIfOnBoard(2);
	testBoard.MarkIfOnBoard(14);
	testBoard.MarkIfOnBoard(18);
	testBoard.MarkIfOnBoard(19);
	EXPECT_FALSE(testBoard.HaveWon());
}

TEST(BingoBoardTest, Score)
{
	declareTestBoard;
	testBoard.MarkIfOnBoard(22);
	testBoard.MarkIfOnBoard(13);
	testBoard.MarkIfOnBoard(17);
	testBoard.MarkIfOnBoard(11);
	testBoard.MarkIfOnBoard(0);
	
	EXPECT_EQ( testBoard.Score(0), 0);
	EXPECT_EQ( testBoard.Score(22),
		(8 + 2 + 23 + 4 + 24 +
		21 + 9 + 14 + 16 + 7 +
		6 + 10 + 3 + 18 + 5 +
		1 + 12 + 20 + 15 + 19) * 22);
}

TEST(Solution_4_1Test, CheckBadInput)
{
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}