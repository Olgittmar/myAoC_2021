#ifndef SOLUTION_10_2
#define SOLUTION_10_2

#include <stack>

#include <Constants.h>

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