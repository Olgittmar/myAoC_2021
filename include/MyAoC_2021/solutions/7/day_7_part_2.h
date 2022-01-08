#ifndef MYAOC_2021_SOLUTIONS_7_DAY_7_7_PART_2_H
#define MYAOC_2021_SOLUTIONS_7_DAY_7_7_PART_2_H

#include <string>
#include <vector>

#include <utils/Constants.h>

namespace solutions
{

inline constexpr auto CostOfSteps(ulong n) -> ulong { return (n * (n + 1UL)) / 2UL; }

inline constexpr auto CostOfStepsBetween(ulong crabPos, ulong pos) -> ulong {
	return CostOfSteps(std::max(crabPos, pos) - std::min(crabPos, pos));
}

auto CalculateExpensiveFuelConsumption(const std::vector<ulong>& crabPositions) -> ulong;

auto CalculateExpensiveAlignmentOptimalFuelConsumption(const std::string_view& input) -> ulong;

} // namespace solutions

#endif