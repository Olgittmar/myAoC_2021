#include "MyAoC_2021/solutions/Solution_6_1.h"

#include <numeric>
#include <algorithm>
#include <iostream>

#include "MyAoC_2021/utils/StringSplit.h"

namespace solutions
{

// cppcheck-suppress unusedFunction
int CalculateNumberOfLanternFishAfterNDays(const std::string& input, int numDays)
{
	auto initState = utils::SplitStringToInt(input, ',');
	std::vector<LanternFish> lanternFish;

	std::transform(initState.cbegin(), initState.cend(), std::back_inserter(lanternFish),
		[](int age) -> LanternFish { return LanternFish(age);});

	for(int i = 0; i < numDays; ++i) {
		const auto numNewFish = std::count_if(
			lanternFish.begin(), lanternFish.end(),
			[&](LanternFish& fish){ return fish.CountDown(); });
		
		lanternFish.resize(lanternFish.size() + static_cast<size_t>(numNewFish), LanternFish{});
	}

	return static_cast<int>(lanternFish.size());
}


}
