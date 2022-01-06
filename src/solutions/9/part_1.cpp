#include <9/part_1.h>

#include <algorithm>
#include <map>

#include <StringSplit.h>

namespace solutions
{

int SumRiskLevelOfLowPoints(const std::string_view& input)
{
	std::map<std::pair<int,int>, int> heightMap;
	auto lines = utils::SplitString(input, '\n');

	int row = 0;
	for(const auto& line : lines) {
		int column = 0;
		for(const char& c : line) {
			heightMap[{row, column}] = static_cast<int>(c - '0');
			++column;
		}
		++row;
	}

	int sumOfLowestPointsRiskLevel = 0;
	for(auto item : heightMap) {
		int numLargerNeighbours = 0;
		int numNeighbours = 0;

		// item.first.first == row
		// item.first.second == column
		// item.second == height
		std::pair<int,int> north{item.first.first - 1, item.first.second};
		std::pair<int,int> south{item.first.first + 1, item.first.second};
		std::pair<int,int> east{item.first.first, item.first.second + 1};
		std::pair<int,int> west{item.first.first, item.first.second - 1};

		numNeighbours += static_cast<int>( heightMap.contains(north));
		numNeighbours += static_cast<int>( heightMap.contains(south));
		numNeighbours += static_cast<int>( heightMap.contains(east));
		numNeighbours += static_cast<int>( heightMap.contains(west));

		numLargerNeighbours += static_cast<int>( heightMap.contains(north) && heightMap.at(north) > item.second );
		numLargerNeighbours += static_cast<int>( heightMap.contains(south) && heightMap.at(south) > item.second );
		numLargerNeighbours += static_cast<int>( heightMap.contains(east) && heightMap.at(east) > item.second );
		numLargerNeighbours += static_cast<int>( heightMap.contains(west) && heightMap.at(west) > item.second );

		sumOfLowestPointsRiskLevel += static_cast<int>(numLargerNeighbours >= numNeighbours) * (1 + item.second);
	}

	return sumOfLowestPointsRiskLevel;
}

} // namespace solutions
