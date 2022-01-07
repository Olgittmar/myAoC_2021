#ifndef SOLUTION_4_1_h
#define SOLUTION_4_1_h

#include <string_view>
#include <unordered_map>
#include <vector>

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

    auto operator=(const BoardNumber& other) -> BoardNumber& = default;
    auto operator=(BoardNumber&& other) -> BoardNumber& = default;

	[[nodiscard]] inline constexpr auto isHit() const -> bool
		{ return m_hit; }
	[[nodiscard]] inline constexpr auto row() const -> size_t
		{ return m_row; }
	[[nodiscard]] inline constexpr auto columnt() const -> size_t
		{ return m_column; }

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

    auto operator=(const BingoBoard& other) -> BingoBoard& = default;
    auto operator=(BingoBoard&& other) -> BingoBoard& = default;

    auto HaveWon() const -> bool;
    void MarkIfOnBoard(int key);
    auto Score(int justCalled) const -> int;

    static const size_t numRows = 5;
    static const size_t numColumns = 5;
  private:
    std::unordered_map<int, BoardNumber> board;
};

auto GetNumberSequence(const std::string_view& input, size_t* resultingOffset = nullptr) -> std::vector<int>;
auto GetBingoBoards(const std::string_view& input) -> std::vector<BingoBoard>;

// cppcheck-suppress unusedFunction
[[gnu::used]] [[maybe_unused]]
auto WinBingo(const std::string_view& input) -> int;

} // namespace solutions

#endif