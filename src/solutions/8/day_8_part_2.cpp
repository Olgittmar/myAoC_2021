#include <solutions/8/day_8_part_2.h>

#include <cmath>
#include <iostream>
#include <string_view>

#include <utils/StringSplit.h>
#include <utils/myMath.h>

namespace solutions
{

inline auto
CodeToNumberMapper::Intersect(const std::string_view& str1, const std::string_view& str2) -> std::string
{
	std::string _ret;
	std::copy_if(str1.cbegin(), str1.cend(), std::back_inserter(_ret),
		[&](const char& c) -> bool { return str2.find(c) != std::string_view::npos; });
	return _ret;
}
	
inline auto
CodeToNumberMapper::Difference(const std::string_view& str1, const std::string_view& str2) -> std::string
{
	std::string _ret;
	std::copy_if(str1.cbegin(), str1.cend(), std::back_inserter(_ret),
		[&](const char& c) -> bool { return str2.find(c) == std::string_view::npos; });
	return _ret;
}

template<>
auto
CodeToNumberMapper::DetermineAmbiguousDigit<5UL>(const std::string_view& code) -> int
{
	// size == 5 means it's either a 2, 3 or 5
	if(IsEquivalent(code, m_2)){ return 2; }
	if(IsEquivalent(code, m_3)){ return 3; }
	if(IsEquivalent(code, m_5)){ return 5; }

	// Rule of exclusion
	if( !m_3.empty() && !m_5.empty() ) {
		m_2 = code;
		return 2;
	}
	
	if( !m_2.empty() && !m_5.empty() ) {
		m_3 = code;
		return 3;
	}

	if( !m_2.empty() && !m_3.empty() ) {
		m_5 = code;
		return 5;
	}

	if( !m_1.empty() ){
		std::string inter = Intersect(code, m_1);
		if(inter.size() == 2UL){
			m_3 = code;
			return 3;
		}
	}

	if( !m_4.empty() ){
		std::string diff = Difference(code, m_4);
		if(diff.size() == 3UL){
			m_2 = code;
			return 2;
		}
	}

	if( !m_7.empty() ) {
		std::string inter = Intersect(code, m_7);
		if(inter.size() == 3UL){
			m_3 = code;
			return 3;
		}
	}

	if( (!m_1.empty() && !m_4.empty())
	 || (!m_4.empty() && !m_7.empty()) ) {
		m_5 = code;
		return 5;
	}

	return -1;
}

template<>
auto
CodeToNumberMapper::DetermineAmbiguousDigit<6UL>(const std::string_view& code) -> int
{
	// size == 6 means it's either a 0, 6 or 9
	if(IsEquivalent(code, m_0)){ return 0; }
	if(IsEquivalent(code, m_6)){ return 6; }
	if(IsEquivalent(code, m_9)){ return 9; }

	// Rule of exclusion
	if( !m_6.empty() && !m_9.empty() ){
		m_0 = code;
		return 0;
	}
	
	if( !m_0.empty() && !m_9.empty() ){
		m_6 = code;
		return 6;
	}
	
	if( !m_0.empty() && !m_6.empty() ){
		m_9 = code;
		return 9;
	}

	if( !m_1.empty() ){
		std::string inter = Intersect(code, m_1);
		if(inter.size() == 1UL){
			m_6 = code;
			return 6;
		}
	}

	if( !m_4.empty() && IsSubsetOf(m_4, code) ){
		m_9 = code;
		return 9;
	}

	if( !m_7.empty() ) {
		std::string inter = Intersect(code, m_7);
		if(inter.size() == 2UL){
			m_6 = code;
			return 6;
		}
	}

	if( (!m_1.empty() && !m_4.empty())
	 || (!m_4.empty() && !m_7.empty()) ) {
		// We have already checked for 6 and 9, so if we got here, it must be a 0.
		m_0 = code;
		return 0;
	}

	return -1;
}

auto
CodeToNumberMapper::ConvertToDigit(const std::string_view& code) -> int
{
	switch (code.size())
	{
	case 2UL:
		if( m_1.empty() ) { m_1 = code; }
		return 1;
	case 3UL:
		if( m_7.empty() ) { m_7 = code; }
		return 7;
	case 4UL:
		if( m_4.empty() ) { m_4 = code; }
		return 4;
	case 7UL:
		// 8 is just all
		return 8;
	case 5UL:
	{
		// It's either a 2, 3 or 5
		return DetermineAmbiguousDigit<5UL>(code);
	}
	case 6UL:
	{
		// It's either a 0, 6 or 9
		return DetermineAmbiguousDigit<6UL>(code);
	}
	default:
		break;
	}

	return -1;
}

auto
SumOfJumbledCodes(const std::string_view& input) -> int
{
	// TODO: Template for this syntax
	// auto [in, out] = utils::SplitString(input, '|');
	auto lines = utils::SplitString(input, '\n');
	int totalSum = 0;

	for(auto line : lines) {
		auto lineData = utils::SplitString(line, '|');
		auto inCodes = utils::SplitString(lineData.at(0), ' ');
		auto outCodes = utils::SplitString(lineData.at(1), ' ');

		std::vector<std::string_view> deferred{};
		CodeToNumberMapper codeMapper{};
		
		for(auto code : inCodes) {
			if( codeMapper.ConvertToDigit(code) == -1 ) {
				deferred.push_back(code);
			}
		}

		for(auto code : deferred) {
			if( codeMapper.ConvertToDigit(code) == -1 ) {
				std::cerr << "Failed to decode \"" << code << " on second try\"" << '\n';
			}
		}
		
		int value = 0;
		size_t digitPos = outCodes.size();
		for(auto code : outCodes) {
			value += codeMapper.ConvertToDigit(code) * static_cast<int>( utils::IntPowBase10(--digitPos) );
		}

		totalSum += value;
	}

	return totalSum;
}

} // namespace solutions
