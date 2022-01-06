#ifndef SOLUTION_9_2
#define SOLUTION_9_2

#include <map>

#include <Constants.h>

namespace solutions
{

std::vector<std::pair<int,int>> GetLowPoints(const std::map<std::pair<int,int>, int>& heightMap);
// Orthogonal floodfill to find basin size
int GetBasinSize(const std::pair<int,int>& lowPoint, const std::map<std::pair<int,int>, int>& heightMap);

int ProductOfLargestBasinSizes(const std::string_view& input, size_t numLargestBasins);

}

#endif