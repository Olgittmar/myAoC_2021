#include <solutions/13/day_13_part_1.h>


namespace solutions {

void FoldDottedPaper(std::unordered_set<utils::Coordinate2D>& coords, const std::string_view& foldInstructions, int numFolds)
{
	static const std::string fold_along = "fold along ";
	auto timesFolded = 0;

	auto foldInstructionLines = utils::SplitString(foldInstructions, '\n');

	for(const auto& foldInstruction : foldInstructionLines)
	{
		if(numFolds != 0 && ++timesFolded > numFolds) { break; }
		if(foldInstruction.empty()) { break; }

		std::vector<utils::Coordinate2D> toBeRemoved{};
		std::vector<utils::Coordinate2D> toBeAdded{};
		
		// instruction[0] = axis, instruction[1] = pos
		auto instruction = utils::SplitString(foldInstruction.substr(fold_along.size()), '=');

		if(instruction.empty() || instruction.at(0UL).empty()) {
			continue;
		}

		for(auto coord : coords) {
			// Nicer way to do this?
			bool foldAlongX = instruction.at(0UL).find('x') != std::string_view::npos;
			bool foldAlongY = instruction.at(0UL).find('y') != std::string_view::npos;
			auto foldPos = utils::StringViewToInt(instruction.at(1UL));

			// Chunky! "y=n" -> insert(coord.x, folded_y) into set, then remove original
			if(foldAlongX) {
				if(coord.x() < foldPos) {
					continue;
				}
				auto posAfterFold = GetPosAfterFolding(coord.x(), foldPos);
				toBeAdded.emplace_back(posAfterFold, coord.y());
				toBeRemoved.emplace_back(coord);
			} else if(foldAlongY) {
				if(coord.y() < foldPos) {
					continue;
				}
				auto posAfterFold = GetPosAfterFolding(coord.y(), foldPos);
				toBeAdded.emplace_back(coord.x(), posAfterFold);
				toBeRemoved.emplace_back(coord);
			} else {
				utils::Print("Something went wrong!");
				continue;
			}
		}

		for (auto coord : toBeRemoved) {
			coords.erase(coord);
		}
		
		for (auto coord : toBeAdded) {
			coords.insert(coord);
		}
	}
}

auto DotsVisibleAfterNFolds(const std::string_view& input, int numFolds) -> ulong
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

	FoldDottedPaper(coords, foldInstructions, numFolds);

	return coords.size();
}

} // namespace solutions