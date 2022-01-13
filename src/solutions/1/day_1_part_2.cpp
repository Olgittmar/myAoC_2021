#include <solutions/1/day_1_part_2.h>

#include <utils/utils.h>

#include <iostream>

namespace solutions {

inline auto
SumLastThree(const std::vector<int>::const_iterator& it) -> int{
    return *(it - 2) + *(it - 1) + *it;
}

// cppcheck-suppress unusedFunction
auto CountIncreasingSlidingWindow(const std::string_view& str) -> int {
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

} // namespace solutions