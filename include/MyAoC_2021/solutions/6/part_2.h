#ifndef SOLUTION_6_2
#define SOLUTION_6_2

#include <array>
#include <string>

#include <Constants.h>

namespace solutions
{

inline constexpr void CountDownFish(std::array<ulong, utils::lanternfishDaysAfterInitialSpawn>& fishArray);

[[nodiscard]]
inline auto CountTotalNumberOfFish(std::array<ulong, utils::lanternfishDaysAfterInitialSpawn>& fishArray) -> ulong;

[[gnu::used]] [[maybe_unused]]
auto CalculateMassiveNumberOfLanternFishAfterNDays(const std::string_view& input , ulong numDays) -> ulong;

} // namespace solutions

#endif