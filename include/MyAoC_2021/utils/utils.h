#ifndef MYAOC_2021_UTILS_UTILS_H
#define MYAOC_2021_UTILS_UTILS_H

#include "Constants.h"
#include "Coordinates.h"
#include "myConcepts.h"
#include "myMath.h"
#include "StringSplit.h"

#include <charconv>

namespace utils {

template<typename T> requires Streamable<T>
auto Print(T x, std::ostream& out = std::cout) -> std::ostream& { return out << x << '\n'; }

inline constexpr auto StringViewToInt(const std::string_view& strView, int base = 10) -> int {
	int result;
	auto resultCode = std::from_chars(strView.data(), strView.data() + strView.size(), result, base);
	if(resultCode.ec == std::errc::invalid_argument) {
		throw std::invalid_argument{"invalid_argument"};
	} else if(resultCode.ec == std::errc::result_out_of_range) {
		throw std::out_of_range{"out_of_range"};
	}
	return result;
}

inline constexpr auto StringViewToULong(const std::string_view& strView, int base = 10) -> ulong {
	ulong result;
	auto resultCode = std::from_chars(strView.data(), strView.data() + strView.size(), result, base);
	if(resultCode.ec == std::errc::invalid_argument) {
		throw std::invalid_argument{"invalid_argument"};
	} else if(resultCode.ec == std::errc::result_out_of_range) {
		throw std::out_of_range{"out_of_range"};
	}
	return result;
}

} // namespace utils

#endif