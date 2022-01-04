#include "MyAoC_2021/solutions/Solution_10_1.h"

#include <stack>

#include "MyAoC_2021/utils/StringSplit.h"

namespace solutions
{

char
GetFirstIllegalChar(const std::string_view& line)
{
	std::stack<char> charStack{};

	for(const char& c : line) // NOLINT
	{
		if(c == '(' || c == '[' || c == '{' || c == '<'){
			charStack.push(c);
			continue;
		}

		if( !charStack.empty() &&
		(   (c == ')' && charStack.top() == '(')
		 || (c == ']' && charStack.top() == '[')
		 || (c == '}' && charStack.top() == '{')
		 || (c == '>' && charStack.top() == '<') ))
		{
			charStack.pop();
			continue;
		}
		return c;
	}
	return '\0';
}

int
SyntaxErrorScoreCorrupted(const std::string_view& input)
{
	auto lines = utils::SplitString(input, '\n');
	int totalSyntaxScore = 0;
	for(const auto& line : lines) {
		auto illegalChar = GetFirstIllegalChar(line);
		totalSyntaxScore += CharScore(illegalChar);
	}
	return totalSyntaxScore;
}

} // namespace solutions
