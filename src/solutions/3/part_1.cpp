#include <3/part_1.h>

#include <StringSplit.h>
#include <algorithm>
#include <iostream>

namespace solutions {

// cppcheck-suppress unusedFunction
auto SubmarinePowerConsumption(const std::string_view& str) -> int
{
    auto input = utils::SplitString(str, '\n');

    auto onesTrend = TallyOnes(input);
    auto gamma = std::stoi(onesTrend, nullptr, 2);
    auto zerosTrend = FlipBitsInBitstring(onesTrend); // faster than option below?
    // auto zerosTrend = TallyChar(input, '0');
    auto epsilon = std::stoi(zerosTrend, nullptr, 2);

    return gamma * epsilon;
}

auto
FlipBitsInBitstring(const std::string_view& bitstring) -> std::string
{
    std::string _ret;
    std::transform(bitstring.cbegin(), bitstring.cend(), std::back_inserter(_ret),
        [](auto c){ return (c == '1' ? '0' : '1'); });
    return _ret;
}

auto
TallyOnes(const std::vector<std::string_view>& bitstrings) -> std::string
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

    for(auto bucket : buckets){
        // If at least half of the bits are 1s, then c is most common
        if(bucket >= numRows/2){
            _ret.push_back('1');
        } else {
            _ret.push_back('0');
        }
    }
    return _ret;
}

} // namespace solutions