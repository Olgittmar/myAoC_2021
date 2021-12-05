#include "MyAoC_2021/solutions/Solution_3_2.h"

#include <iostream>

#include "MyAoC_2021/utils/StringSplit.h"
#include "MyAoC_2021/solutions/Solution_3_1.h"

namespace solutions {

int
SubmarineLifeSupportRating(const std::string& input)
{
    auto bitstrings = utils::SplitString(input, '\n');
    auto buckets = TallyChars(bitstrings);
    auto onesTrend = FilterTrend(buckets, true, '1');
    auto zerosTrend = FilterTrend(buckets, false, '0');

    auto oxygenBitstrings = bitstrings;
    auto co2Bitstrings = bitstrings;

    auto oxygenLvlBits = FilterBitsByTrend(oxygenBitstrings, onesTrend);
    auto co2LvlBits = FilterBitsByTrend(co2Bitstrings, zerosTrend);

    auto oxygenGeneratorRating = std::stoi(oxygenLvlBits, nullptr, 2);
    auto co2ScrubberRating = std::stoi(co2LvlBits, nullptr, 2);

    std::cout << "o2GenRating: " << oxygenLvlBits << " = " << oxygenGeneratorRating << std::endl;
    std::cout << "co2ScrubRating: " << co2LvlBits << " = " << co2ScrubberRating << std::endl;
    return oxygenGeneratorRating * co2ScrubberRating;
}


//! Wrong order, filtering should be done per position, which affects tallies!
std::string
FilterBitsByTrend(std::vector<std::string>& bitstrings, const std::string& trend)
{
    std::cout << "In FilterBitsByTrend" << std::endl;
    std::cout << "trend: " << trend << std::endl;
    auto bitstringLength = bitstrings[0].size();
    for (size_t i = 0; i < bitstringLength; ++i){
        for(auto it = bitstrings.begin(); it != bitstrings.end();){
            if( it->at(i) != trend[i] ){
                std::cout << "removing " << *it << " due to no " << trend[i] << " at position " << i + 1 << std::endl;
                it = bitstrings.erase(it);
                if(bitstrings.size() <= 1){
                    std::cout << "Done filtering!" << std::endl;
                    goto Filtered;
                }
            } else {
                ++it;
            }
        }
    }
    Filtered:
    if(bitstrings.size() > 1){
        std::cerr << "Warning: there is more than one match after filtering" << std::endl;
        for(auto it = bitstrings.cbegin(); it != bitstrings.cend(); ++it){
            std::cerr << *it << std::endl;
        }
    }
    return bitstrings[0];
}

std::vector<std::unordered_map<char, int>>
TallyChars(const std::vector<std::string>& strings)
{
    std::cout << "In TallyChars" << std::endl;
    if(strings.size() == 0){
        throw std::invalid_argument("String vector to be tallied is empty!");
    }

    std::vector<std::unordered_map<char,int>> _ret;
    _ret.resize(strings[0].size());
    std::cout << "Tallying " << _ret.size() << " positions" << std::endl;
    
    // For every position, tally the chars encountered in that position
    // When all strings have been tallied, find the char with highest occurrance
    // and put it in position i of the return string.
    for(size_t i = 0; i < _ret.size(); ++i){
        std::unordered_map<char, int> buckets;

        for(auto it = strings.cbegin(); it != strings.cend(); ++it){
            buckets[it->at(i)] += 1;
        }

        _ret[i] = buckets;
    }

    return _ret;
}

std::string
FilterTrend(const std::vector<std::unordered_map<char,int>>& buckets, bool filterByMostCommon, const char& tieBreaker)
{
    std::cout << "in FilterTrend" << std::endl;
    std::string _ret;
    _ret.resize(buckets.size());
    
    // For every position, tally the chars encountered in that position
    // When all strings have been tallied, find the char with highest occurrance
    // and put it in position i of the return string.
    for(size_t i = 0; i < _ret.size(); ++i){
        auto bucketIt = buckets.at(i).cbegin();

        std::pair<char, int> trend = *(bucketIt++);
        
        for(; bucketIt != buckets.at(i).cend(); ++bucketIt){
            if( (bucketIt->second == tieBreaker
              && bucketIt->second == trend.second)
             || (filterByMostCommon
              && bucketIt->second > trend.second)
             || (!filterByMostCommon
              && bucketIt->second < trend.second) ) {
                trend = *bucketIt;
            }
        }
        _ret[i] = trend.first;
    }
    return _ret;
}

}