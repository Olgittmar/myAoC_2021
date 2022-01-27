#include <solutions/16/day_16_part_1.h>
#include <solutions/16/day_16_part_2.h>

constexpr const char* genericInput_16_Literal = "D2FE28";
constexpr const char* genericInput_16_Operator_1 = "38006F45291200";
constexpr const char* genericInput_16_Operator_2 = "EE00D40C823060";
constexpr const char* genericInput_16_1 = "8A004A801A8002F478";
constexpr const char* genericInput_16_2 = "620080001611562C8802118E34";
constexpr const char* genericInput_16_3 = "C0015000016115A2E0802F182340";
constexpr const char* genericInput_16_4 = "A0016C880162017C3686B18A3D4780";

#include <gtest/gtest.h>

TEST(Solution16Part1Test, Package_Literal) // NOLINT
{
	EXPECT_EQ( solutions::SumOfPacketVersions(genericInput_16_Literal), 6); // NOLINT
}

TEST(Solution16Part1Test, Package_Operator) // NOLINT
{
	EXPECT_EQ( solutions::SumOfPacketVersions(genericInput_16_Operator_1), 9); // NOLINT
	EXPECT_EQ( solutions::SumOfPacketVersions(genericInput_16_Operator_2), 14); // NOLINT
}

TEST(Solution16Part1Test, Package_1) // NOLINT
{
	EXPECT_EQ( solutions::SumOfPacketVersions(genericInput_16_1), 16); // NOLINT
}

TEST(Solution16Part1Test, Package_2) // NOLINT
{
	EXPECT_EQ( solutions::SumOfPacketVersions(genericInput_16_2), 12); // NOLINT
}

TEST(Solution16Part1Test, Package_3) // NOLINT
{
	EXPECT_EQ( solutions::SumOfPacketVersions(genericInput_16_3), 23); // NOLINT
}

TEST(Solution16Part1Test, Package_4) // NOLINT
{
	EXPECT_EQ( solutions::SumOfPacketVersions(genericInput_16_4), 31); // NOLINT
}

auto main(int argc, char **argv) -> int
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}