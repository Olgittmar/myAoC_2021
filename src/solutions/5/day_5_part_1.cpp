#include <solutions/5/day_5_part_1.h>

#include <iostream>
#include <numeric>

#include <utils/utils.h>

namespace solutions {

// cppcheck-suppress unusedFunction
auto NumberOfOverlappingVentlinePoints(const std::string_view& input) -> int
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

} // namespace solutions