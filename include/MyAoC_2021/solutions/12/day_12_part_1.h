#ifndef MYAOC_2021_SOLUTIONS_12_DAY_12_12_PART_1_H
#define MYAOC_2021_SOLUTIONS_12_DAY_12_12_PART_1_H

#include <algorithm>
#include <cctype>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <string_view>

namespace solutions {

inline auto IsSmall(const std::string& caveId) -> bool {
	return std::all_of(caveId.cbegin(), caveId.cend(),
		[](const char& c){ return std::islower(c); });
}

inline auto IsVisited(const std::string& caveId, const std::vector<std::string>& path) -> bool {
	return std::any_of(path.cbegin(), path.cend(),
		[&caveId](const std::string& str) -> bool { return str == caveId; });
}

void NumValidPaths(unsigned long& numPaths, std::deque<std::vector<std::string>>& paths, const std::map<std::string, std::set<std::string>>& caveMap);

auto FindNumCavePaths(const std::string_view& input) -> unsigned long;

} // namespace solutions

#endif