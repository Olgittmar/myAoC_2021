#include <solutions/9/day_9_part_2.h>

#include <algorithm>
#include <deque>
#include <numeric>
#include <set>

#include <utils/StringSplit.h>

namespace solutions
{

auto
GetBasinSize(const std::pair<int,int>& lowPoint, const std::map<std::pair<int,int>, int>& heightMap) -> int
{
	int basinSize = 1;
	std::deque<std::pair<int,int>> queue{{lowPoint}};
	std::set<std::pair<int,int>> considered{lowPoint};

	auto checkDirection = [&](const std::pair<int,int>& dir, const std::pair<int,int>& ref) -> bool {
		if( !heightMap.contains(dir)
		 || considered.contains(dir)
		 || heightMap.at(dir) < heightMap.at(ref)
		 || heightMap.at(dir) >= 9 ) {
			 return false;
		}
		queue.push_back(dir);
		considered.insert(dir);
		return true;
	};

	while(!queue.empty()){
		const auto& currPoint = queue.front();

		std::pair<int, int> north{currPoint.first - 1, currPoint.second};
		std::pair<int, int> south{currPoint.first + 1, currPoint.second};
		std::pair<int, int> east{currPoint.first, currPoint.second + 1};
		std::pair<int, int> west{currPoint.first, currPoint.second - 1};

		basinSize += static_cast<int>( checkDirection(north, currPoint) );
		basinSize += static_cast<int>( checkDirection(south, currPoint) );
		basinSize += static_cast<int>( checkDirection(east, currPoint) );
		basinSize += static_cast<int>( checkDirection(west, currPoint) );

		queue.pop_front();
	}

	return basinSize;
}

auto
GetLowPoints(const std::map<std::pair<int,int>, int>& heightMap) -> std::vector<std::pair<int,int>>
{
	std::vector<std::pair<int,int>> _ret;
	for(auto item : heightMap) {
		int numLargerNeighbours = 0;
		int numNeighbours = 0;

		std::pair<int,int> north{item.first.first - 1, item.first.second};
		std::pair<int,int> south{item.first.first + 1, item.first.second};
		std::pair<int,int> east{item.first.first, item.first.second + 1};
		std::pair<int,int> west{item.first.first, item.first.second - 1};

		numNeighbours += static_cast<int>( heightMap.contains(north) );
		numNeighbours += static_cast<int>( heightMap.contains(south) );
		numNeighbours += static_cast<int>( heightMap.contains(east) );
		numNeighbours += static_cast<int>( heightMap.contains(west) );

		numLargerNeighbours += static_cast<int>( heightMap.contains(north) && heightMap.at(north) > item.second );
		numLargerNeighbours += static_cast<int>( heightMap.contains(south) && heightMap.at(south) > item.second );
		numLargerNeighbours += static_cast<int>( heightMap.contains(east) && heightMap.at(east) > item.second );
		numLargerNeighbours += static_cast<int>( heightMap.contains(west) && heightMap.at(west) > item.second );

		if( numLargerNeighbours >= numNeighbours ){
			_ret.push_back(item.first);
		}
	}
	return _ret;
}

auto
ProductOfLargestBasinSizes(const std::string_view& input, size_t numLargestBasins) -> int
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

	std::vector<int> basinSizes;
	auto lowPoints = GetLowPoints(heightMap);
	std::transform(lowPoints.begin(), lowPoints.end(), std::back_inserter(basinSizes),
		[&](const std::pair<int,int>& point){ return GetBasinSize(point, heightMap); });

	std::sort(basinSizes.begin(), basinSizes.end());

	if(basinSizes.size() > numLargestBasins){
		auto rIt = basinSizes.crbegin();
		int totalProduct = 1;
		for(size_t i = 0; i < numLargestBasins; ++i){
			totalProduct = totalProduct * *rIt;
			++rIt;
		}
		return totalProduct;
	}
	return std::accumulate(basinSizes.cbegin(), basinSizes.cend(), 1,
		[&](int P, int size){ return P*size; });
}

} // namespace solutions
