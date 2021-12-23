#include "MyAoC_2021/solutions/Solution_7_2.h"

#include <cmath>

#include "MyAoC_2021/utils/StringSplit.h"
#include "MyAoC_2021/solutions/Solution_7_1.h"

namespace solutions
{

ulong CalculateExpensiveFuelConsumption(const std::vector<ulong>& crabPositions)
{
	if(crabPositions.empty()){
		return 0UL;
	}

	const auto [minPos, maxPos] = GetCrabPositionRange(crabPositions);
	std::vector<ulong> fuelConsumptions(maxPos - minPos, 0UL);

	for(size_t pos = 0; pos < fuelConsumptions.size(); ++pos){
		for(auto crabPos : crabPositions) {
			auto cost = CostOfStepsBetween(crabPos, minPos + pos);
			fuelConsumptions[pos] += cost;
		}
	}

	ulong optimalFuelConsumption{fuelConsumptions.front()};
	for(auto consumption : fuelConsumptions){
		optimalFuelConsumption = std::min(consumption, optimalFuelConsumption);
	}

	return optimalFuelConsumption;
}

ulong CalculateExpensiveAlignmentOptimalFuelConsumption(const std::string_view& input)
{
	auto crabPositions = utils::SplitStringToULong(input, ',');
	return CalculateExpensiveFuelConsumption(crabPositions);
}

}
