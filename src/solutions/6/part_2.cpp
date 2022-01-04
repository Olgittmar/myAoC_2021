#include "MyAoC_2021/solutions/6/part_2.h"

#include <iostream>
#include <numeric>

#include "MyAoC_2021/utils/StringSplit.h"

namespace solutions
{

inline constexpr void CountDownFish(std::array<ulong,utils::lanternfishDaysAfterInitialSpawn>& fishArray)
{
	auto timedOut = fishArray.at(0);
	for(size_t index = 1; index < fishArray.size(); ++index){
		fishArray.at(index - 1) = fishArray.at(index);
	}
	fishArray.at(utils::lanternfishDaysAfterInitialSpawn - 1) = timedOut;
	fishArray.at(utils::lanternfishSpawnInterval - 1) += timedOut;
}

inline ulong CountTotalNumberOfFish(std::array<ulong,utils::lanternfishDaysAfterInitialSpawn>& fishArray)
{
	return std::accumulate(fishArray.cbegin(), fishArray.cend(), 0UL);
}

// cppcheck-suppress unusedFunction
ulong CalculateMassiveNumberOfLanternFishAfterNDays(const std::string_view& input, ulong numDays)
{
	auto initialAges = utils::SplitStringToULong(input, ',');
	std::array<ulong,utils::lanternfishDaysAfterInitialSpawn> fishlist{0UL};

	for(auto fishAge : initialAges) {
		fishlist.at(fishAge) += 1;
	}

	for(ulong day = 0; day < numDays; ++day){
		CountDownFish(fishlist);
	}

	return CountTotalNumberOfFish(fishlist);
}

}
