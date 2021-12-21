#include "MyAoC_2021/solutions/Solution_4_2.h"
#include "MyAoC_2021/solutions/Solution_4_1.h"

#include <iostream>

#include "MyAoC_2021/utils/StringSplit.h"

namespace solutions {

// cppcheck-suppress unusedFunction
int LoseBingo(const std::string_view& input)
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

}