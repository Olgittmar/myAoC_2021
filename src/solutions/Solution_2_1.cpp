#include "MyAoC_2021/solutions/Solution_2_1.h"

#include "MyAoC_2021/utils/StringSplit.h"

namespace solutions {

int
SubmarineNavigationProduct(const std::string& str)
{
    auto input = utils::SplitString(str, '\n');
    SubmarinePosition subPos;

    for(auto it = input.cbegin(); it != input.cend(); it++){
        auto moveAction = StrToMovement(*it);
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

// Not the safest comparison but good enough for this problem
std::pair<MovementType, int> StrToMovement(const std::string& str)
{
    if(str.find(ForwardStr) != str.npos){
        // The substring which starts at ForwardStr.size must be what is left of the string when "forward " is removed,
        // which is the number of units to move.
        return std::make_pair<MovementType,int>( HORIZONTAL, std::stoi( str.substr( ForwardStr.size() ) ) );
    }

    if(str.find(DownStr) != str.npos){
        return std::make_pair<MovementType,int>( DEPTH, std::stoi( str.substr( DownStr.size() ) ) );
    }

    if(str.find(UpStr) != str.npos){
        // Up is reversed in direction, so subtract that value from depth.
        return std::make_pair<MovementType,int>( DEPTH, -(std::stoi( str.substr( UpStr.size() ) ) ) );
    }
}

}