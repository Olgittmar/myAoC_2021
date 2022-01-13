#ifndef MYAOC_2021_SOLUTIONS_12_DAY_12_PART_1_H
#define MYAOC_2021_SOLUTIONS_12_DAY_12_PART_1_H

#include <algorithm>
#include <cctype>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <string_view>

namespace solutions {

inline auto IsSmall(const std::string_view& caveId) -> bool {
	return std::all_of(caveId.cbegin(), caveId.cend(),
		[](const char& c){ return std::islower(c); });
}

inline auto IsVisited(const std::string_view& caveId, const std::string_view& path) -> bool {
	return path.find(caveId) != std::string_view::npos;
}

void NumValidPaths(unsigned long& numPaths, std::deque<std::string>& paths, const std::map<std::string, std::set<std::string>>& caveMap);

auto FindNumCavePaths(const std::string_view& input) -> unsigned long;

} // namespace solutions

#endif