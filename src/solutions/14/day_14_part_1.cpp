#include <solutions/14/day_14_part_1.h>

#include <sstream>
#include <span>
#include <tuple>

#include <utils/utils.h>

namespace solutions
{

auto GetPolymerChain(
	const std::map<std::string_view, std::string_view>& insertionRuleMap,
	const std::map<std::string, long>& pairCountMap,
	std::map<char, long>& charCountMap)
  -> std::map<std::string, long>
{
	std::map<std::string, long> _retPairCount{};
	
	for(const auto& pair : pairCountMap) {
		auto key = pair.first;
		auto val = pair.second;
		
		if( insertionRuleMap.contains(key) ) {
			auto insertVal = insertionRuleMap.at(key).front();
			charCountMap[insertVal] += val;
			
			std::string leftKey{key.front()};
			leftKey += insertVal;

			std::string rightKey{insertVal};
			rightKey += key.back();

			_retPairCount[leftKey] += val;
			_retPairCount[rightKey] += val;
		} else {
			_retPairCount[key] += val;
		}
	}

	return _retPairCount;
}

auto CommonUncommonPolymerDiff(const std::string_view& input, int numSteps) -> long
{
	auto delimPos = input.find("\n\n");
	auto polyChainTemplate = input.substr(0UL, delimPos);
	auto insertionRules = utils::SplitString(input.substr(delimPos + 2UL), '\n');

	// Which pairs should be split, and what should be inserted
	std::map<std::string_view, std::string_view> insertionRuleMap{};
	// How many of each pair do we currently have?
	std::map<std::string, long> pairCountMap{};
	// How many of each char do we have?
	std::map<char, long> charCountMap{};

	for(const auto& item : insertionRules){
		auto rule = utils::SplitString(item, " -> ");
		if(rule.size() != 2UL) {
			continue;
		}
		insertionRuleMap.emplace(rule.at(0UL), rule.at(1UL));
	}

	for(size_t offset = 0UL; offset < polyChainTemplate.size(); ++offset) {
		charCountMap[polyChainTemplate.at(offset)] += 1L;

		auto pair = polyChainTemplate.substr(offset, 2UL);
		if( pair.size() < 2UL ) {
			continue;
		}
		++pairCountMap[std::string{pair}];
	}

	// Go through the steps
	for(int step = 0; step < numSteps; ++step) {
		pairCountMap = GetPolymerChain(insertionRuleMap, pairCountMap, charCountMap);
	}

	long mostCommon{0}, leastCommon{__LONG_MAX__};
	for(const auto& item : charCountMap ) {
		mostCommon = std::max(mostCommon, item.second);
		leastCommon = std::min(leastCommon, item.second);
	}

	return mostCommon - leastCommon;
}

} // namespace solutions


