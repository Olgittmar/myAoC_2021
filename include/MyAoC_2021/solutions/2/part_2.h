#ifndef SOLUTION_2_2_H
#define SOLUTION_2_2_H

#include <string>
#include <vector>

#include "MyAoC_2021/utils/StringSplit.h"

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

    Submarine& operator=(const Submarine& other) = default;
    Submarine& operator=(Submarine&& other) = default;

    [[nodiscard]] // But why not? 
    inline constexpr int GetNavigationProduct() const { return m_depth * m_hPos; }
    void Navigate(const std::vector<std::string_view>& instructions);

  private:
    enum MoveCommand {
        DOWN, UP, FORWARD, UNKNOWN
    };

    int m_aim;
    int m_hPos;
    int m_depth;

    void Move(MoveCommand command, int value);
    static MoveCommand StrToMovecommand(const std::string_view& str);
    static std::pair<MoveCommand, int> StrToCommandValuePair(const std::string_view& str);

};

// cppcheck-suppress unusedFunction
[[gnu::used]] [[maybe_unused]]
int SubmarineAdvancedNavigationProduct(const std::string_view& str);

}

#endif