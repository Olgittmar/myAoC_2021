#ifndef MYAOC_2021_SOLUTIONS_3_DAY_3_PART_2_H
#define MYAOC_2021_SOLUTIONS_3_DAY_3_PART_2_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace solutions {

void FilterByTrend(std::unordered_set<std::string_view>& bitstrings, bool filterByMostCommon, const char& tiebreaker );
auto TallyCharsAtBitstringPosition(const std::unordered_set<std::string_view>& bitstrings, size_t pos) -> std::unordered_map<char,int>;
void RemoveIfNotMatchingTrendAtPosition(std::unordered_set<std::string_view>& bitstrings, const char& c, size_t pos);

inline auto GetBitstringLength(const std::unordered_set<std::string_view>& bitstrings) -> size_t
	{ return bitstrings.cbegin()->length(); } // not so nice hack to find length of all bitstrings
auto GetCharByTrend(const std::unordered_map<char, int>& trend, bool searchForMostCommon, const char& tieBreaker) -> char;

// cppcheck-suppress unusedFunction
[[gnu::used]] [[maybe_unused]]
auto SubmarineLifeSupportRating(const std::string_view& input) -> int;

} // namespace solutions

#endif