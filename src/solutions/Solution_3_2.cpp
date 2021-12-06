#include "MyAoC_2021/solutions/Solution_3_2.h"

#include <iostream>

#include "MyAoC_2021/utils/StringSplit.h"
#include "MyAoC_2021/solutions/Solution_3_1.h"

namespace solutions {

int
SubmarineLifeSupportRating(const std::string& input)
{
    auto bitstrings = utils::SplitString(input, '\n');

    std::unordered_set<std::string> onesBitstrings( bitstrings.cbegin(), bitstrings.cend() );
    std::unordered_set<std::string> zerosBitstrings( bitstrings.cbegin(), bitstrings.cend() );

    FilterByTrend(onesBitstrings, true, '1');
    FilterByTrend(zerosBitstrings, false, '0');

    auto oxygenLvlBits = *(onesBitstrings.cbegin());
    auto co2LvlBits = *(zerosBitstrings.cbegin());

    auto oxygenGeneratorRating = std::stoi(oxygenLvlBits, nullptr, 2);
    auto co2ScrubberRating = std::stoi(co2LvlBits, nullptr, 2);

    return oxygenGeneratorRating * co2ScrubberRating;
}


void
FilterByTrend(std::unordered_set<std::string>& bitstrings, bool filterByMostCommon, const char& tiebreaker)
{
    for(size_t i = 0; i < GetBitstringLength(bitstrings); ++i) {
        auto trend = TallyCharsAtBitstringPosition(bitstrings, i);
        auto trendingChar = GetCharByTrend(trend, filterByMostCommon, tiebreaker);
        RemoveIfNotMatchingTrendAtPosition(bitstrings, trendingChar, i);

        if(bitstrings.size() < 2){
            break; // no need to continue
        }
    }

    if(bitstrings.size() != 1){
        std::cerr << "Ended up with unexpected number of elements left over. bitstrings.size() =" << bitstrings.size() << std::endl;
    }
}

char
GetCharByTrend(const std::unordered_map<char, int>& trend, bool searchForMostCommon, const char& tieBreaker)
{
    auto it = trend.cbegin();
    auto trendingItem = it;
    for(; it != trend.cend(); ++it){
        // this got wierd...
        if( searchForMostCommon && it->second > trendingItem->second){}
        else if( !searchForMostCommon && it->second < trendingItem->second){}
        else if( it->first == tieBreaker && it->second == trendingItem->second ){}
        else {
            continue;
        }
        trendingItem = it;
    }
    return trendingItem->first;
}

std::unordered_map<char, int>
TallyCharsAtBitstringPosition(const std::unordered_set<std::string>& bitstrings, size_t pos)
{
    std::unordered_map<char,int> buckets;

    if( GetBitstringLength(bitstrings) <= pos) {
        throw std::out_of_range("pos >= length of bitstrings");
    }

    for(auto it = bitstrings.cbegin(); it != bitstrings.cend(); ++it) {
        buckets[it->at(pos)] += 1;
    }

    return buckets;
}

void
RemoveIfNotMatchingTrendAtPosition(std::unordered_set<std::string>& bitstrings, const char& c, size_t pos)
{
    // Should stop if there is only 1 item left...
    for(auto it = bitstrings.begin(); it != bitstrings.end();){
        if( it->at(pos) != c ){
            it = bitstrings.erase(it);
        } else {
            ++it;
        }
    }
}

}