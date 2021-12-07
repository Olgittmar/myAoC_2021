#include "MyAoC_2021/solutions/Solution_4_2.h"
#include "MyAoC_2021/solutions/Solution_4_1.h"

#include <iostream>

#include "MyAoC_2021/utils/StringSplit.h"

namespace solutions {

int LoseBingo(const std::string& input)
{    
    size_t offset;
    auto numberSequence = GetNumberSequence(input, &offset);
    auto bingoBoards = GetBingoBoards(input, offset);

    for(auto it = numberSequence.cbegin(); it != numberSequence.cend(); ++it){
        for(auto boardIt = bingoBoards.begin(); boardIt != bingoBoards.cend();) {
            boardIt->MarkIfOnBoard(*it);
            if(boardIt->HaveWon()){
                if(bingoBoards.size() == 1){
                    return bingoBoards.cbegin()->Score(*it);
                } else {
                    boardIt = bingoBoards.erase(boardIt);
                }
            } else {
                ++boardIt;
            }
        }
    }

    return 0;
}

}