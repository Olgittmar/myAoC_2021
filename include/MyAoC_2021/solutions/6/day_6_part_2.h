#ifndef MYAOC_2021_SOLUTIONS_6_DAY_6_PART_2_H
#define MYAOC_2021_SOLUTIONS_6_DAY_6_PART_2_H

#include <array>
#include <string>

#include <utils/Constants.h>

namespace solutions
{

inline constexpr void CountDownFish(std::array<ulong, utils::lanternfishDaysAfterInitialSpawn>& fishArray);

[[nodiscard]]
inline auto CountTotalNumberOfFish(std::array<ulong, utils::lanternfishDaysAfterInitialSpawn>& fishArray) -> ulong;

[[gnu::used]] [[maybe_unused]]
auto CalculateMassiveNumberOfLanternFishAfterNDays(const std::string_view& input , ulong numDays) -> ulong;

} // namespace solutions

#endif