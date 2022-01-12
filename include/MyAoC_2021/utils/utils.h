#ifndef MYAOC_2021_UTILS_UTILS_H
#define MYAOC_2021_UTILS_UTILS_H

#include <utils/Constants.h>
#include <utils/Coordinates.h>
#include <utils/myConcepts.h>
#include <utils/myMath.h>
#include <utils/StringSplit.h>

namespace utils {

template<typename T> requires Streamable<T>
auto Print(T x, std::ostream& out = std::cout) -> std::ostream& { return out << x << '\n'; }

} // namespace utils

#endif