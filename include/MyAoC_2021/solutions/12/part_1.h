#ifndef SOLUTION_12_1
#define SOLUTION_12_1

#include <string_view>
#include <string>
#include <algorithm>
#include <cctype>
#include <set>
#include <deque>
#include <map>

namespace solutions {

inline bool IsSmall(const std::string& caveId) {
	return std::all_of(caveId.cbegin(), caveId.cend(),
		[](const char& c){ return std::islower(c); });
}

inline bool IsVisited(const std::string& caveId, const std::vector<std::string>& path) {
	return std::any_of(path.cbegin(), path.cend(),
		[&caveId](const std::string& str) -> bool { return str == caveId; });
}

void NumValidPaths(unsigned long& numPaths, std::deque<std::vector<std::string>>& paths, const std::map<std::string, std::set<std::string>>& caveMap);

unsigned long FindNumCavePaths(const std::string_view& input);

}

#endif