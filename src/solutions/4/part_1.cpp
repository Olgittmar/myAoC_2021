#include "MyAoC_2021/solutions/4/part_1.h"

#include <iostream>
#include <sstream>
#include <numeric>

#include "MyAoC_2021/utils/StringSplit.h"
#include "MyAoC_2021/utils/Constants.h"

namespace solutions {

// Assume board numbers are unique
BingoBoard::BingoBoard(const std::vector<std::string_view>& numStrings)
{
    int num{};
    for(size_t i = 0; i < numRows; ++i ) {
        auto nums = utils::SplitStringToInt(numStrings.at(i), ' ', true);
        for(size_t j = 0; j < numColumns; ++j){
            num = nums.at(j);
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
    std::array<int, numColumns> columnsHit = {{0}};
    std::array<int, numRows> rowsHit = {{0}};

    for(auto boardNumber : board) {
        if(boardNumber.second.m_hit){
            // Was too occupied thinking if whether I could,
            // forgot to wonder if I should...
            if( ++columnsHit.at(boardNumber.second.m_column) >= static_cast<int>(numColumns)
             || ++rowsHit.at(boardNumber.second.m_row) >= static_cast<int>(numRows) ) {
                return true;
            }
        }
    }

    return false;
}

int
BingoBoard::Score(int justCalled) const
{
	std::cout << "Scoring" << std::endl;
    int sum = std::accumulate(board.cbegin(), board.cend(), 0, 
        [&](int S, const std::pair<int, solutions::BoardNumber>& BoardNumber){
			return S + BoardNumber.first * static_cast<int>(!BoardNumber.second.isHit());
        }
    );
    return sum * justCalled;
}

std::vector<int>
GetNumberSequence(const std::string_view& input, size_t* resultingOffset)
{
    std::string_view numberSequenceString = input.substr(0, input.find("\n\n"));
    if(resultingOffset != nullptr){
        *resultingOffset = numberSequenceString.size() + 2;
    }
    return utils::SplitStringToInt(numberSequenceString, ',');
}

std::vector<BingoBoard>
GetBingoBoards(const std::string_view& input)
{
    size_t sectionStart{};
    std::vector<BingoBoard> bingoBoards;

    while( sectionStart < input.size() )
    {
        size_t sectionEnd = input.find("\n\n", sectionStart);
        auto section = input.substr(sectionStart, sectionEnd);
        auto numStrings = utils::SplitString(section, '\n');
        bingoBoards.emplace_back( numStrings );

		if( sectionEnd == std::string_view::npos ){
			break;
		}
		sectionStart = sectionEnd + 2;
    }

    return bingoBoards;
}

// cppcheck-suppress unusedFunction
int WinBingo(const std::string_view& input)
{
    size_t offset = 0;
    auto numberSequence = GetNumberSequence(input, &offset);
    std::vector<BingoBoard> bingoBoards = GetBingoBoards(input.substr(offset));

    for(auto number : numberSequence){
        for(auto boardIt = bingoBoards.begin(); boardIt != bingoBoards.cend(); ++boardIt) {
            boardIt->MarkIfOnBoard(number);
            if(boardIt->HaveWon()){
                return boardIt->Score(number);
            }
        }
    }

    return 0;
}


}