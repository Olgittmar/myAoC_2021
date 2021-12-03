#include "MyAoC_2021/solutions/Solution_1_2.h"

#include "MyAoC_2021/utils/StringSplit.h"

#include <iostream>

namespace solutions {

inline int SumLastThree(std::vector<int>::const_iterator& it){
    return *(it - 2) + *(it - 1) + *it;
}

int CountIncreasingSlidingWindow(const std::string& str) {
    auto input = utils::SplitStringToInt(str, '\n');
    if(input.size() <= 3){
        return 0;
    }
    auto front = input.cbegin() + 2;
    int previousSum = SumLastThree(front);
    int numIncreased = 0;

    while( ++front != input.cend() ){
        numIncreased += static_cast<int>( previousSum < SumLastThree(front) );
        previousSum = SumLastThree(front);

    }
    return numIncreased;
}

}