#include <solutions/4/day_4_part_2.h>

#include <iostream>

#include <solutions/4/day_4_part_1.h>

#include <utils/utils.h>

namespace solutions {

// cppcheck-suppress unusedFunction
auto LoseBingo(const std::string_view& input) -> int
{    
    size_t offset = 0;
    auto numberSequence = GetNumberSequence(input, &offset);
    auto bingoBoards = GetBingoBoards(input.substr(offset));

    for(auto number : numberSequence){
        for(auto boardIt = bingoBoards.begin(); boardIt != bingoBoards.cend();) {
            boardIt->MarkIfOnBoard(number);
            if(boardIt->HaveWon()){
                if(bingoBoards.size() == 1){
                    return bingoBoards.cbegin()->Score(number);
                }
                boardIt = bingoBoards.erase(boardIt);
            } else {
                ++boardIt;
            }
        }
    }

    return 0;
}

} // namespace solutions