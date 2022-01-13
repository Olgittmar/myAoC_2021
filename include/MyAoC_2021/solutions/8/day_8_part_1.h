#ifndef MYAOC_2021_SOLUTIONS_8_DAY_8_PART_1_H
#define MYAOC_2021_SOLUTIONS_8_DAY_8_PART_1_H

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