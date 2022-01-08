#ifndef MYAOC_2021_SOLUTIONS_12_DAY_12_12_PART_2_H
#define MYAOC_2021_SOLUTIONS_12_DAY_12_12_PART_2_H

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