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

std::pair<MovementType, int> StrToMovement(const std::string_view& str);

// cppcheck-suppress unusedFunction
[[gnu::used]] [[maybe_unused]]
int SubmarineNavigationProduct(const std::string_view& str);

}

#endif