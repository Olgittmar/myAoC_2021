#include <solutions/15/day_15_part_1.h>

#include <queue>
#include <set>
#include <vector>

#include <utils/utils.h>

namespace solutions
{

// TODO: function turned out quite chunky, need to refactor for clarity
auto FindLeastRiskyPath(const std::vector<std::vector<int>>& map, int avgCost) -> int
{
	typedef std::pair<int, int> Coordinate;
	typedef std::pair<Coordinate, int> ValuedCoordinate;
	
	const Coordinate _start{0, 0};
	const Coordinate _goal{static_cast<int>(map.at(0UL).size() - 1UL), static_cast<int>(map.size() - 1UL)};
	
	auto h =  [&] ( const Coordinate& coord ) constexpr -> int {
		auto dx = std::max(coord.first, _goal.first) -  std::min(coord.first, _goal.first);
    	auto dy = std::max(coord.second, _goal.second) - std::min(coord.second, _goal.second);
    	return avgCost * (dx + dy);
	};

	// Queue of paths to be considered, with the associated cost
    auto cmp = [&] (const ValuedCoordinate& left, const ValuedCoordinate& right) constexpr -> bool {
		return (h(left.first) + left.second) > (h(right.first) + right.second);
	};

	// Prime queue with first possible nodes
	std::priority_queue<ValuedCoordinate, std::vector<ValuedCoordinate>, decltype(cmp)> queue(cmp);

	// We have already considered start, in theory
	std::map<Coordinate, int> considered{{_start, 0}};

	// Lambda to compact code a bit
	auto ConsiderCoordinate = [&](const Coordinate& coord, int nodeCost) {
		auto costOfCoord = map.at(size_t(coord.second)).at(size_t(coord.first));
		ValuedCoordinate valuedCoord{coord, nodeCost + costOfCoord};
		if(!considered.contains(coord)) {
			queue.push(valuedCoord);
		} else if(considered.at(coord) > valuedCoord.second) {
			considered.erase(coord);
			queue.push(valuedCoord);
		}
	};

	{
		ValuedCoordinate startSouth{{1, 0}, map.at(0UL).at(1UL)};
		ValuedCoordinate startEast{{0, 1}, map.at(1UL).at(0UL)};
		queue.push(startSouth);
		queue.push(startEast);
	}

	int cheapestPathCost = INT32_MAX;

	// Start by fining any path by considering cheapest nodes first
	// something like orthogonal A*
	while(!queue.empty()) {
		auto currentCoord = queue.top().first;
		// g is cost up to and including this point
		auto g = queue.top().second;
		queue.pop();

		if(considered.contains(currentCoord)) {
			continue;
		}
		considered.emplace(currentCoord, g);

		// When a path has been found, we can discard anything more expensive than the one we found
		// branching from the lowest cost options first
		if(cheapestPathCost <= g) {
			continue;
		}

		if(currentCoord == _goal) {
			cheapestPathCost = std::min(cheapestPathCost, g);
		}

		// Add next batch of coords to be considered.
		if(currentCoord.first > 0) {
			Coordinate west{currentCoord.first - 1, currentCoord.second};
			ConsiderCoordinate(west, g);
		}

		if(currentCoord.first < _goal.first) {
			Coordinate east{currentCoord.first + 1, currentCoord.second};
			ConsiderCoordinate(east, g);
		}

		if(currentCoord.second > 0) {
			Coordinate north{currentCoord.first, currentCoord.second - 1};
			ConsiderCoordinate(north, g);
		}

		if(currentCoord.second < _goal.second) {
			Coordinate south{currentCoord.first, currentCoord.second + 1};
			ConsiderCoordinate(south, g);
		}
	}

	return cheapestPathCost;
}

auto RiskValueOfLeastRiskyPath(const std::string_view& input) -> int
{
	auto lines = utils::SplitString(input, '\n');
	auto x_size = lines.at(0UL).size();
	auto y_size = lines.size();
	auto charToInt = [](const char& c) -> int { return c - '0'; };
	double avgCost{-1.0}; // Heuristic constant used in pathfinding algorithm later

	std::vector<std::vector<int>> map( y_size, std::vector<int>(x_size, 0) );
	for(size_t y = 0UL; y < y_size; ++y) { // y
		for(size_t x = 0UL; x < x_size; ++x) { // x
			auto val = charToInt( lines.at(y).at(x) );
			map.at(y).at(x) = val;
			avgCost = (avgCost == -1.0 ? double(val) : (avgCost + double(val)) / 2.0);
		}
	}

	return FindLeastRiskyPath(map, int(avgCost));
}

} // namespace solutions


