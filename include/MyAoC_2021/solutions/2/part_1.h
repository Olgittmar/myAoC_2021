#ifndef SOLUTION_2_1_H
#define SOLUTION_2_1_H

#include <string>

namespace solutions {

enum MovementType {
    HORIZONTAL, DEPTH
};

struct SubmarinePosition {
    int h_position = 0;
    int depth = 0;
};

auto StrToMovement(const std::string_view& str) -> std::pair<MovementType, int>;

// cppcheck-suppress unusedFunction
[[gnu::used]] [[maybe_unused]]
auto SubmarineNavigationProduct(const std::string_view& str) -> int;

} // namespace solutions

#endif