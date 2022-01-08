#ifndef MYAOC_2021_SOLUTIONS_7_DAY_7_7_PART_1_H
#define MYAOC_2021_SOLUTIONS_7_DAY_7_7_PART_1_H

#include <string>
#include <vector>

#include <utils/Constants.h>

namespace solutions
{

auto CalculateFuelConsumption(const std::vector<ulong>& crabPositions, size_t pos) -> ulong;
auto GetCrabPositionRange(const std::vector<ulong>& crabPositions) -> std::pair<ulong,ulong>;
auto CalculateAlignmentOptimalFuelConsumption(const std::string_view& input) -> ulong;

} // namespace solutions

#endif