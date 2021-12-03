#include "MyAoC_2021/solutions/Solution_1_1.h"

#include "MyAoC_2021/utils/StringSplit.h"

#include <iostream>

namespace solutions {

int
CountNumIncreasing(const std::string& str)
{
    auto input = utils::SplitStringToInt(str, '\n');
    
    // Special case
    if( input.size() == 2 ){
        return static_cast<int>(input[0] < input[1]);
    } else if(input.size() < 2){
        return 0;
    }

    int numLarger = 0;
    
    auto it = input.cbegin();
    auto previous = *(it++);
    for(; it != input.cend(); it++ ) {
        // Add 1 if previous is smaller than current
        numLarger += static_cast<int>(previous < *it);
        previous = *it;
    }

    return numLarger;
}

}