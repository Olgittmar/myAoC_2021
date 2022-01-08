#ifndef MYAOC_2021_SOLUTIONS_11_DAY_11_11_PART_1_H
#define MYAOC_2021_SOLUTIONS_11_DAY_11_11_PART_1_H

#include <array>

#include <utils/Constants.h>

namespace solutions {

auto PropagateDumboFlashes(std::array<std::array<int, utils::dumboMapSize>, utils::dumboMapSize>& dumboMap ) -> ulong;
auto CountDumboFlashes(const std::string_view& input, ulong numSteps) -> ulong;

} // namespace solutions

#endif