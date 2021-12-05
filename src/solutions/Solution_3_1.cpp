#include "MyAoC_2021/solutions/Solution_3_1.h"

#include <iostream>
#include "MyAoC_2021/utils/StringSplit.h"

namespace solutions {

int
SubmarinePowerConsumption(const std::string& str)
{
    auto input = utils::SplitString(str, '\n');

    auto onesTrend = TallyOnes(input);
    auto gamma = std::stoi(onesTrend, nullptr, 2);
    auto zerosTrend = FlipBitsInBitstring(onesTrend); // faster than option below?
    // auto zerosTrend = TallyChar(input, '0');
    auto epsilon = std::stoi(zerosTrend, nullptr, 2);

    return gamma * epsilon;
}

std::string
FlipBitsInBitstring(const std::string& bitstring)
{
    std::string _ret = bitstring;
    for(auto it = _ret.begin(); it != _ret.end(); ++it){
        *it = (*it == '1' ? '0' : '1');
    }
    return _ret;
}

std::string
TallyOnes(const std::vector<std::string>& bitstrings)
{
    std::string _ret;
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
        // If at least half of the bits are 1s, then c is most common
        if(*bucketIt >= numRows/2){
            _ret.push_back('1');
        } else {
            _ret.push_back('0');
        }
    }
    return _ret;
}

} // solutions