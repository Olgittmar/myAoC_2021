#include <1/part_1.h>

#include <StringSplit.h>

#include <iostream>
#include <string_view>

namespace solutions {

// cppcheck-suppress unusedFunction
auto CountNumIncreasing(const std::string_view& str) -> int
{
    auto input = utils::SplitStringToInt(str, '\n');
    
    // Special case
    if( input.size() == 2 ){
        return static_cast<int>(input[0] < input[1]);
    }
    if(input.size() < 2){
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

} // namespace solutions