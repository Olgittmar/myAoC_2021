#include "MyAoC_2021/utils/Coordinates.h"
#include "MyAoC_2021/utils/StringSplit.h"

#include <iostream>


namespace utils {

const std::string VentLineDivider = " -> ";

std::vector<Coordinate2D>
Line::range() const
{
    std::vector<Coordinate2D> _ret;
    if(isVertical()){
        for(int i = 0; i < abs( up() - down() + 1 ); ++i) {
            _ret.push_back( Coordinate2D( m_start.x, down() + i ) );
        }
    } else {
        for(int i = 0; i < abs( right() - left() + 1 ); ++i) {
            _ret.push_back( Coordinate2D( left() + i, leftMostY() + i*slope() ) );
        }
    }
    return _ret;
}

Line
lineFromString(const std::string& str)
{
    auto dividerPos = str.find(VentLineDivider);
    auto startCoordStr = str.substr( 0, dividerPos );
    auto endCoordStr = str.substr( dividerPos + VentLineDivider.length() );
    auto startCoords = SplitStringToInt(startCoordStr, ',');
    auto endCoords = SplitStringToInt(endCoordStr, ',');

    return Line(
        Coordinate2D( startCoords[0], startCoords[1] ),
        Coordinate2D( endCoords[0], endCoords[1] ) );
}

}