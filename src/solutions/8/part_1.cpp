#include <8/part_1.h>

#include <cmath>
#include <unordered_set>

#include <StringSplit.h>

namespace solutions
{

int GetNumberOfSegments(const std::string_view& code)
{
	return static_cast<int>(code.size());
}

int GetNumberOfCodesOfUniqueLength(const std::vector<std::string_view>& data)
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

int GetNumberOfCodesOfUniqueLengthInOutput(const std::string_view& input)
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

}
