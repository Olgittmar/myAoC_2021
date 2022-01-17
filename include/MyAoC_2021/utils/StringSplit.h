#ifndef MYAOC_2021_UTILS_STRINGSPLIT_H
#define MYAOC_2021_UTILS_STRINGSPLIT_H

#include <string>
#include <string_view>
#include <vector>

namespace utils {

[[maybe_unused]]
auto SplitString(const std::string_view& str, const char& delim, bool greedy = true) -> std::vector<std::string_view>;

[[maybe_unused]]
auto SplitString(const std::string_view& str, const std::string_view& delimStr) -> std::vector<std::string_view>;

[[maybe_unused]]
auto SplitStringToInt(const std::string_view& str, const char& delim, bool greedy = true, int base = 10) -> std::vector<int>;

[[maybe_unused]]
auto SplitStringToULong(const std::string_view& str, const char& delim, bool greedy = true, int base = 10) -> std::vector<ulong>;

} // namespace utils

#endif