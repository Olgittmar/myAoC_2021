#include "MyAoC_2021/solutions/Solution_2_2.h"

#include <stdexcept>

namespace solutions {

const char* Submarine::ForwardStr = "forward";
const char* Submarine::DownStr = "down";
const char* Submarine::UpStr = "up";

int
Submarine::GetNavigationProduct() const
{
    return m_depth * m_hPos;
}

void
Submarine::Navigate(const std::vector<std::string>& instructions)
{
    for(auto it = instructions.cbegin(); it != instructions.cend(); it++){
        auto com = StrToCommandValuePair(*it);
        Move(com.first, com.second);
    }
}

void
Submarine::Move(MoveCommand command, int value)
{
    switch (command)
    {
    case FORWARD:
        m_hPos += value;
        m_depth += m_aim*value;
        break;
    case DOWN:
        m_aim += value;
        break;
    case UP:
        m_aim -= value;
        break;
    default:
        break;
    }

}

Submarine::MoveCommand
Submarine::StrToMovecommand(const std::string& str) const
{
    if( str.find(ForwardStr) != str.npos ){
        return FORWARD;
    }
    if( str.find(DownStr) != str.npos ){
        return DOWN;
    }
    if( str.find(UpStr) != str.npos ){
        return UP;
    }
    throw std::invalid_argument("Argument " + str + " is not a moveCommand");
}

std::pair<Submarine::MoveCommand, int>
Submarine::StrToCommandValuePair(const std::string& str) const
{
    auto delimPos = str.find(' ');
    if(delimPos == str.npos || delimPos + 1 >= str.size()){
        return std::make_pair<Submarine::MoveCommand, int>( UNKNOWN, 0 );
    }
    return std::make_pair<Submarine::MoveCommand, int>(
        StrToMovecommand( str.substr(0, delimPos) ),
        std::stoi( str.substr(delimPos) )
    );
}

int
SubmarineAdvancedNavigationProduct(const std::string& str)
{
    Submarine sub;
    sub.Navigate( utils::SplitString(str, '\n') );
    return sub.GetNavigationProduct();
}

} // solutions