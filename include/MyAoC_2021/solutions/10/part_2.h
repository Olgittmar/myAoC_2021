#ifndef SOLUTION_10_2
#define SOLUTION_10_2

#include <stack>

#include <Constants.h>

namespace solutions
{

constexpr inline unsigned long long CharCompletionScore(const char& c){
	switch (c) {
		case '(': return 1ULL;
		case '[': return 2ULL;
		case '{': return 3ULL;
		case '<': return 4ULL;
	default: break;
	}
	return 0ULL;
}

std::stack<char> AutoComplete(const std::string_view& line);

unsigned long long MiddleCompletedScore(const std::string_view& input);

}

#endif