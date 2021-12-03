#ifndef SOLUTION_2_2_H
#define SOLUTION_2_2_H

#include <string>
#include <vector>

#include "MyAoC_2021/utils/StringSplit.h"

namespace solutions {

class Submarine
{
  public:
    Submarine() : m_aim(0), m_hPos(0), m_depth(0) {}
    Submarine(int aim, int hPos, int depth)
        : m_aim(aim), m_hPos(hPos), m_depth(depth) {}
    ~Submarine(){}

    int GetNavigationProduct() const;
    void Navigate(const std::vector<std::string>& instructions);

  private:
    enum MoveCommand {
        DOWN, UP, FORWARD, UNKNOWN
    };

    static const char* ForwardStr;
    static const char* DownStr;
    static const char* UpStr;
    
    int m_aim;
    int m_hPos;
    int m_depth;

    void Move(MoveCommand command, int value);
    MoveCommand StrToMovecommand(const std::string& str) const;
    std::pair<MoveCommand, int> StrToCommandValuePair(const std::string& str) const;

};

int SubmarineAdvancedNavigationProduct(const std::string& str);

}

#endif