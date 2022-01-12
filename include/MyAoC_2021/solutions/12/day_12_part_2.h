#ifndef MYAOC_2021_SOLUTIONS_12_DAY_12_12_PART_2_H
#define MYAOC_2021_SOLUTIONS_12_DAY_12_12_PART_2_H

#include <algorithm>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <string_view>
#include <vector>

#include <utils/StringSplit.h>

namespace solutions {

inline auto NumTimesVisited(const std::string_view& caveId, const std::string_view& path) -> long {
	long numTimesVisited = 0L;
	auto pos = 0UL;
	while ( (pos = path.find(caveId, pos) ) != std::string_view::npos) {
		++numTimesVisited;
	}
	return numTimesVisited;
}

void NumValidPathsWithExtraSmallCaveVisit(unsigned long& numPaths, std::deque<std::pair<std::string, bool>>& paths,
	const std::map<std::string, std::set<std::string>>& caveMap);

auto FindNumCavePathsWithExtraVisit(const std::string_view& input) -> unsigned long;

} // namespace solutions

#endif