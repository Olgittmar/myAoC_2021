#ifndef SOLUTION_8_1
#define SOLUTION_8_1

#include <string_view>
#include <vector>

namespace solutions
{

auto GetNumberOfSegments(const std::string_view& code) -> int;

auto GetNumberOfCodesOfUniqueLength(const std::vector<std::string_view>& data) -> int;
// Don't like this solution, it feels brute force-y
auto GetNumberOfCodesOfUniqueLengthInOutput(const std::string_view& input) -> int;

} // namespace solutions

#endif