#include "MyAoC_2021/solutions/Solution_1_2.h"

#include "MyAoC_2021/utils/StringSplit.h"

#include <iostream>

namespace solutions {

inline int
SumLastThree(const std::vector<int>::const_iterator& it){
    return *(it - 2) + *(it - 1) + *it;
}

// cppcheck-suppress unusedFunction
int CountIncreasingSlidingWindow(const std::string_view& str) {
    int numberBase = 10; // NOLINT
    auto input = utils::SplitStringToInt(str, '\n', true, numberBase);
    if(input.size() <= 3){
        return 0;
    }
    auto front{input.cbegin() + 2};
    int previousSum = SumLastThree(front);
    int numIncreased = 0;

    while( ++front != input.cend() ){
        numIncreased += static_cast<int>( previousSum < SumLastThree(front) );
        previousSum = SumLastThree(front);

    }
    return numIncreased;
}

}