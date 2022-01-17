#ifndef MYAOC_2021_SOLUTIONS_14_DAY_14_PART_1_H
#define MYAOC_2021_SOLUTIONS_14_DAY_14_PART_1_H

#include <string>
#include <vector>

namespace solutions {

auto GetPolymerChain(
	const std::map<std::string_view, std::string_view>& insertionRules,
	const std::map<std::string, long>& pairCountMap,
	std::map<char, long>& charCountMap)
  -> std::map<std::string, long>;
auto CommonUncommonPolymerDiff(const std::string_view& input, int numSteps) -> long;

} // namespace solutions

#endif