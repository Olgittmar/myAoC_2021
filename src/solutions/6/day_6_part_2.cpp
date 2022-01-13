#include <solutions/6/day_6_part_2.h>

#include <iostream>
#include <numeric>

#include <utils/utils.h>

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

inline auto CountTotalNumberOfFish(std::array<ulong,utils::lanternfishDaysAfterInitialSpawn>& fishArray) -> ulong
{
	return std::accumulate(fishArray.cbegin(), fishArray.cend(), 0UL);
}

// cppcheck-suppress unusedFunction
auto CalculateMassiveNumberOfLanternFishAfterNDays(const std::string_view& input, ulong numDays) -> ulong
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

} // namespace solutions
