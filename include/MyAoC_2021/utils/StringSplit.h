#ifndef STRING_SPLIT_H
#define STRING_SPLIT_H

#include <string>
#include <string_view>
#include <vector>

#include <Constants.h>

namespace utils {

[[maybe_unused]]
auto SplitString(const std::string_view& str, const char& delim, bool greedy = true) -> std::vector<std::string_view>;

[[maybe_unused]]
auto SplitStringToInt(const std::string_view& str, const char& delim, bool greedy = true, int base = 10) -> std::vector<int>;

[[maybe_unused]]
auto SplitStringToULong(const std::string_view& str, const char& delim, bool greedy = true, int base = 10) -> std::vector<ulong>;

[[maybe_unused]]
auto StringViewToInt(const std::string_view& strView, int base = 10) -> int;

[[maybe_unused]]
auto StringViewToULong(const std::string_view& strView, int base = 10) -> ulong;

} // namespace utils

#endif