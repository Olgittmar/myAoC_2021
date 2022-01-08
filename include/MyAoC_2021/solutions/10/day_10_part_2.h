#ifndef MYAOC_2021_SOLUTIONS_10_DAY_10_10_PART_2_H
#define MYAOC_2021_SOLUTIONS_10_DAY_10_10_PART_2_H

#include <stack>

#include <utils/Constants.h>

namespace solutions
{

constexpr inline auto CharCompletionScore(const char& c) -> unsigned long long {
	switch (c) {
		case '(': return 1ULL;
		case '[': return 2ULL;
		case '{': return 3ULL;
		case '<': return 4ULL;
	default: break;
	}
	return 0ULL;
}

auto AutoComplete(const std::string_view& line) -> std::stack<char>;

auto MiddleCompletedScore(const std::string_view& input) -> unsigned long long;

} // namespace solutions

#endif