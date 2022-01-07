#include <Coordinates.h>

#include <string>
#include <vector>

#include <gtest/gtest.h>
// NOLINTBEGIN(*-readability-magic-numbers)
TEST(Coordinate2DTest, init) // NOLINT
{
  utils::Coordinate2D defaultCoord;
  EXPECT_EQ( defaultCoord.x(), 0 );
  EXPECT_EQ( defaultCoord.y(), 0 );

  utils::Coordinate2D coord(2, 5); // NOLINT
  EXPECT_EQ( coord.x(), 2 );
  EXPECT_EQ( coord.y(), 5 );

  utils::Coordinate2D copy(coord);
  EXPECT_EQ( copy.x(), 2 );
  EXPECT_EQ( copy.y(), 5 );
}

TEST(Coordinate2DTest, operatorEquals) // NOLINT
{
  utils::Coordinate2D coord1(2, 5); // NOLINT
  utils::Coordinate2D coord2(2, 5); // NOLINT
  utils::Coordinate2D coord3(4, 5); // NOLINT
  utils::Coordinate2D coord4;

  EXPECT_EQ( coord1, coord2 );
  EXPECT_EQ( coord1, utils::Coordinate2D(2, 5) ); // NOLINT
  EXPECT_EQ( coord4, utils::Coordinate2D() ); // NOLINT
  EXPECT_NE( coord1, coord3 );
  EXPECT_NE( coord2, coord3 );
  EXPECT_NE( coord1, coord4 );
  EXPECT_NE( coord2, coord4 );
  EXPECT_NE( coord3, coord4 );
}

TEST(LineTest, init) // NOLINT
{
    utils::Line line1 = utils::Line(utils::Coordinate2D{2, 0}, utils::Coordinate2D{3,4});
    utils::Line line2 = utils::Line::lineFromString("2,0 -> 3,4");
    EXPECT_EQ(line1, line2);
}


TEST(LineTest, slope) // NOLINT
{
    utils::Line slopedLine = utils::Line::lineFromString("2,0 -> 3,4");
    utils::Line slopedLine2 = utils::Line::lineFromString("1,0 -> 3,4");

    EXPECT_EQ( slopedLine.slope(), 4 ); // NOLINT
    EXPECT_EQ( slopedLine2.slope(), 2 ); // NOLINT
}

TEST(LineTest, Iterate) // NOLINT
{
    utils::Line slopedLine = utils::Line::lineFromString("2,0 -> 4,8");

    int expected_x = 2; // NOLINT
    int expected_y = 0; // NOLINT
    int iterations = 0; // NOLINT
    auto range = slopedLine.range();
    ASSERT_EQ( range.size(), 3 );
    for( auto coord : range ) { // Constness?
        ++iterations;
        ASSERT_EQ(coord.x(), expected_x);
        ASSERT_EQ(coord.y(), expected_y);
        ++expected_x;
        expected_y += 4; // NOLINT
    }
    EXPECT_EQ(iterations, 3); // NOLINT


    utils::Line anotherSlopedLine = utils::Line::lineFromString("8,0 -> 0,8");

    // Making assumptions about how the range is parsed, this is a bad test
    int anotherExpected_x = 0; // NOLINT
    int anotherExpected_y = 8; // NOLINT
    int otherIterations = 0; // NOLINT
    auto anotherRange = anotherSlopedLine.range();
    ASSERT_EQ( anotherRange.size(), 9 );
    for( auto coord : anotherRange ) { // Constness?
        ++otherIterations;
        ASSERT_EQ(coord.x(), anotherExpected_x);
        ASSERT_EQ(coord.y(), anotherExpected_y);
        ASSERT_TRUE(coord.x() + coord.y() == 8); // NOLINT
        ++anotherExpected_x;
        anotherExpected_y -= 1;
    }
    EXPECT_EQ(otherIterations, 9); // NOLINT
}

TEST(LineTest, IterateVertical) // NOLINT
{
    utils::Line verticalLine = utils::Line::lineFromString("2,0 -> 2,4");

    int expected_x = 2; // NOLINT
    int expected_y = 0; // NOLINT
    int iterations = 0; // NOLINT
    auto range = verticalLine.range();
    ASSERT_EQ( range.size(), 5 ); // NOLINT
    for( auto coord : range ) {
        ++iterations;
        ASSERT_EQ(coord.x(), expected_x);
        ASSERT_EQ(coord.y(), expected_y);
        ++expected_y;
    }
    EXPECT_EQ(iterations, 5); // NOLINT
}

TEST(LineTest, IterateHorizontal) // NOLINT
{
    utils::Line horizontalLine = utils::Line::lineFromString("2,1 -> 8,1");

    int expected_x = 2; // NOLINT
    int expected_y = 1; // NOLINT
    int iterations = 0; // NOLINT
    auto range = horizontalLine.range();
    ASSERT_EQ( range.size(), 7 ); // NOLINT
    for( auto coord : range ) {
        ++iterations;
        ASSERT_EQ(coord.x(), expected_x);
        ASSERT_EQ(coord.y(), expected_y);
        ++expected_x;
    }
    EXPECT_EQ(iterations, 7); // NOLINT
}
// NOLINTEND(*-readability-magic-numbers)
auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
