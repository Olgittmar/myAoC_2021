#ifndef MYAOC_2021_SOLUTIONS_16_DAY_16_PART_1_H
#define MYAOC_2021_SOLUTIONS_16_DAY_16_PART_1_H

#include <bitset>
#include <iostream>
#include <memory>
#include <vector>

#include <utils/utils.h>

namespace solutions {

//TODO: Implement comparator operators to clean up EvaluatePackageValues a bit
struct Package {
	enum PackageType {
		BASE, LITERAL, OPERATOR
	};

	std::string_view version;
	std::string_view typeID;

	inline auto GetSumOfPackageVersions() -> ulong;
	auto GetPackageValue() -> ulong;
};

struct LiteralPackage : public Package {
	ulong value;
};

struct OperatorPackage : public Package {
	enum LengthType {
		COUNT, BITSIZE
	};

	LengthType lengthType;
	ulong length = 0UL;
	std::vector<std::unique_ptr<Package>> subPackages;
};


auto GetSubPackages(const std::string_view& bits, size_t& pos, ulong count, OperatorPackage::LengthType lengthType)
	-> std::vector<std::unique_ptr<Package>>;
auto GetNextPackage(const std::string_view& bits, size_t& pos)
	-> std::unique_ptr<Package>;
auto GetLiteralPackage(const std::string_view& bits, size_t& pos, const std::string_view& packageVersion, const std::string_view& packageTypeId)
	-> std::unique_ptr<LiteralPackage>;
auto GetOperatorPackage(const std::string_view& bits, size_t& pos, const std::string_view& packageVersion, const std::string_view& packageTypeId)
	-> std::unique_ptr<OperatorPackage>;
auto GetPackages(const std::string_view& bits)
	-> std::vector<std::unique_ptr<Package>>;

constexpr auto CharToBits(const char& c) -> const char*;
auto SumOfPackageVersions(const std::string_view& input) -> ulong;

} // namespace solutions

#endif