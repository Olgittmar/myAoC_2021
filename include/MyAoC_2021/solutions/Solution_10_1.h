#ifndef SOLUTION_10_1
#define SOLUTION_10_1


#include "MyAoC_2021/utils/Constants.h"

namespace solutions
{

enum CharPos : size_t {
PARENTHESIS = 0UL,
SQUARE = 1UL,
CURLY = 2UL,
ANGLE = 3UL
};

constexpr inline char PosToChar(size_t pos){
	switch (pos) {
	case 0UL:
		return ')';
	case 1UL:
		return ']';
	case 2UL:
		return '}';
	case 3UL:
		return '>';
	default:
		break;
	}
	return '\n';
}

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