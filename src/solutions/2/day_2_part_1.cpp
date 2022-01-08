#include <solutions/2/day_2_part_1.h>

#include <utils/StringSplit.h>

namespace solutions {

// cppcheck-suppress unusedFunction
auto SubmarineNavigationProduct(const std::string_view& str) -> int
{
    auto input = utils::SplitString(str, '\n');
    SubmarinePosition subPos;

    for(const auto& command : input){
        auto moveAction = StrToMovement(command);
        switch (moveAction.first)
        {
        case HORIZONTAL:
            subPos.h_position += moveAction.second;
            break;
        case DEPTH:
            subPos.depth += moveAction.second;
            break;
        default:
            break;
        }
    }

    return subPos.h_position * subPos.depth;
}

auto StrToMovement(const std::string_view& str) -> std::pair<MovementType, int>
{
    constexpr const std::string_view ForwardStr{"forward "};
    constexpr const std::string_view DownStr{"down "};
    constexpr const std::string_view UpStr{"up "};
    
    if(str.find(ForwardStr) != std::string_view::npos){
        // The substring which starts at ForwardStr.size must be what is left of the string when "forward " is removed,
        // which is the number of units to move.
        return std::make_pair<MovementType,int>( HORIZONTAL, utils::StringViewToInt( str.substr( ForwardStr.size() ) ) );
    }

    if(str.find(DownStr) != std::string_view::npos){
        return std::make_pair<MovementType,int>( DEPTH, utils::StringViewToInt( str.substr( DownStr.size() ) ) );
    }

    if(str.find(UpStr) != std::string_view::npos){
        // Up is reversed in direction, so subtract that value from depth.
        return std::make_pair<MovementType,int>( DEPTH, -(utils::StringViewToInt( str.substr( UpStr.size() ) ) ) );
    }

    return std::make_pair<MovementType,int>(HORIZONTAL, 0);
}

} // namespace solutions