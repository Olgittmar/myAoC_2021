#ifndef MYAOC_2021_SOLUTIONS_13_DAY_13_PART_1_H
#define MYAOC_2021_SOLUTIONS_13_DAY_13_PART_1_H

#include <cmath>
#include <string_view>
#include <unordered_set>

#include <utils/utils.h>

namespace solutions {

inline constexpr auto GetPosAfterFolding(int pos, int foldPos) -> int {
	return std::min(pos, foldPos - std::abs(pos - foldPos));
}

void FoldDottedPaper(std::unordered_set<utils::Coordinate2D>& coords, const std::string_view& foldInstructions, int numFolds);

auto DotsVisibleAfterNFolds(const std::string_view& input, int numFolds) -> ulong;

} // namespace solutions

#endif