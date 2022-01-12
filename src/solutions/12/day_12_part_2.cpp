#include <solutions/12/day_12_part_2.h>

#include <solutions/12/day_12_part_1.h>

#include <utils/StringSplit.h>

namespace solutions {

void NumValidPathsWithExtraSmallCaveVisit(
	unsigned long& numPaths,
	[[maybe_unused]] std::deque<std::vector<std::string>>& paths,
	[[maybe_unused]] const std::map<std::string, std::set<std::string>>& caveMap)
{
	static const std::string _start{"start"};
	static const std::string _end{"end"};

	// Something something small cave
	while (!paths.empty())
	{
		auto path = paths.front();
		paths.pop_front();

		if(path.back() == _end){
			++numPaths;
			continue;
		}

		bool hasVisitedSmallCaveTwice = HasSmallCaveVisitedTwice(path);
		
		for(const auto& cave : caveMap.at(path.back())) {
			if(cave == _start) {
				continue;
			}

			bool isSmall = IsSmall(cave);

			if(hasVisitedSmallCaveTwice && isSmall && IsVisited(cave, path)) {
				continue;
			}

			std::vector<std::string> tmpCpy{path};
			tmpCpy.emplace_back(cave);
			paths.emplace_back(tmpCpy);
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
	std::deque<std::vector<std::string>> paths = {};
	paths.emplace_back( std::vector<std::string>({_start}) );
	NumValidPathsWithExtraSmallCaveVisit(numPaths, paths, caveMap);

	return numPaths;
}

} // namespace solutions