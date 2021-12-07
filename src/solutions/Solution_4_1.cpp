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
    auto boardNumber = board.find(key);
    if( boardNumber != board.end() ){
        boardNumber->second.m_hit = true;
    }
}

bool
BingoBoard::HaveWon() const
{
    int columnsHit[5] = {0};
    int rowsHit[5] = {0};

    for(auto it = board.cbegin(); it != board.cend(); ++it) {
        if(it->second.m_hit){
            // Was too occupied thinking if whether I could,
            // forgot to wonder if I should...
            if( ++columnsHit[it->second.m_column] >= 5
             || ++rowsHit[it->second.m_row] >= 5 ) {
                return true;
            }
        }
    }

    return false;
}

int
BingoBoard::Score(int justCalled) const
{
    int sum = 0;
    for(auto it = board.cbegin(); it != board.cend(); ++it){
        if(!it->second.m_hit){
            sum += it->first;
        }
    }
    return sum*justCalled;
}

std::vector<int> GetNumberSequence(const std::string& input, size_t* resultingOffset)
{
    std::string numberSequenceString = input.substr(0, input.find("\n\n"));
    *resultingOffset = numberSequenceString.size();
    return utils::SplitStringToInt(numberSequenceString, ',');
}

std::vector<BingoBoard> GetBingoBoards(const std::string& input, size_t start)
{
    size_t sectionEnd = start;
    size_t sectionStart = 0;
    std::vector<BingoBoard> bingoBoards;

    while( sectionEnd != input.npos && sectionStart < sectionEnd ){
        sectionStart = sectionEnd + 2;
        sectionEnd = input.find("\n\n", sectionStart);
        auto section = input.substr(sectionStart, sectionEnd);
        auto numStrings = utils::SplitString(section, '\n');
        bingoBoards.push_back( BingoBoard( numStrings ) );
    }
    return bingoBoards;
}

int WinBingo(const std::string& input)
{
    size_t offset;
    auto numberSequence = GetNumberSequence(input, &offset);
    std::vector<BingoBoard> bingoBoards = GetBingoBoards(input, offset);

    for(auto it = numberSequence.cbegin(); it != numberSequence.cend(); ++it){
        for(auto boardIt = bingoBoards.begin(); boardIt != bingoBoards.cend(); ++boardIt) {
            boardIt->MarkIfOnBoard(*it);
            if(boardIt->HaveWon()){
                return boardIt->Score(*it);
            }
        }
    }

    return 0;
}


}