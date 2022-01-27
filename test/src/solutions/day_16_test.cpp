#include <solutions/16/day_16_part_1.h>
#include <solutions/16/day_16_part_2.h>

constexpr const char* genericInput_16_Literal = "D2FE28";
constexpr const char* genericInput_16_Operator_1 = "38006F45291200";
constexpr const char* genericInput_16_Operator_2 = "EE00D40C823060";
constexpr const char* genericInput_16_1_1 = "8A004A801A8002F478";
constexpr const char* genericInput_16_1_2 = "620080001611562C8802118E34";
constexpr const char* genericInput_16_1_3 = "C0015000016115A2E0802F182340";
constexpr const char* genericInput_16_1_4 = "A0016C880162017C3686B18A3D4780";

constexpr const char* genericInput_16_2_1 = "C200B40A82";
constexpr const char* genericInput_16_2_2 = "04005AC33890";
constexpr const char* genericInput_16_2_3 = "880086C3E88112";
constexpr const char* genericInput_16_2_4 = "CE00C43D881120";
constexpr const char* genericInput_16_2_5 = "D8005AC2A8F0";
constexpr const char* genericInput_16_2_6 = "F600BC2D8F";
constexpr const char* genericInput_16_2_7 = "9C005AC2F8F0";
constexpr const char* genericInput_16_2_8 = "9C0141080250320F1802104A08";

#include <gtest/gtest.h>

TEST(Solution16Part1Test, Package_Literal) // NOLINT
{
	EXPECT_EQ( solutions::SumOfPackageVersions(genericInput_16_Literal), 6UL); // NOLINT
}

TEST(Solution16Part1Test, Package_Operator) // NOLINT
{
	EXPECT_EQ( solutions::SumOfPackageVersions(genericInput_16_Operator_1), 9UL); // NOLINT
	EXPECT_EQ( solutions::SumOfPackageVersions(genericInput_16_Operator_2), 14UL); // NOLINT
}

// Part 1

TEST(Solution16Part1Test, Package_1_1) // NOLINT
{
	EXPECT_EQ( solutions::SumOfPackageVersions(genericInput_16_1_1), 16UL); // NOLINT
}

TEST(Solution16Part1Test, Package_1_2) // NOLINT
{
	EXPECT_EQ( solutions::SumOfPackageVersions(genericInput_16_1_2), 12UL); // NOLINT
}

TEST(Solution16Part1Test, Package_1_3) // NOLINT
{
	EXPECT_EQ( solutions::SumOfPackageVersions(genericInput_16_1_3), 23UL); // NOLINT
}

TEST(Solution16Part1Test, Package_1_4) // NOLINT
{
	EXPECT_EQ( solutions::SumOfPackageVersions(genericInput_16_1_4), 31UL); // NOLINT
}

// Part 2

TEST(Solution16Part1Test, Package_2_1) // NOLINT
{
	EXPECT_EQ( solutions::EvaluatePackageValues(genericInput_16_2_1), 3UL); // NOLINT
}

TEST(Solution16Part1Test, Package_2_2) // NOLINT
{
	EXPECT_EQ( solutions::EvaluatePackageValues(genericInput_16_2_2), 54UL); // NOLINT
}

TEST(Solution16Part1Test, Package_2_3) // NOLINT
{
	EXPECT_EQ( solutions::EvaluatePackageValues(genericInput_16_2_3), 7UL); // NOLINT
}

TEST(Solution16Part1Test, Package_2_4) // NOLINT
{
	EXPECT_EQ( solutions::EvaluatePackageValues(genericInput_16_2_4), 9UL); // NOLINT
}

TEST(Solution16Part1Test, Package_2_5) // NOLINT
{
	EXPECT_EQ( solutions::EvaluatePackageValues(genericInput_16_2_5), 1UL); // NOLINT
}

TEST(Solution16Part1Test, Package_2_6) // NOLINT
{
	EXPECT_EQ( solutions::EvaluatePackageValues(genericInput_16_2_6), 0UL); // NOLINT
}

TEST(Solution16Part1Test, Package_2_7) // NOLINT
{
	EXPECT_EQ( solutions::EvaluatePackageValues(genericInput_16_2_7), 0UL); // NOLINT
}

TEST(Solution16Part1Test, Package_2_8) // NOLINT
{
	EXPECT_EQ( solutions::EvaluatePackageValues(genericInput_16_2_8), 1UL); // NOLINT
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}