#include <solutions/15/day_15_part_2.h>

#include <utils/utils.h>

#include <solutions/15/day_15_part_1.h>

namespace solutions
{

// Pathfinding algorithm from 15_1 should be fast enough, so we only need to construct the larger map
auto RiskValueOfLeastRiskyPathThroughLargeMap(const std::string_view& input) -> int
{
	const ulong sizeMultiplier{5UL};
	auto lines = utils::SplitString(input, '\n');
	auto x_size = lines.at(0UL).size();
	auto y_size = lines.size();
	auto charToInt = [](const char& c) -> int { return c - '0'; };

	std::vector<std::vector<int>> map( y_size * sizeMultiplier,
					 std::vector<int>( x_size * sizeMultiplier, 0) );

	for(size_t y = 0UL; y < y_size * sizeMultiplier; ++y) { // y
		for(size_t x = 0UL; x < x_size * sizeMultiplier; ++x) { // x
			auto val = charToInt( lines.at(y % y_size).at(x % x_size) );
			auto modifiedVal = ( val + int(x / x_size) + int(y / y_size) );
			auto boundedVal = (modifiedVal % 10) + static_cast<int>(modifiedVal >= 10); // this is dumb
			map.at(y).at(x) = boundedVal;
		}
	}
	
	return FindLeastRiskyPath(map);
}

} // namespace solutions