#ifndef SOLUTION_3_1_H
#define SOLUTION_3_1_H

#include <string>
#include <vector>

namespace solutions {

auto TallyOnes(const std::vector<std::string_view>& bitstrings) -> std::string;
auto FlipBitsInBitstring(const std::string_view& bitstring) -> std::string;

// cppcheck-suppress unusedFunction
[[gnu::used]] [[maybe_unused]]
auto SubmarinePowerConsumption(const std::string_view& str) -> int;

} // namespace solutions

#endif