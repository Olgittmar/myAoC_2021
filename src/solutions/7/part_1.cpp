#include <7/part_1.h>

#include <cmath>

#include <StringSplit.h>

namespace solutions
{

auto CalculateFuelConsumption(const std::vector<ulong>& crabPositions, size_t pos) -> ulong
{
	ulong fuelConsumption{};
	for(auto crabPos : crabPositions){
		fuelConsumption += std::max(crabPos, pos) - std::min(crabPos, pos);
	}
	return fuelConsumption;
}

auto GetCrabPositionRange(const std::vector<ulong>& crabPositions) -> std::pair<ulong,ulong>
{
	std::pair<ulong,ulong> _ret{crabPositions.size() - 1, 0UL};
	if(_ret.first == _ret.second){
		return _ret;
	}

	for(auto crabPos : crabPositions){
		_ret.first = std::min(crabPos, _ret.first);
		_ret.second = std::max(crabPos, _ret.second);
	}

	return _ret;
}

auto CalculateAlignmentOptimalFuelConsumption(const std::string_view& input) -> ulong
{
	auto crabPositions = utils::SplitStringToULong(input, ',');
	auto [minPos, maxPos] = GetCrabPositionRange(crabPositions);
	// Bugprone, need to find a better way to initialize this val
	// maybe use transform or generate instead?
	ulong fuelConsumption{CalculateFuelConsumption(crabPositions, 0UL)};
	// ulong bestPos{};

	for(ulong i = minPos; i <= maxPos; ++i){
		auto candidate = CalculateFuelConsumption(crabPositions, i);
		if( candidate < fuelConsumption ){
			fuelConsumption = candidate;
			// bestPos = i;
		}
	}
	return fuelConsumption;
}

} // namespace solutions
