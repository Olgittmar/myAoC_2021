#ifndef SOLUTION_8_1
#define SOLUTION_8_1

#include <string>
#include <vector>

#include "MyAoC_2021/utils/Constants.h"

namespace solutions
{

int GetNumberOfSegments(const std::string_view& code);

int GetNumberOfCodesOfUniqueLength(const std::vector<std::string_view>& data);
// Don't like this solution, it feels brute force-y
int GetNumberOfCodesOfUniqueLengthInOutput(const std::string_view& input);

}

#endif