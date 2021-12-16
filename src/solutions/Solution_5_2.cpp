#include "MyAoC_2021/solutions/Solution_5_2.h"

#include <iostream>

#include "MyAoC_2021/utils/Coordinates.h"
#include "MyAoC_2021/utils/StringSplit.h"

namespace solutions {

// Far from optimal solution but I suspect I will need a structure like this for part 2...
int NumberOfOverlappingVentlinePointsIncludingDiagonals(const std::string& input)
{
    std::unordered_map<utils::Coordinate2D, int> grid;
    auto lines = utils::SplitString(input, '\n');
    for(auto line : lines){
        utils::Line ventLine = utils::lineFromString(line);
        for(auto coord : ventLine.range()){
            auto gridCoord = grid.find(coord);
            if( gridCoord != grid.end() ){
                gridCoord->second += 1;
            } else {
                grid.emplace(coord, 1);
            }
        }
    }

    int numIntersections = 0;
    for( auto it = grid.cbegin(); it != grid.cend(); ++it ) {
        numIntersections += static_cast<int>(it->second >= 2);
    }

    return numIntersections;
}

}