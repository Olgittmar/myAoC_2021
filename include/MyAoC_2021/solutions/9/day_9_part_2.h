#ifndef MYAOC_2021_SOLUTIONS_9_DAY_9_PART_2_H
#define MYAOC_2021_SOLUTIONS_9_DAY_9_PART_2_H

#include <map>

#include <utils/Constants.h>

namespace solutions
{

auto GetLowPoints(const std::map<std::pair<int,int>, int>& heightMap) -> std::vector<std::pair<int,int>>;
// Orthogonal floodfill to find basin size
auto GetBasinSize(const std::pair<int,int>& lowPoint, const std::map<std::pair<int,int>, int>& heightMap) -> int;

auto ProductOfLargestBasinSizes(const std::string_view& input, size_t numLargestBasins) -> int;

} // namespace solutions

#endif