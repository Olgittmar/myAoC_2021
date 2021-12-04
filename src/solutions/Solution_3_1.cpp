#include "MyAoC_2021/solutions/Solution_3_1.h"

#include <iostream>
#include "MyAoC_2021/utils/StringSplit.h"

namespace solutions {

// TODO: Not very elegant, need to refactor a bit.
int
SubmarinePowerConsumption(const std::string& str)
{
    auto input = utils::SplitString(str, '\n');

    auto tallyResult = TallyOnes(input);
    auto gamma = std::stoi(tallyResult.first, nullptr, 2);
    auto epsilon = std::stoi(tallyResult.second, nullptr, 2);

    return gamma * epsilon;
}

std::pair<std::string, std::string>
TallyOnes(const std::vector<std::string>& bitstrings)
{
    std::pair<std::string,std::string> _ret;
    std::vector<int> buckets;
    int numRows = 0;
    auto it = bitstrings.cbegin();
    buckets.assign(it->size(), 0);

    // count number of '1's in each position.
    for(; it != bitstrings.cend(); ++it){
        // Keep track of the total number of lines so we can determine if '1' is more common
        ++numRows;
        for( std::size_t i = 0; i < it->size(); ++i ){
            // "Is the i:th element of the substring a '1'? If so, add 1 to the bucket"
            buckets[i] += static_cast<int>( (*it)[i] == '1' );
        }
    }

    for(auto bucketIt = buckets.cbegin(); bucketIt != buckets.cend(); ++bucketIt){
        // If at least half of the bits are 1s, then 1 is most common
        if(*bucketIt >= numRows/2){
            _ret.first.push_back('1');
            _ret.second.push_back('0');
        } else {
            _ret.first.push_back('0');
            _ret.second.push_back('1');
        }
    }
    return _ret;
}

} // solutions