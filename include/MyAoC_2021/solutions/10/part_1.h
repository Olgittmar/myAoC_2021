#ifndef SOLUTION_10_1
#define SOLUTION_10_1


#include <Constants.h>

namespace solutions
{

constexpr inline auto CharScore(const char& c) -> int {
	switch (c) {
		case '\0': return 0;
		case ')': return 3;
		case ']': return 57;
		case '}': return 1197;
		case '>': return 25137;
	default: break;
	}
	return -1;
}

auto GetFirstIllegalChar(const std::string_view& line) -> char;

auto SyntaxErrorScoreCorrupted(const std::string_view& input) -> int;

} // namespace solutions

#endif