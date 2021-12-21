#ifndef STRING_SPLIT_H
#define STRING_SPLIT_H

#include <vector>
#include <string>
#include <string_view>

#include "MyAoC_2021/utils/Constants.h"

namespace utils {

[[maybe_unused]] [[maybe_unused]]
std::vector<std::string_view> SplitString(const std::string_view& str, const char& delim, bool greedy = true);

[[maybe_unused]] [[maybe_unused]]
std::vector<int> SplitStringToInt(const std::string_view& str, const char& delim, bool greedy = true, int base = utils::magic10); // NOLINT(*-magic-numbers)

[[maybe_unused]] [[maybe_unused]]
int StringViewToInt(const std::string_view& strView, int base = utils::magic10); // NOLINT(*-magic-numbers)

}

#endif