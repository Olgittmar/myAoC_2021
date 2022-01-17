#ifndef MYAOC_2021_SOLUTIONS_14_DAY_14_PART_1_H
#define MYAOC_2021_SOLUTIONS_14_DAY_14_PART_1_H

#include <string>
#include <vector>

namespace solutions {

auto GetPolymerChain(const std::string_view& polymerChain, const std::vector<std::string_view>& insertionRules) -> std::string;
auto CommonUncommonPolymerDiff(const std::string_view& input, int numSteps) -> long;

} // namespace solutions

#endif