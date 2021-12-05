#ifndef SOLUTION_3_2_h
#define SOLUTION_3_2_h

#include <vector>
#include <string>
#include <unordered_map>

namespace solutions {

int SubmarineLifeSupportRating(const std::string& input); // should create a Submarine namespace...
std::string FilterBitsByTrend(std::vector<std::string>& bitstrings, const std::string& trend);
// Assumes that all strings are of same size
std::vector<std::unordered_map<char, int>> TallyChars(const std::vector<std::string>& strings);
std::string FilterTrend(const std::vector<std::unordered_map<char,int>>& buckets, bool filterByMostCommon, const char& tieBreaker);

}

#endif