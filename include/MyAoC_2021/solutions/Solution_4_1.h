#ifndef SOLUTION_4_1_h
#define SOLUTION_4_1_h

#include <unordered_map>

#include "MyAoC_2021/utils/StringSplit.h"


namespace solutions {

class BingoBoard;

class BoardNumber {
  public:
    BoardNumber() = default;
    BoardNumber(const BoardNumber& other) = default;
    BoardNumber(BoardNumber&& other) = default;
    BoardNumber(size_t row, size_t column, bool hit = false)
      : m_row(row), m_column(column), m_hit(hit){}
    ~BoardNumber() = default;

    BoardNumber& operator=(const BoardNumber& other) = default;
    BoardNumber& operator=(BoardNumber&& other) = default;

	[[nodiscard]] inline constexpr bool isHit() const { return m_hit; }
	[[nodiscard]] inline constexpr size_t row() const { return m_row; }
	[[nodiscard]] inline constexpr size_t columnt() const { return m_column; }

    friend BingoBoard;

  private:
    size_t m_row = 0UL;
    size_t m_column = 0UL;
    bool m_hit = false;
};

class BingoBoard {
  public:
    BingoBoard() = default;
    BingoBoard(const BingoBoard& other) = default;
    BingoBoard(BingoBoard&& other) = default;
    explicit BingoBoard(const std::vector<std::string_view>& numStrings);
    ~BingoBoard() = default;

    BingoBoard& operator=(const BingoBoard& other) = default;
    BingoBoard& operator=(BingoBoard&& other) = default;

    bool HaveWon() const;
    void MarkIfOnBoard(int key);
    int Score(int justCalled) const;

    static const size_t numRows = 5;
    static const size_t numColumns = 5;
  private:
    std::unordered_map<int, BoardNumber> board;
};

std::vector<int> GetNumberSequence(const std::string_view& input, size_t* resultingOffset = nullptr);
std::vector<BingoBoard> GetBingoBoards(const std::string_view& input);

// cppcheck-suppress unusedFunction
[[gnu::used]] [[maybe_unused]]
int WinBingo(const std::string_view& input);

}

#endif