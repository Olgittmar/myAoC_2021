#ifndef SOLUTION_3_1_H
#define SOLUTION_3_1_H

#include <vector>
#include <string>

namespace solutions {

std::string TallyOnes(const std::vector<std::string_view>& bitstrings);
std::string FlipBitsInBitstring(const std::string_view& bitstring);

// cppcheck-suppress unusedFunction
[[gnu::used]] [[maybe_unused]]
int SubmarinePowerConsumption(const std::string_view& str);

}

#endif