#include "MyAoC_2021/utils/Coordinates.h"

#include <vector>
#include <string>

#include <gtest/gtest.h>

TEST(Coordinate2DTest, init)
{
  utils::Coordinate2D defaultCoord;
  EXPECT_EQ( defaultCoord.x, 0 );
  EXPECT_EQ( defaultCoord.y, 0 );

  utils::Coordinate2D coord(2, 5);
  EXPECT_EQ( coord.x, 2 );
  EXPECT_EQ( coord.y, 5 );

  utils::Coordinate2D copy(coord);
  EXPECT_EQ( copy.x, 2 );
  EXPECT_EQ( copy.y, 5 );
}

TEST(Coordinate2DTest, operatorEquals)
{
  utils::Coordinate2D coord1(2, 5);
  utils::Coordinate2D coord2(2, 5);
  utils::Coordinate2D coord3(4, 5);
  utils::Coordinate2D coord4;

  EXPECT_EQ( coord1, coord2 );
  EXPECT_EQ( coord1, utils::Coordinate2D(2, 5) );
  EXPECT_EQ( coord4, utils::Coordinate2D() );
  EXPECT_NE( coord1, coord3 );
  EXPECT_NE( coord2, coord3 );
  EXPECT_NE( coord1, coord4 );
  EXPECT_NE( coord2, coord4 );
  EXPECT_NE( coord3, coord4 );
}

TEST(LineTest, slope)
{
    utils::Line slopedLine = utils::lineFromString("2,0 -> 3,4");
    utils::Line slopedLine2 = utils::lineFromString("1,0 -> 3,4");

    EXPECT_EQ( slopedLine.slope(), 4 );
    EXPECT_EQ( slopedLine2.slope(), 2 );
}

TEST(LineTest, Iterate)
{
    utils::Line slopedLine = utils::lineFromString("2,0 -> 4,8");

    int expected_x = 2;
    int expected_y = 0;
    int iterations = 0;
    auto range = slopedLine.range();
    ASSERT_EQ( range.size(), 3 );
    for( auto coord : range ) { // Constness?
        ++iterations;
        ASSERT_EQ(coord.x, expected_x);
        ASSERT_EQ(coord.y, expected_y);
        ++expected_x;
        expected_y += 4;
    }
    EXPECT_EQ(iterations, 3);


    utils::Line anotherSlopedLine = utils::lineFromString("8,0 -> 0,8");

    // Making assumptions about how the range is parsed, this is a bad test
    int anotherExpected_x = 0;
    int anotherExpected_y = 8;
    int otherIterations = 0;
    auto anotherRange = anotherSlopedLine.range();
    ASSERT_EQ( anotherRange.size(), 9 );
    for( auto coord : anotherRange ) { // Constness?
        ++otherIterations;
        ASSERT_EQ(coord.x, anotherExpected_x);
        ASSERT_EQ(coord.y, anotherExpected_y);
        ASSERT_TRUE(coord.x + coord.y == 8);
        ++anotherExpected_x;
        anotherExpected_y -= 1;
    }
    EXPECT_EQ(otherIterations, 9);
}

TEST(LineTest, IterateVertical)
{
    utils::Line verticalLine = utils::lineFromString("2,0 -> 2,4");

    int expected_x = 2;
    int expected_y = 0;
    int iterations = 0;
    auto range = verticalLine.range();
    ASSERT_EQ( range.size(), 5 );
    for( auto coord : range ) {
        ++iterations;
        ASSERT_EQ(coord.x, expected_x);
        ASSERT_EQ(coord.y, expected_y);
        ++expected_y;
    }
    EXPECT_EQ(iterations, 5);
}

TEST(LineTest, IterateHorizontal)
{
    utils::Line horizontalLine = utils::lineFromString("2,1 -> 8,1");

    int expected_x = 2;
    int expected_y = 1;
    int iterations = 0;
    auto range = horizontalLine.range();
    ASSERT_EQ( range.size(), 7 );
    for( auto coord : range ) {
        ++iterations;
        ASSERT_EQ(coord.x, expected_x);
        ASSERT_EQ(coord.y, expected_y);
        ++expected_x;
    }
    EXPECT_EQ(iterations, 7);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
