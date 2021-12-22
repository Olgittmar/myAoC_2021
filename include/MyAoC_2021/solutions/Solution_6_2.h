#ifndef SOLUTION_6_2
#define SOLUTION_6_2

#include <string>
#include <vector>
#include <deque>

namespace solutions
{

[[nodiscard]]
inline constexpr ulong CountLanternfishChildrenSpawned(ulong initialAge, ulong currentDay, ulong numDays, std::deque<std::pair<ulong,ulong>>& queue);

[[gnu::used]] [[maybe_unused]]
ulong CalculateMassiveNumberOfLanternFishAfterNDays(const std::string& input , ulong numDays);

}

#endif