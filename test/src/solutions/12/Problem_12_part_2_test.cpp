#include <solutions/12/day_12_part_2.h>

constexpr const char* genericInput_12_2_none = "start-A\nA-c\nb-d\nb-end";
constexpr const char* genericInput_12_2_small = "start-A\nstart-b\nA-c\nA-b\nb-d\nA-end\nb-end";
constexpr const char* genericInput_12_2_larger = "dc-end\nHN-start\nstart-kj\ndc-start\ndc-HN\nLN-dc\nHN-end\nkj-sa\nkj-HN\nkj-dc";
constexpr const char* genericInput_12_2_huge = "fs-end\nhe-DX\nfs-he\nstart-DX\npj-DX\nend-zg\nzg-sl\nzg-pj\npj-he\nRW-he\nfs-DX\npj-RW\nzg-RW\nstart-pj\nhe-WI\nzg-he\npj-fs\nstart-RW";

#include <gtest/gtest.h>

TEST(Solution_12_2Test, NoPath) // NOLINT
{
	EXPECT_EQ( solutions::FindNumCavePathsWithExtraVisit(genericInput_12_2_none), 0); // NOLINT
}


TEST(Solution_12_2Test, SmallCave) // NOLINT
{
	EXPECT_EQ( solutions::FindNumCavePathsWithExtraVisit(genericInput_12_2_small), 36); // NOLINT
}

TEST(Solution_12_2Test, LargerCave) // NOLINT
{
	EXPECT_EQ( solutions::FindNumCavePathsWithExtraVisit(genericInput_12_2_larger), 103); // NOLINT
}

TEST(Solution_12_2Test, HugeCave) // NOLINT
{
	EXPECT_EQ( solutions::FindNumCavePathsWithExtraVisit(genericInput_12_2_huge), 3509); // NOLINT
}
auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}