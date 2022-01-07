#include <7/part_2.h>

#include <cmath>

#include <7/part_1.h>
#include <StringSplit.h>

namespace solutions
{

auto CalculateExpensiveFuelConsumption(const std::vector<ulong>& crabPositions) -> ulong
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

auto CalculateExpensiveAlignmentOptimalFuelConsumption(const std::string_view& input) -> ulong
{
	auto crabPositions = utils::SplitStringToULong(input, ',');
	return CalculateExpensiveFuelConsumption(crabPositions);
}

} // namespace solutions
