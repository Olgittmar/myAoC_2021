#include <Coordinates.h>

#include <iostream>

namespace utils {

auto Line::range() const -> std::vector<Coordinate2D>
{
    std::vector<Coordinate2D> _ret{};
    if(isVertical()){
        for(int i = 0; i < abs( up() - down() + 1 ); ++i) {
            _ret.emplace_back( Coordinate2D( m_start.x(), down() + i ) );
        }
    } else {
        for(int i = 0; i < abs( right() - left() + 1 ); ++i) {
            _ret.emplace_back( Coordinate2D( left() + i, leftMostY() + i*slope() ) );
        }
    }
    return _ret;
}

auto Line::lineFromString(const std::string_view& str) -> Line
{
    auto dividerPos = str.find(VentLineDivider);
    auto startCoordStr = str.substr( 0, dividerPos );
    auto endCoordStr = str.substr( dividerPos + VentLineDivider.size() );
    auto startCoords = SplitStringToInt(startCoordStr, ',');
    auto endCoords = SplitStringToInt(endCoordStr, ',');

    return Line{
        Coordinate2D( startCoords[0], startCoords[1] ),
        Coordinate2D( endCoords[0], endCoords[1] )};
}

} // namespace utils