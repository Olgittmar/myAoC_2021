#include <solutions/12/day_12_part_1.h>

#include <deque>
#include <map>
#include <numeric>
#include <string>
#include <vector>

#include <utils/StringSplit.h>

namespace solutions {

void
NumValidPaths(unsigned long& numPaths, std::deque<std::string>& paths, const std::map<std::string, std::set<std::string>>& caveMap)
{
	static const std::string _end{"end"};

	// Something something small cave
	while (!paths.empty())
	{
		auto path = paths.front();
		paths.pop_front();

		if(path.ends_with(_end)){
			++numPaths;
			continue;
		}

		auto lastDelimiterPos = path.rfind(',');
		auto lastVisited = path.substr(lastDelimiterPos == std::string::npos ? 0UL : lastDelimiterPos + 1UL);
		
		for( const auto& cave : caveMap.at(lastVisited) ) {
			if( IsSmall(cave) && IsVisited(cave, path)){
				continue;
			}
			paths.emplace_back(path + ',' + cave);
		}
	}
}

auto
FindNumCavePaths(const std::string_view& input) -> unsigned long
{
	static const std::string _start{"start"};

	auto data = utils::SplitString(input, '\n');
	std::map<std::string, std::set<std::string>> caveMap{};

	// Set up caveMap
	for(const auto& line : data) {
		auto caves = utils::SplitString(line, '-');
		std::string cave1{caves.at(0UL)};
		std::string cave2{caves.at(1UL)};

		caveMap[cave1].insert(cave2);
		caveMap[cave2].insert(cave1);
	}

	unsigned long numPaths = 0UL;
	std::deque<std::string> paths{_start};
	NumValidPaths(numPaths, paths, caveMap);

	return numPaths;
}

} // namespace solutions