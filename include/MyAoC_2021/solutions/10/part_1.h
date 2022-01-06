#ifndef SOLUTION_10_1
#define SOLUTION_10_1


#include <Constants.h>

namespace solutions
{

constexpr inline int CharScore(const char& c){
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

char GetFirstIllegalChar(const std::string_view& line);

int SyntaxErrorScoreCorrupted(const std::string_view& input);

}

#endif