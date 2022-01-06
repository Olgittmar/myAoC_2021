#include <11/part_2.h>

#include <StringSplit.h>

#include <11/part_1.h>

namespace solutions {

ulong
PredictSynchronizedFlash(const std::string_view& input, ulong maxSteps)
{
	auto lines = utils::SplitString(input, '\n');
	std::array<std::array<int, utils::dumboMapSize>, utils::dumboMapSize> dumboMap{};
	
	// read values into dumboMap
	for(ulong row = 0; row < utils::dumboMapSize; ++row) {
		auto line = lines.at(row);
		for(ulong col = 0; col < utils::dumboMapSize; ++col) {
			dumboMap.at(row).at(col) = static_cast<int>( line.at(col) - '0' );
		}
	}

	ulong numSteps = 0UL;
	//! This isn't efficient
	while( ++numSteps <= maxSteps
		&& PropagateDumboFlashes(dumboMap) < utils::dumboMapSize * utils::dumboMapSize)
	{
		for(ulong row = 0UL; row < utils::dumboMapSize; ++row) {
			for(ulong col = 0UL; col < utils::dumboMapSize; ++col) {
				int& val = dumboMap.at(row).at(col);
				if( val > 9){
					val = 0;
				}
			}
		}
	}

	return numSteps;
}


} // solutions