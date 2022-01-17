#include <solutions/14/day_14_part_1.h>

#include <sstream>
#include <span>

#include <utils/utils.h>

namespace solutions
{

auto GetPolymerChain(const std::string_view& polymerChain, const std::vector<std::string_view>& insertionRules) -> std::string
{
	std::string _ret{};

	// Ok since lifetime of this map is less than insertionRules
	std::map<std::string_view, std::string_view> insertionRuleMap{};

	for(const auto& item : insertionRules){
		auto rule = utils::SplitString(item, " -> ");
		if(rule.size() != 2UL) {
			continue;
		}
		insertionRuleMap.emplace(rule.at(0UL), rule.at(1UL));
	}

	std::string key{"0"};
	key += polymerChain.at(0UL);
	// key is a sliding window over the pairs of chars in polymerChain.
	for(const char& c : polymerChain.substr(1UL)) {
		key.at(0UL) = key.at(1UL);
		key.at(1UL) = c;

		_ret += key.at(0UL);
		if(insertionRuleMap.contains(key)) {
			_ret += insertionRuleMap.at(key);
		}
	}
	// Add last char, it's not covered by loop above, but will not result in any new insertions
	_ret += key.at(1UL);
	return _ret;
}

auto CommonUncommonPolymerDiff(const std::string_view& input, int numSteps) -> long
{
	auto delimPos = input.find("\n\n");
	auto polyChainTemplate = input.substr(0UL, delimPos);
	auto insertionRules = utils::SplitString(input.substr(delimPos + 2UL), '\n');

	// Go through the steps
	std::string polyChain{polyChainTemplate.begin(), polyChainTemplate.end()};
	for(int step = 0; step < numSteps; ++step) {
		polyChain = GetPolymerChain(polyChain, insertionRules);
	}

	// Count occurances
	std::map<char, long> charCountMap{};
	for(const char& c : polyChain) {
		++charCountMap[c];
	}

	long mostCommon{0}, leastCommon{__LONG_MAX__};
	for(const auto& item : charCountMap ) {
		mostCommon = std::max(mostCommon, item.second);
		leastCommon = std::min(leastCommon, item.second);
	}

	return mostCommon - leastCommon;
}

} // namespace solutions


