#include <2/part_2.h>

#include <stdexcept>

#include <StringSplit.h>

namespace solutions {

void
Submarine::Navigate(const std::vector<std::string_view>& instructions)
{
    for(const auto& instruction : instructions){
        auto com = StrToCommandValuePair(instruction);
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

auto
Submarine::StrToMovecommand(const std::string_view& str) -> Submarine::MoveCommand
{
    constexpr std::string_view ForwardStr{"forward"};
    constexpr std::string_view DownStr{"down"};
    constexpr std::string_view UpStr{"up"};

    if( str.find(ForwardStr) != std::string_view::npos ){
        return FORWARD;
    }
    if( str.find(DownStr) != std::string_view::npos ){
        return DOWN;
    }
    if( str.find(UpStr) != std::string_view::npos ){
        return UP;
    }
    std::string errMsg{"Argument"};
    errMsg += str.data();
    errMsg += " is not a moveCommand";
    throw std::invalid_argument(errMsg);
}

auto
Submarine::StrToCommandValuePair(const std::string_view& str) -> std::pair<Submarine::MoveCommand, int>
{
    auto delimPos = str.find(' ');
    if(delimPos == std::string::npos || delimPos + 1 >= str.size()){
        return std::make_pair<Submarine::MoveCommand, int>( UNKNOWN, 0 );
    }
    return std::make_pair<Submarine::MoveCommand, int>(
        StrToMovecommand( str.substr(0, delimPos) ),
        utils::StringViewToInt( str.substr(delimPos) )
    );
}

// cppcheck-suppress unusedFunction
auto SubmarineAdvancedNavigationProduct(const std::string_view& str) -> int
{
    Submarine sub{};
    sub.Navigate( utils::SplitString(str, '\n') );
    return sub.GetNavigationProduct();
}

} // namespace solutions