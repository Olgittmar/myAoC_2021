#ifndef SOLUTION_4_1_h
#define SOLUTION_4_1_h

#include <map>

#include "MyAoC_2021/utils/StringSplit.h"


namespace solutions {

struct BoardNumber {
    BoardNumber() : m_row(0), m_column(0), m_hit(false) {}
    BoardNumber(size_t row, size_t column, bool hit = false)
      : m_row(row), m_column(column), m_hit(hit){}
    ~BoardNumber() = default;

    size_t m_row;
    size_t m_column;
    bool m_hit;
};

class BingoBoard {
  public:
    BingoBoard() : board() {}
    explicit BingoBoard(const std::vector<std::string>& numStrings);
    ~BingoBoard() = default;

    bool HaveWon() const;
    void MarkIfOnBoard(int key);
    int Score(int justCalled) const;

  private:
    std::map<int, BoardNumber> board;
};

std::vector<int> GetNumberSequence(const std::string& input, size_t* resultingOffset);
std::vector<BingoBoard> GetBingoBoards(const std::string& input, size_t start);

int WinBingo(const std::string& input);

}

#endif