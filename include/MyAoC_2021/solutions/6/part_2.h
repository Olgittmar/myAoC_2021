#ifndef SOLUTION_6_2
#define SOLUTION_6_2

#include <string>
#include <array>

#include <Constants.h>

namespace solutions
{

inline constexpr void CountDownFish(std::array<ulong, utils::lanternfishDaysAfterInitialSpawn>& fishArray);

[[nodiscard]]
inline ulong CountTotalNumberOfFish(std::array<ulong, utils::lanternfishDaysAfterInitialSpawn>& fishArray);

[[gnu::used]] [[maybe_unused]]
ulong CalculateMassiveNumberOfLanternFishAfterNDays(const std::string_view& input , ulong numDays);

}

#endif