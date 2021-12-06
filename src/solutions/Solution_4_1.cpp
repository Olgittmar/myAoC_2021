#include "MyAoC_2021/solutions/Solution_4_1.h"

#include <iostream>
#include <sstream>

#include "MyAoC_2021/utils/StringSplit.h"

namespace solutions {

// Assume board numbers are unique
BingoBoard::BingoBoard(const std::vector<std::string>& numStrings)
{
    int num;
    for(size_t i = 0; i < 5; ++i ){
        std::stringstream strStrm(numStrings[i]);
        for(size_t j = 0; j < 5; ++j){
            strStrm >> num; // Don't like this
            board[num] = BoardNumber(i, j);
        }
    }
}

void
BingoBoard::MarkIfOnBoard(int key)
{

}

bool
BingoBoard::HaveWon() const
{
    return false;
}

int
BingoBoard::Score(int justCalled) const
{
    return justCalled;
}

int WinBingo(const std::string& input)
{
    std::vector<BingoBoard> bingoBoards;

    size_t sectionStart = 0;
    size_t sectionEnd = input.find("\n\n");
    std::string numberSequenceString = input.substr(sectionStart, sectionEnd);

    while( sectionEnd != input.npos && sectionStart < sectionEnd ){
        sectionStart = sectionEnd + 2;
        sectionEnd = input.find("\n\n");

        auto numStrings = utils::SplitString(input.substr(sectionStart, sectionEnd), '\n');
        bingoBoards.push_back( BingoBoard( numStrings ) );
    }

    auto numberSequence = utils::SplitStringToInt(numberSequenceString, ',');

    for(auto it = numberSequence.cbegin(); it != numberSequence.cend(); ++it){
        for(auto boardIt = bingoBoards.begin(); boardIt != bingoBoards.cend(); ++boardIt){
            boardIt->MarkIfOnBoard(*it);
            if(boardIt->HaveWon()){
                return boardIt->Score(*it);
            }
        }
    }

    return 0;
}


}