#include <8/part_1.h>

#include <cmath>
#include <unordered_set>

#include <StringSplit.h>

namespace solutions
{

auto GetNumberOfSegments(const std::string_view& code) -> int
{
	return static_cast<int>(code.size());
}

auto GetNumberOfCodesOfUniqueLength(const std::vector<std::string_view>& data) -> int
{
	int _ret{0};
	const std::unordered_set<int> sizesFound{2, 3, 4, 7};
	for( auto jumbledNumber : data ){
		if( sizesFound.contains( GetNumberOfSegments(jumbledNumber) ) ){
			++_ret;
		}
	}
	return _ret;
}

auto GetNumberOfCodesOfUniqueLengthInOutput(const std::string_view& input) -> int
{
	// auto data = utils::SplitString(input, '|');
	// auto jumbledInput = data.at(0);
	// auto jumbledOutput = data.at(1);
	int numUnique{0};
	auto lines = utils::SplitString(input, '\n');
	for(auto line : lines){
		auto jumbledOutput = utils::SplitString(line, '|').at(1);
		auto jumbledCodes = utils::SplitString(jumbledOutput, ' ');
		numUnique += GetNumberOfCodesOfUniqueLength(jumbledCodes);
	}
	return numUnique;
}

} // namespace solutions
