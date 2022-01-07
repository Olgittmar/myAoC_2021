#include <12/part_1.h>

constexpr const char* genericInput_12_1_none = "start-A\nA-c\nb-d\nb-end";
constexpr const char* genericInput_12_1_small = "start-A\nstart-b\nA-c\nA-b\nb-d\nA-end\nb-end";
constexpr const char* genericInput_12_1_larger = "dc-end\nHN-start\nstart-kj\ndc-start\ndc-HN\nLN-dc\nHN-end\nkj-sa\nkj-HN\nkj-dc";
constexpr const char* genericInput_12_1_huge = "fs-end\nhe-DX\nfs-he\nstart-DX\npj-DX\nend-zg\nzg-sl\nzg-pj\npj-he\nRW-he\nfs-DX\npj-RW\nzg-RW\nstart-pj\nhe-WI\nzg-he\npj-fs\nstart-RW";

#include <gtest/gtest.h>

TEST(Solution_12_1Test, CheckGenericValues) // NOLINT
{
	EXPECT_EQ( solutions::FindNumCavePaths(genericInput_12_1_none), 0); // NOLINT
	EXPECT_EQ( solutions::FindNumCavePaths(genericInput_12_1_small), 10); // NOLINT
	EXPECT_EQ( solutions::FindNumCavePaths(genericInput_12_1_larger), 19); // NOLINT
	EXPECT_EQ( solutions::FindNumCavePaths(genericInput_12_1_huge), 226); // NOLINT
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}