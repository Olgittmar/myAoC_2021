#ifndef SOLUTION_7_2
#define SOLUTION_7_2

#include <string>
#include <vector>

#include <Constants.h>

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