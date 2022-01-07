#include <10/part_1.h>

#include <stack>

#include <StringSplit.h>

namespace solutions
{

auto
GetFirstIllegalChar(const std::string_view& line) -> char
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

auto
SyntaxErrorScoreCorrupted(const std::string_view& input) -> int
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
