#include <utils/myMath.h>

#include <array>
#include <utility>

namespace {

template<long long EXPONENT, long long NUM>
struct intPow {
    enum { value = EXPONENT * intPow<EXPONENT, NUM - 1>::value };
};

template <long long EXPONENT>
struct intPow<EXPONENT, 0> {
    enum { value = 1 };
};

template <std::size_t ... Indices>
constexpr auto genBaseTenTable([[maybe_unused]] std::index_sequence<Indices...> _) {
    return std::array<long long, 19>{ (intPow<10,Indices>::value)... }; // NOLINT
}

constexpr std::array<long long, 19> BaseTenlookupTable = genBaseTenTable(std::make_index_sequence<19>()); // NOLINT

} // namespace

namespace utils {

auto IntPowBase10(unsigned long n) -> long long {
    return BaseTenlookupTable.at(n);
}

} // namespace utils