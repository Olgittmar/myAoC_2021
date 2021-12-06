#ifndef SOLUTION_3_2_h
#define SOLUTION_3_2_h

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace solutions {

int SubmarineLifeSupportRating(const std::string& input); // should create a Submarine namespace...
void FilterByTrend(std::unordered_set<std::string>& bitstrings, bool filterByMostCommon, const char& tieBreaker );
std::unordered_map<char,int> TallyCharsAtBitstringPosition(const std::unordered_set<std::string>& bitstrings, size_t pos);
void RemoveIfNotMatchingTrendAtPosition(std::unordered_set<std::string>& bitstrings, const char& c, size_t pos);
inline size_t GetBitstringLength(const std::unordered_set<std::string>& bitstrings) { return bitstrings.cbegin()->length(); }
char GetCharByTrend(const std::unordered_map<char, int>& trend, bool searchForMostCommon, const char& tieBreaker);

}

#endif