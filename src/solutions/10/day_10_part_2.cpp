#include <solutions/10/day_10_part_2.h>

#include <utils/StringSplit.h>

namespace solutions
{

auto
AutoComplete(const std::string_view& line) -> std::stack<char>
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
		// Should probably throw but can't be bothered to set up exception handling..
		return std::stack<char>{};
	}
	return charStack;
}

auto
MiddleCompletedScore(const std::string_view& input) -> unsigned long long
{
	auto lines = utils::SplitString(input, '\n');
	std::vector<unsigned long long> scores{};
	for(const auto& line : lines) {
		unsigned long long syntaxScore = 0ULL;
		auto missingCharSequence = AutoComplete(line);
		if(missingCharSequence.empty()){
			continue;
		}
		while(!missingCharSequence.empty()){
			const char& c = missingCharSequence.top();
			syntaxScore = syntaxScore * 5ULL + CharCompletionScore(c);
			missingCharSequence.pop();
		}
		scores.push_back(syntaxScore);
	}

	std::sort(scores.begin(), scores.end());
	unsigned long long middleSyntaxScore = scores.at( scores.size()/2UL );
	return middleSyntaxScore;
}

} // namespace solutions
