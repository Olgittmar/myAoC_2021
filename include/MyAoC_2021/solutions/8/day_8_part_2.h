#ifndef MYAOC_2021_SOLUTIONS_8_DAY_8_PART_2_H
#define MYAOC_2021_SOLUTIONS_8_DAY_8_PART_2_H

#include <algorithm>
#include <string>

namespace solutions
{

class CodeToNumberMapper {
  public:
	CodeToNumberMapper() = default;
	~CodeToNumberMapper() = default;
	CodeToNumberMapper(const CodeToNumberMapper& other) = default;
	CodeToNumberMapper(CodeToNumberMapper&& other) = default;

	auto operator=(const CodeToNumberMapper& other) -> CodeToNumberMapper& = default;
	auto operator=(CodeToNumberMapper&& other) -> CodeToNumberMapper& = default;

	auto ConvertToDigit(const std::string_view& code) -> int;

  private:
	// Dangerous, we can't allow this object to outlive the strings pointed to by the members below.
	std::string_view m_0{};
	std::string_view m_1{};
	std::string_view m_2{};
	std::string_view m_3{};
	std::string_view m_4{};
	std::string_view m_5{};
	std::string_view m_6{};
	std::string_view m_7{};
	std::string_view m_9{};

	// Returns true if str1 is a subset of str2
	[[nodiscard]]
	static inline auto IsSubsetOf(const std::string_view& str1, const std::string_view& str2) -> bool {
		return std::all_of(str1.cbegin(), str1.cend(),
			[&](const char& c){ return str2.find(c, 0UL) != std::string_view::npos; }); }

	// Returns true if str1 is canonically equivalent to str2
	[[nodiscard]]
	static inline auto IsEquivalent(const std::string_view& str1, const std::string_view& str2) -> bool {
		return IsSubsetOf(str1, str2) && str1.size() == str2.size(); }
	
	// Returns a string which contains the chars which are found in both str1 and str2
	[[nodiscard]]
	static inline auto Intersect(const std::string_view& str1, const std::string_view& str2) -> std::string;
	
	// Returns a string which contains the char which are found in str1 but not str2
	[[nodiscard]]
	static inline auto Difference(const std::string_view& str1, const std::string_view& str2) -> std::string;

	template <size_t S>
	[[nodiscard]]
	auto DetermineAmbiguousDigit(const std::string_view& code) -> int;
};

auto SumOfJumbledCodes(const std::string_view& input) -> int;

} // namespace solutions

#endif