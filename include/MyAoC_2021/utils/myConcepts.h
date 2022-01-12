#ifndef MYAOC_2021_UTILS_MYCONSEPTS_H
#define MYAOC_2021_UTILS_MYCONSEPTS_H

#include <concepts>
#include <iostream>
#include <type_traits>

namespace utils {

template<typename T>
concept Streamable = requires (T x, std::ostream& out)
{
	{ out << x } -> std::same_as<std::ostream&>;
};

template<typename T>
concept RangeForLoopable = requires (T container)
{
	{ container.begin() } -> std::input_or_output_iterator;
	{ container.end() } -> std::input_or_output_iterator;
};

} // namespace utils

#endif