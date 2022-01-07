#ifndef SOLUTION_2_2_H
#define SOLUTION_2_2_H

#include <string_view>
#include <vector>

namespace solutions {

class Submarine
{
  public:
    Submarine() = default;
    Submarine(const Submarine& other) = default;
    Submarine(Submarine&&) = default;
    Submarine(int aim, int hPos, int depth)
        : m_aim(aim), m_hPos(hPos), m_depth(depth) {}
    ~Submarine() = default;

    auto operator=(const Submarine& other) -> Submarine& = default;
    auto operator=(Submarine&& other) -> Submarine& = default;

    [[nodiscard]]
    inline constexpr auto GetNavigationProduct() const -> int { return m_depth * m_hPos; }
    void Navigate(const std::vector<std::string_view>& instructions);

  private:
    enum MoveCommand {
        DOWN, UP, FORWARD, UNKNOWN
    };

    int m_aim;
    int m_hPos;
    int m_depth;

    void Move(MoveCommand command, int value);
    static auto StrToMovecommand(const std::string_view& str) -> MoveCommand;
    static auto StrToCommandValuePair(const std::string_view& str) -> std::pair<MoveCommand, int>;

};

// cppcheck-suppress unusedFunction
[[gnu::used]] [[maybe_unused]]
auto SubmarineAdvancedNavigationProduct(const std::string_view& str) -> int;

} // namespace solutions

#endif