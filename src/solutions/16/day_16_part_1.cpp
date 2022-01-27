#include <solutions/16/day_16_part_1.h>

#include <ranges>

#include <utils/utils.h>

namespace solutions
{

auto GetLiteralPackage(const std::string_view& bits, size_t& pos, const std::string_view& packageVersion, const std::string_view& packageTypeId)
	-> std::unique_ptr<LiteralPackage>
{
		char prefix;
		ulong val = 0UL;
		do {
			prefix = bits.at(pos++);
			auto valStr = bits.substr(pos, 4UL);
			// bitwise or?
			val = (val << 4) + utils::StringViewToULong(valStr, 2);
			pos += 4UL;
		} while( prefix != '0' && pos < bits.size());

		return std::make_unique<LiteralPackage>( LiteralPackage{ {.version = packageVersion, .typeID = packageTypeId}, val} );
}

auto GetOperatorPackage(const std::string_view& bits, size_t& pos, const std::string_view& packageVersion, const std::string_view& packageTypeId)
	-> std::unique_ptr<OperatorPackage>
{
	auto packageLengthTypeBit = bits.at(pos++);
	auto packageLengthType = (packageLengthTypeBit == '0' ? OperatorPackage::BITSIZE : OperatorPackage::COUNT);
	auto subPackageLengthNumBits = (packageLengthTypeBit == '0' ? 15UL : 11UL);
	auto subPackageLengthBits = bits.substr(pos, subPackageLengthNumBits);
	pos += subPackageLengthNumBits;
	auto subPackageLength = utils::StringViewToULong(subPackageLengthBits, 2);
	auto subPackages = GetSubPackages(bits, pos, subPackageLength, packageLengthType);
	
	return std::make_unique<OperatorPackage>( OperatorPackage{
			{.version = packageVersion, .typeID = packageTypeId},
			packageLengthType, subPackageLength, std::move(subPackages)} );
}


auto GetSubPackages(const std::string_view& bits, size_t& pos, ulong count, OperatorPackage::LengthType lengthType)
	-> std::vector<std::unique_ptr<Package>>
{
	std::vector<std::unique_ptr<Package>> _ret;

	if(lengthType == OperatorPackage::COUNT)
	{
		for(ulong n = 0UL; n < count; ++n) {
			_ret.push_back( GetNextPackage(bits, pos) );
		}
	}
	else if(lengthType == OperatorPackage::BITSIZE)
	{
		auto endPos = pos + count;
		while(pos < endPos && endPos <= bits.size()) {
			_ret.push_back( GetNextPackage(bits, pos) );
		}
	}

	return _ret;
}

auto GetNextPackage(const std::string_view& bits, size_t& pos) -> std::unique_ptr<Package>
{
	using namespace std::string_literals;

	auto packageVersion = bits.substr(pos, 3UL);
	pos += 3UL;

	auto packageTypeId = bits.substr(pos, 3UL);
	pos += 3UL;

	if(packageTypeId == "100"s) {
		return GetLiteralPackage(bits, pos, packageVersion, packageTypeId);
	}

	return GetOperatorPackage(bits, pos, packageVersion, packageTypeId);
}

auto GetPackages(const std::string_view& bits) -> std::vector<std::unique_ptr<Package>>
{
	std::vector<std::unique_ptr<Package>> _ret{};

	for(size_t pos = 0UL; pos < bits.size();) {
		_ret.push_back( GetNextPackage(bits, pos) );
	}
	
	return _ret;
}

constexpr auto CharToBits(const char& c) -> const char*
{
	using namespace std::string_literals;
	switch (c)
	{
		case '0': return "0000";
		case '1': return "0001";
		case '2': return "0010";
		case '3': return "0011";
		case '4': return "0100";
		case '5': return "0101";
		case '6': return "0110";
		case '7': return "0111";
		case '8': return "1000";
		case '9': return "1001";
		case 'A': return "1010";
		case 'B': return "1011";
		case 'C': return "1100";
		case 'D': return "1101";
		case 'E': return "1110";
		case 'F': return "1111";
		default: return "";
	}
}

inline auto Package::GetSumOfPackageVersions() -> ulong
{
	using namespace std::string_literals;
	ulong _ret = utils::StringViewToULong(version, 2);
	if(typeID != "100"s) {
		auto op = static_cast<OperatorPackage*>(this);
		for( auto& subPackage : op->subPackages) {
			_ret += subPackage->GetSumOfPackageVersions();
		}
	}
	return _ret;
}

auto Package::GetPackageValue() -> ulong
{
	using namespace std::string_literals;
	if(typeID == "100"s) {
		auto lp = static_cast<LiteralPackage*>(this);
		return lp->value;
	}

	auto op = static_cast<OperatorPackage*>(this);
	ulong _ret{};
	switch (utils::StringViewToULong(typeID, 2))
	{
	case 0UL: // Sum
	{
		_ret = std::accumulate(
			std::next(op->subPackages.begin()), op->subPackages.end(),
			op->subPackages.front()->GetPackageValue(),
			[&](ulong S, std::unique_ptr<solutions::Package>& subPackage) {
				return S + subPackage->GetPackageValue();
			}
		);
	} break;
	case 1UL: // Product
	{
		_ret = std::accumulate(
			std::next(op->subPackages.begin()), op->subPackages.end(),
			op->subPackages.front()->GetPackageValue(),
			[&](ulong S, std::unique_ptr<solutions::Package>& subPackage) {
				return S * subPackage->GetPackageValue();
			}
		);

	} break;
	case 2UL: // Min
	{
		//! Can we do this more reasonably with std::min or similar?
		_ret = ULLONG_MAX;
		for(auto& subPackage : op->subPackages) {
			_ret = std::min(_ret, subPackage->GetPackageValue());
		}
	} break;
	case 3UL: // Max
	{
		_ret = 0UL;
		for(auto& subPackage : op->subPackages) {
			_ret = std::max(_ret, subPackage->GetPackageValue());
		}
	} break;
	case 5UL: // Greater
	{
		auto firstVal = op->subPackages.front()->GetPackageValue();
		auto secondVal = op->subPackages.at(1UL)->GetPackageValue();
		_ret = static_cast<ulong>( firstVal > secondVal );
	} break;
	case 6UL: // Less
	{
		auto firstVal = op->subPackages.front()->GetPackageValue();
		auto secondVal = op->subPackages.at(1UL)->GetPackageValue();
		_ret = static_cast<ulong>( firstVal < secondVal );
	} break;
	case 7UL: // Eq
	{
		auto firstVal = op->subPackages.front()->GetPackageValue();
		auto secondVal = op->subPackages.at(1UL)->GetPackageValue();
		_ret = static_cast<ulong>( firstVal == secondVal );
	} break;

	default: break;
	}

	return _ret;
}

auto SumOfPackageVersions(const std::string_view& input) -> ulong
{
	std::string bits{};
	bits.reserve(input.size() * 4UL);

	for(const char& c : input) {
		bits += CharToBits(c);
	}

	size_t pos = 0UL;
	auto rootPackage = GetNextPackage(bits, pos);

	ulong sumOfVersions = rootPackage->GetSumOfPackageVersions();
	
	return sumOfVersions;
}


} // namespace solutions