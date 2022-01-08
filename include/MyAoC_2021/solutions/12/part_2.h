#ifndef SOLUTIONS_12_2
#define SOLUTIONS_12_2

#include <algorithm>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <string_view>
#include <vector>

namespace solutions {

inline auto NumTimesVisited(const std::string& caveId, const std::vector<std::string>& path) -> long {
	return std::count(path.cbegin(), path.cend(), caveId);
}

inline auto HasSmallCaveVisitedTwice(const std::vector<std::string>& path) -> bool {
	auto found = std::set<std::string>{path.cbegin(), path.cend()};
	return found.size() == path.size();
}

void NumValidPathsWithExtraSmallCaveVisit(unsigned long& numPaths, std::deque<std::vector<std::string>>& paths,
	const std::map<std::string, std::set<std::string>>& caveMap);

auto FindNumCavePathsWithExtraVisit(const std::string_view& input) -> unsigned long;

} // namespace solutions

#endif