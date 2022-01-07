#ifndef SOLUTION_7_1
#define SOLUTION_7_1

#include <string>
#include <vector>

#include <Constants.h>

namespace solutions
{

auto CalculateFuelConsumption(const std::vector<ulong>& crabPositions, size_t pos) -> ulong;
auto GetCrabPositionRange(const std::vector<ulong>& crabPositions) -> std::pair<ulong,ulong>;
auto CalculateAlignmentOptimalFuelConsumption(const std::string_view& input) -> ulong;

} // namespace solutions

#endif