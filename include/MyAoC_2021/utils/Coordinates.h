#ifndef COORDINATES_H
#define COORDINATES_H

#include <string>
#include <cmath>
#include <vector>
#include <functional>

namespace utils {

class Coordinate2D {

  public:
	Coordinate2D() = default;
	Coordinate2D(const Coordinate2D& other) = default;
	Coordinate2D(Coordinate2D&& other) = default;
	~Coordinate2D() = default;
	//TODO: Need to look at how this works again
	explicit constexpr Coordinate2D(int _x, int _y) : m_x(_x), m_y(_y) {}

	Coordinate2D& operator=(const Coordinate2D& other) = default;
	Coordinate2D& operator=(Coordinate2D&& other) = default;

	constexpr bool operator==(const Coordinate2D& other) const {
		return m_x == other.m_x && m_y == other.m_y;
	}
	constexpr bool operator!=(const Coordinate2D& other) const {
		return !operator==(other);
	}

	[[nodiscard]] inline constexpr int x() const { return m_x; }
	[[nodiscard]] inline constexpr int y() const { return m_y; }

  private:
    int m_x = 0;
    int m_y = 0;
};

struct Coordinate2DHash {
	size_t operator()(Coordinate2D const& coord) const noexcept
	{
		size_t hx = std::hash<int>{}(coord.x());
		size_t hy = std::hash<int>{}(coord.y());
		return hx ^ (hy << 1UL);
	}
};

class Line {
  public:
	Line() = default;
	Line(const Line& other) = default;
	Line(Line&& other) = default;
	Line(Coordinate2D start, Coordinate2D end) : m_start(start), m_end(end) {}
	explicit Line(const std::string_view& line);
	~Line() = default;

	Line& operator=(const Line& other) = default;
	Line& operator=(Line&& other) = default;

	constexpr bool operator==(const Line& other) const {
		return m_start == other.m_start && m_end == other.m_end;
	}
	constexpr bool operator!=(const Line& other) const {
		return m_start != other.m_start || m_end != other.m_end;
	}

	[[nodiscard]] constexpr int right() const { return std::max(m_start.x(), m_end.x()); }
	[[nodiscard]] constexpr int left() const { return std::min(m_start.x(), m_end.x()); }
	[[nodiscard]] constexpr int up() const { return std::max(m_start.y(), m_end.y()); }
	[[nodiscard]] constexpr int down() const { return std::min(m_start.y(), m_end.y()); }
	[[nodiscard]] constexpr int leftMostY() const { return (m_start.x() <= m_end.x()) ? m_start.y() : m_end.y(); }
	[[nodiscard]] constexpr bool isHorizontal() const { return m_start.y() == m_end.y(); }
	[[nodiscard]] constexpr bool isVertical() const { return m_start.x() == m_end.x(); }
	[[nodiscard]] constexpr bool isSloped() const { return !(isHorizontal() || isVertical()); }
	[[nodiscard]] constexpr int slope() const { return (m_end.y() - m_start.y())/(m_end.x() - m_start.x()); }

	static Line lineFromString(const std::string_view& str);

	[[nodiscard]] [[maybe_unused]] [[gnu::used]]
	std::vector<Coordinate2D> range() const;

  private:
	static inline const std::string_view VentLineDivider = "->";
    Coordinate2D m_start;
    Coordinate2D m_end;
};

}

template<>
struct std::hash<utils::Coordinate2D>
{
	size_t operator()(utils::Coordinate2D const& coord) const noexcept
	{
		return utils::Coordinate2DHash{}(coord);
	}
};

#endif