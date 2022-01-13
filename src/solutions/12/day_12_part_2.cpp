#include <solutions/12/day_12_part_2.h>

#include <solutions/12/day_12_part_1.h>

#include <utils/utils.h>

namespace solutions {

void NumValidPathsWithExtraSmallCaveVisit(
	unsigned long& numPaths,
	[[maybe_unused]] std::deque<std::pair<std::string, bool>>& paths,
	[[maybe_unused]] const std::map<std::string, std::set<std::string>>& caveMap)
{
	static const std::string _start{"start"};
	static const std::string _end{"end"};

	// Something something small cave
	while (!paths.empty())
	{
		auto path = paths.front().first;
		bool hasVisitedSmallCaveTwice = paths.front().second;
		paths.pop_front();

		if( path.ends_with(_end) ){
			++numPaths;
			continue;
		}

		auto lastDelimiterPos = path.rfind(',');
		auto lastVisited = path.substr(lastDelimiterPos == std::string::npos ? 0UL : lastDelimiterPos + 1);
		
		auto caves = caveMap.at(lastVisited);

		for( const auto& cave : caves ) {
			if(cave == _start && path.size() > 1UL ) {
				continue;
			}

			bool willHaveVisitedSmallCaveTwice = hasVisitedSmallCaveTwice;
			if( IsSmall(cave) && IsVisited(cave, path) ) {
				if(hasVisitedSmallCaveTwice) {
					continue;
				}
				willHaveVisitedSmallCaveTwice = true;
			}

			auto next = std::pair<std::string, bool>{path + ',' + cave, hasVisitedSmallCaveTwice || willHaveVisitedSmallCaveTwice};
			paths.emplace_back(next);
		}
	}
}


auto
FindNumCavePathsWithExtraVisit([[maybe_unused]] const std::string_view& input) -> unsigned long
{
	static const std::string _start{"start"};

	auto data = utils::SplitString(input, '\n');
	auto caveMap = std::map<std::string, std::set<std::string>>();
	
	// Set up caveMap
	for(const auto& line : data) {
		auto caves = utils::SplitString(line, '-');
		std::string cave1{caves.at(0UL)};
		std::string cave2{caves.at(1UL)};

		caveMap[cave1].insert(cave2);
		caveMap[cave2].insert(cave1);
	}

	unsigned long numPaths = 0UL;
	std::deque<std::pair<std::string, bool>> paths{{_start, false}};
	NumValidPathsWithExtraSmallCaveVisit(numPaths, paths, caveMap);

	return numPaths;
}

} // namespace solutions