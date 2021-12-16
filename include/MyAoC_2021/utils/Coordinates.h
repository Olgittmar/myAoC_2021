#ifndef COORDINATES_H
#define COORDINATES_H

#include <string>
#include <math.h>
#include <vector>
#include <functional>

namespace utils {

struct Coordinate2D {
	constexpr Coordinate2D() : x(0), y(0) {}
	constexpr Coordinate2D(int _x, int _y)
	  : x(_x), y(_y) {}
	constexpr bool operator==(const Coordinate2D& other) const {
		return x == other.x && y == other.y;
	}
	constexpr bool operator!=(const Coordinate2D& other) const {
		return !operator==(other);
	}

    const int x;
    const int y;
};

class Line {
  public:
	Line() : m_start(0,0), m_end(0, 0) {}
	Line(Coordinate2D start, Coordinate2D end) : m_start(start), m_end(end) {}
	explicit Line(const std::string& line);
	~Line() = default;

	constexpr int right() const { return std::max(m_start.x, m_end.x); }
	constexpr int left() const { return std::min(m_start.x, m_end.x); }
	constexpr int up() const { return std::max(m_start.y, m_end.y); }
	constexpr int down() const { return std::min(m_start.y, m_end.y); }
	constexpr int leftMostY() const { return (m_start.x <= m_end.x) ? m_start.y : m_end.y; }
	
	constexpr bool isHorizontal() const { return m_start.y == m_end.y; }
	constexpr bool isVertical() const { return m_start.x == m_end.x; }
	constexpr bool isSloped() const { return !(isHorizontal() || isVertical()); }

	constexpr int slope() const { return (m_end.y - m_start.y)/(m_end.x - m_start.x); }

	std::vector<Coordinate2D> range() const;

  private:

    const Coordinate2D m_start;
    const Coordinate2D m_end;
};

Line lineFromString(const std::string& str);
}

template<>
struct std::hash<utils::Coordinate2D>
{
	size_t operator()(utils::Coordinate2D const& coord) const noexcept
	{
		size_t hx = std::hash<int>{}(coord.x);
		size_t hy = std::hash<int>{}(coord.y);
		return hx ^ (hy << 1);
	}
};


// struct Coordinate2DHash {
// 	std::size_t operator()(utils::Coordinate2D const& coord) const noexcept
// 	{
// 		size_t hx = std::hash<int>{}(coord.x);
// 		size_t hy = std::hash<int>{}(coord.y);
// 		return hx ^ (hy << 1);
// 	}
// };


#endif