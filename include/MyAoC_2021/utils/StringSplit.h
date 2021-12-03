#ifndef STRING_SPLIT_H
#define STRING_SPLIT_H

#include <vector>
#include <string>
#include <string_view>

namespace utils {

std::vector<std::string> SplitString(const std::string& str, const char& delim);
std::vector<int> SplitStringToInt(const std::string& str, const char& delim);

}

#endif