#include "MyAoC_2021/solutions/Solution_5_1.h"

#include <iostream>
#include <numeric>

#include "MyAoC_2021/utils/Coordinates.h"
#include "MyAoC_2021/utils/StringSplit.h"

namespace solutions {

// cppcheck-suppress unusedFunction
int NumberOfOverlappingVentlinePoints(const std::string_view& input)
{
    std::unordered_map<utils::Coordinate2D, int> grid;
    auto lines = utils::SplitString(input, '\n');
    for(const auto& line : lines){
        utils::Line ventLine = utils::Line::lineFromString(line);
        if(ventLine.isSloped()){
            continue;
        }
        for(auto coord : ventLine.range()){
            auto gridCoord = grid.find(coord);
            if( gridCoord != grid.end() ){
                gridCoord->second += 1;
            } else {
                grid.emplace(coord, 1);
            }
        }
    }

    int numIntersections = std::accumulate(grid.cbegin(), grid.cend(), 0,
        [&](int sum, const std::pair<utils::Coordinate2D, int>& gridPos){
            return sum + static_cast<int>(gridPos.second >= 2);
        }
    );
    return numIntersections;
}

}