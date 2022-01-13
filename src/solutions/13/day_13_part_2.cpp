#include <solutions/13/day_13_part_2.h>

#include <solutions/13/day_13_part_1.h>

#include <utils/utils.h>

namespace solutions {

auto PrintCodeFromDottedPaper(const std::string_view& input, int numFolds) -> std::string
{
	auto separatorPos = input.find("\n\n");
	auto coordData = input.substr(0UL, separatorPos);
	auto foldInstructions = input.substr(separatorPos +2UL);

	auto coordLines = utils::SplitString(coordData, '\n');

	std::unordered_set<utils::Coordinate2D> coords{};

	for(const auto& line : coordLines) {
		auto coordVec = utils::SplitStringToInt(line, ',');
		utils::Coordinate2D coord{ coordVec.at(0UL), coordVec.at(1UL) };

		coords.insert(coord);
	}

	solutions::FoldDottedPaper(coords, foldInstructions, numFolds);

	// Find the dimensions after folding
	int x_max = 0;
	int y_max = 0;
	for(const auto& coord : coords) {
		x_max = std::max(x_max, coord.x());
		y_max = std::max(y_max, coord.y());	
	}

	// paper is folded, now we gotta figure out what is says.
	std::vector<std::string> codeStrings{size_t(y_max + 1), std::string(size_t(x_max + 1), ' ')};
	for(const auto& coord : coords) {
		codeStrings.at( size_t(coord.y()) ).at( size_t(coord.x()) ) = '#';
	}
	
	std::string _ret{};
	for(size_t i = 0UL; i < codeStrings.size(); ++i) {
		if(i != 0UL) {
			_ret += '\n';
		}
		_ret.append(codeStrings.at(i));
	}

	return _ret;
}

} // solutions