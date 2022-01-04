#ifndef SOLUTION_7_1
#define SOLUTION_7_1

#include <string>
#include <vector>

#include "MyAoC_2021/utils/Constants.h"

namespace solutions
{

ulong CalculateFuelConsumption(const std::vector<ulong>& crabPositions, size_t pos);
std::pair<ulong,ulong> GetCrabPositionRange(const std::vector<ulong>& crabPositions);
ulong CalculateAlignmentOptimalFuelConsumption(const std::string_view& input);

}

#endif