#ifndef SOLUTION_8_2
#define SOLUTION_8_2

#include <string>
#include <algorithm>

#include <Constants.h>

namespace solutions
{

class CodeToNumberMapper {
  public:
	CodeToNumberMapper() = default;
	~CodeToNumberMapper() = default;
	CodeToNumberMapper(const CodeToNumberMapper& other) = default;
	CodeToNumberMapper(CodeToNumberMapper&& other) = default;

	CodeToNumberMapper& operator=(const CodeToNumberMapper& other) = default;
	CodeToNumberMapper& operator=(CodeToNumberMapper&& other) = default;

	int ConvertToDigit(const std::string_view& code);

  private:
	// Dangerous, we can't allow this object to outlive the strings pointed to by the members below.
	std::string_view m_0;
	std::string_view m_1;
	std::string_view m_2;
	std::string_view m_3;
	std::string_view m_4;
	std::string_view m_5;
	std::string_view m_6;
	std::string_view m_7;
	std::string_view m_9;

	// Returns true if str1 is a subset of str2
	[[nodiscard]] static inline bool IsSubsetOf(const std::string_view& str1, const std::string_view& str2) {
		return std::all_of(str1.cbegin(), str1.cend(),
			[&](const char& c){ return str2.find(c, 0UL) != std::string_view::npos; }); }

	// Returns true if str1 is canonically equivalent to str2
	[[nodiscard]] static inline bool IsEquivalent(const std::string_view& str1, const std::string_view& str2) {
		return IsSubsetOf(str1, str2) && str1.size() == str2.size(); }
	
	// Returns a string which contains the chars which are found in both str1 and str2
	[[nodiscard]] static inline std::string Intersect(const std::string_view& str1, const std::string_view& str2);
	
	// Returns a string which contains the char which are found in str1 but not str2
	[[nodiscard]] static inline std::string Difference(const std::string_view& str1, const std::string_view& str2);

	template <size_t S>
	[[nodiscard]] int DetermineAmbiguousDigit(const std::string_view& code);
};

int SumOfJumbledCodes(const std::string_view& input);

}

#endif