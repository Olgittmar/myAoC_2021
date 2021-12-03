#ifndef SOLUTION_2_1_H
#define SOLUTION_2_1_H

#include <string>

namespace solutions {

const std::string ForwardStr = "forward ";
const std::string DownStr = "down ";
const std::string UpStr = "up ";

enum MovementType {
    HORIZONTAL, DEPTH
};

struct SubmarinePosition {
    int h_position = 0;
    int depth = 0;
};

int SubmarineNavigationProduct(const std::string& str);
std::pair<MovementType, int> StrToMovement(const std::string& str);

}

#endif