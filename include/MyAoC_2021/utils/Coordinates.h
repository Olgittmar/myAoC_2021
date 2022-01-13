#ifndef MYAOC_2021_UTILS_COORDINATES_H
#define MYAOC_2021_UTILS_COORDINATES_H

#include <cmath>
#include <iostream>
#include <functional>
#include <sstream>
#include <string>
#include <vector>

namespace utils {

class Coordinate2D {

  public:
	Coordinate2D() = default;
	Coordinate2D(const Coordinate2D& other) = default;
	Coordinate2D(Coordinate2D&& other) = default;
	~Coordinate2D() = default;
	//TODO: Need to look at how this works again
	explicit constexpr Coordinate2D(int _x, int _y) : m_x(_x), m_y(_y) {}

	auto operator=(const Coordinate2D& other) -> Coordinate2D& = default;
	auto operator=(Coordinate2D&& other) -> Coordinate2D& = default;

	constexpr auto operator==(const Coordinate2D& other) const -> bool {
		return m_x == other.m_x && m_y == other.m_y;
	}
	constexpr auto operator!=(const Coordinate2D& other) const -> bool {
		return !operator==(other);
	}

	inline constexpr auto setX(int newX) -> void { m_x = newX; }
	inline constexpr auto setY(int newY) -> void { m_y = newY; }

	[[nodiscard]] inline constexpr auto x() const -> int { return m_x; }
	[[nodiscard]] inline constexpr auto y() const -> int { return m_y; }

  private:
	friend inline std::ostream& operator<<(std::ostream& os, const utils::Coordinate2D& coord) {
		return os << '(' << coord.m_x << ", " << coord.m_y << ')';
	}
    int m_x = 0;
    int m_y = 0;
};

struct Coordinate2DHash {
	auto operator()(Coordinate2D const& coord) const noexcept -> size_t
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

	auto operator=(const Line& other) -> Line& = default;
	auto operator=(Line&& other) -> Line& = default;

	constexpr auto operator==(const Line& other) const -> bool {
		return m_start == other.m_start && m_end == other.m_end;
	}
	constexpr auto operator!=(const Line& other) const -> bool {
		return m_start != other.m_start || m_end != other.m_end;
	}

	[[nodiscard]] constexpr auto right() const -> int { return std::max(m_start.x(), m_end.x()); }
	[[nodiscard]] constexpr auto left() const -> int { return std::min(m_start.x(), m_end.x()); }
	[[nodiscard]] constexpr auto up() const -> int { return std::max(m_start.y(), m_end.y()); }
	[[nodiscard]] constexpr auto down() const -> int { return std::min(m_start.y(), m_end.y()); }
	[[nodiscard]] constexpr auto leftMostY() const -> int { return (m_start.x() <= m_end.x()) ? m_start.y() : m_end.y(); }
	[[nodiscard]] constexpr auto isHorizontal() const -> bool { return m_start.y() == m_end.y(); }
	[[nodiscard]] constexpr auto isVertical() const -> bool { return m_start.x() == m_end.x(); }
	[[nodiscard]] constexpr auto isSloped() const -> bool { return !(isHorizontal() || isVertical()); }
	[[nodiscard]] constexpr auto slope() const -> int { return (m_end.y() - m_start.y())/(m_end.x() - m_start.x()); }

	static auto lineFromString(const std::string_view& str) -> Line;

	[[nodiscard]] [[maybe_unused]] [[gnu::used]]
	auto range() const -> std::vector<Coordinate2D>;

  private:
	friend inline std::ostream& operator<<(std::ostream &os, const utils::Line& line) {
		return os << line.m_start << ' ' << line.VentLineDivider << ' ' << line.m_end;
	}
	static inline const std::string_view VentLineDivider = "->";
    Coordinate2D m_start;
    Coordinate2D m_end;
};

} // namespace utils

template<>
struct std::hash<utils::Coordinate2D>
{
	auto operator()(utils::Coordinate2D const& coord) const noexcept -> size_t
	{
		return utils::Coordinate2DHash{}(coord);
	}
};

#endif