#ifndef SOLUTION_9_2
#define SOLUTION_9_2

#include <map>

#include <Constants.h>

namespace solutions
{

auto GetLowPoints(const std::map<std::pair<int,int>, int>& heightMap) -> std::vector<std::pair<int,int>>;
// Orthogonal floodfill to find basin size
auto GetBasinSize(const std::pair<int,int>& lowPoint, const std::map<std::pair<int,int>, int>& heightMap) -> int;

auto ProductOfLargestBasinSizes(const std::string_view& input, size_t numLargestBasins) -> int;

} // namespace solutions

#endif