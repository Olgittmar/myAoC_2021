#ifndef SOLUTION_11_1
#define SOLUTION_11_1

#include <array>

#include <Constants.h>

namespace solutions {

auto PropagateDumboFlashes(std::array<std::array<int, utils::dumboMapSize>, utils::dumboMapSize>& dumboMap ) -> ulong;
auto CountDumboFlashes(const std::string_view& input, ulong numSteps) -> ulong;

} // namespace solutions

#endif