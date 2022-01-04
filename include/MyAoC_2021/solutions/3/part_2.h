#ifndef SOLUTION_3_2_h
#define SOLUTION_3_2_h

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace solutions {

void FilterByTrend(std::unordered_set<std::string_view>& bitstrings, bool filterByMostCommon, const char& tiebreaker );
std::unordered_map<char,int> TallyCharsAtBitstringPosition(const std::unordered_set<std::string_view>& bitstrings, size_t pos);
void RemoveIfNotMatchingTrendAtPosition(std::unordered_set<std::string_view>& bitstrings, const char& c, size_t pos);

inline size_t GetBitstringLength(const std::unordered_set<std::string_view>& bitstrings) { return bitstrings.cbegin()->length(); } // not so nice hack to find length of all bitstrings
char GetCharByTrend(const std::unordered_map<char, int>& trend, bool searchForMostCommon, const char& tieBreaker);

// cppcheck-suppress unusedFunction
[[gnu::used]] [[maybe_unused]]
int SubmarineLifeSupportRating(const std::string_view& input);
}

#endif