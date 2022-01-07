#include <11/part_1.h>

#include <deque>

#include <StringSplit.h>

namespace solutions {

auto
PropagateDumboFlashes(std::array<std::array<int, utils::dumboMapSize>, utils::dumboMapSize>& dumboMap ) -> ulong
{
	ulong numFlashes = 0UL;
	std::array<std::array<bool, utils::dumboMapSize>, utils::dumboMapSize> flashMap{{{false}}};
	std::deque<std::pair<int, int>> incrementing{};

	// add all points to be incremented
	for(int row = 0; row < static_cast<int>(utils::dumboMapSize); ++row) {
		for(int col = 0; col < static_cast<int>(utils::dumboMapSize); ++col) {
			incrementing.emplace_back(std::pair<int,int>{row,col});
		}
	}
	
	auto AddPointIfViable = [&](int row, int col) -> void {
		if(row < 0 || row >= static_cast<int>(utils::dumboMapSize)) {
			return;
		}
		if(col < 0 || col >= static_cast<int>(utils::dumboMapSize)) {
			return;
		}
		if( !flashMap.at(static_cast<ulong>(row)).at(static_cast<ulong>(col)) ) {
			incrementing.emplace_back(std::pair<int,int>{row, col});
		}
	};

	while(!incrementing.empty()) {
		auto row = incrementing.front().first;
		auto col = incrementing.front().second;
		incrementing.pop_front();

		int& val = dumboMap.at(static_cast<ulong>(row)).at(static_cast<ulong>(col));
		bool& hasFlashed = flashMap.at(static_cast<ulong>(row)).at(static_cast<ulong>(col));

		++val;

		// If this dumbo should flash, add all neighbours
		if(val > 9 && !hasFlashed) {
			hasFlashed = true;
			++numFlashes;

			AddPointIfViable(row - 1, col	);	 // north
			AddPointIfViable(row - 1, col - 1); // north west
			AddPointIfViable(row - 1, col + 1); // north east
			AddPointIfViable(row	, col - 1);	 // west
			AddPointIfViable(row	, col + 1);	 // east
			AddPointIfViable(row + 1, col - 1); // south west
			AddPointIfViable(row + 1, col	);	 // south
			AddPointIfViable(row + 1, col + 1); // south east
		}
	}

	return numFlashes;
}

auto
CountDumboFlashes(const std::string_view& input, ulong numSteps) -> ulong
{
	ulong numFlashes = 0UL;
	auto lines = utils::SplitString(input, '\n');
	std::array<std::array<int, utils::dumboMapSize>, utils::dumboMapSize> dumboMap{};
	
	// read values into dumboMap
	for(ulong row = 0; row < utils::dumboMapSize; ++row) {
		auto line = lines.at(row);
		for(ulong col = 0; col < utils::dumboMapSize; ++col) {
			dumboMap.at(row).at(col) = static_cast<int>( line.at(col) - '0' );
		}
	}

	//! This isn't efficient
	for(ulong step = 0; step < numSteps; ++step) {

		numFlashes += PropagateDumboFlashes(dumboMap);

		for(ulong row = 0UL; row < utils::dumboMapSize; ++row) {
			for(ulong col = 0UL; col < utils::dumboMapSize; ++col) {
				int& val = dumboMap.at(row).at(col);
				if( val > 9){
					val = 0;
				}
			}
		}
	}

	return numFlashes;
}

} // namespace solutions