#ifndef SOLUTION_6_2
#define SOLUTION_6_2

#include <string>
#include <array>

#include "MyAoC_2021/utils/Constants.h"

namespace solutions
{

inline constexpr void CountDownFish(std::array<ulong, utils::lanternfishDaysAfterInitialSpawn>& fishArray);

[[nodiscard]]
inline ulong CountTotalNumberOfFish(std::array<ulong, utils::lanternfishDaysAfterInitialSpawn>& fishArray);

[[gnu::used]] [[maybe_unused]]
ulong CalculateMassiveNumberOfLanternFishAfterNDays(const std::string& input , ulong numDays);

}

#endif