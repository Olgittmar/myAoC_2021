#ifndef SOLUTION_7_2
#define SOLUTION_7_2

#include <string>
#include <vector>

#include <Constants.h>

namespace solutions
{

inline constexpr ulong CostOfSteps(ulong n) { return (n * (n + 1UL)) / 2UL; }

inline constexpr ulong CostOfStepsBetween(ulong crabPos, ulong pos) {
	return CostOfSteps(std::max(crabPos, pos) - std::min(crabPos, pos));
}

ulong CalculateExpensiveFuelConsumption(const std::vector<ulong>& crabPositions);

ulong CalculateExpensiveAlignmentOptimalFuelConsumption(const std::string_view& input);

}

#endif