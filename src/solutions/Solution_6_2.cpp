#include "MyAoC_2021/solutions/Solution_6_2.h"

#include <iostream>
#include <numeric>
#include <algorithm>

#include "MyAoC_2021/utils/Constants.h"
#include "MyAoC_2021/utils/StringSplit.h"

namespace solutions
{

inline constexpr ulong CountLanternfishChildrenSpawned(ulong initialAge, ulong currentDay, ulong numDays, std::deque<std::pair<ulong,ulong>>& queue)
{
	ulong numSpawns = 0;
	ulong daysPassed = initialAge + currentDay;

	while( daysPassed < numDays ) {
		queue.emplace_back(utils::lanternfishDaysAfterInitialSpawn, daysPassed);
		daysPassed += utils::lanternfishSpawnInterval;
		++numSpawns;
	}

	return numSpawns;
}

// cppcheck-suppress unusedFunction
ulong CalculateMassiveNumberOfLanternFishAfterNDays(const std::string& input, ulong numDays)
{
	auto initialAges = utils::SplitStringToInt(input, ',');
	std::deque<std::pair<ulong,ulong>> fishQueue{};

	std::transform(initialAges.cbegin(), initialAges.cend(), std::back_inserter(fishQueue),
		[&](ulong age) -> std::pair<ulong,ulong> { return std::pair<ulong,ulong>{age, 0UL}; });

	auto numSpawned = initialAges.size();

	while( !fishQueue.empty() ){
		auto [age, spawnedAtDay] { fishQueue.front() };
		numSpawned += CountLanternfishChildrenSpawned(age, spawnedAtDay, numDays, fishQueue);
		fishQueue.pop_front();
	}

	return numSpawned;
}


}
