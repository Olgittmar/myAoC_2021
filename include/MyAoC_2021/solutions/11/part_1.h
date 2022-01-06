#ifndef SOLUTION_11_1
#define SOLUTION_11_1

#include <array>

#include <Constants.h>

namespace solutions {

ulong PropagateDumboFlashes(std::array<std::array<int, utils::dumboMapSize>, utils::dumboMapSize>& dumboMap );
ulong CountDumboFlashes(const std::string_view& input, ulong numSteps);

}

#endif