#ifndef MYAOC_2021_SOLUTIONS_6_DAY_6_6_PART_1_H
#define MYAOC_2021_SOLUTIONS_6_DAY_6_6_PART_1_H

#include <string>
#include <vector>

namespace solutions
{

class LanternFish
{
  public:
	LanternFish() = default;
	explicit LanternFish(int numDaysUntilSpawn) : m_numDaysUntilSpawn(numDaysUntilSpawn) {}
	LanternFish(const LanternFish& other) = default;
	LanternFish(LanternFish&& other) = default;
	~LanternFish() = default;

	auto operator=(const LanternFish& other) -> LanternFish& = default;
	auto operator=(LanternFish&& other) -> LanternFish& = default;

	[[nodiscard]]
	inline constexpr auto CountDown() -> bool {
		if(--m_numDaysUntilSpawn < 0) {
			m_numDaysUntilSpawn = daysUntilRespawn;
			return true;
		}
		return false;
	}
	[[nodiscard]]
	inline constexpr auto DaysLeft() const -> int { return m_numDaysUntilSpawn; }

	static const int daysUntilRespawn = 6;
	static const int initDaysUntilSpawn = 8;

  private:
	int m_numDaysUntilSpawn = initDaysUntilSpawn;
};

[[gnu::used]] [[maybe_unused]]
auto CalculateNumberOfLanternFishAfterNDays(const std::string& input , int numDays) -> int;

} // namespace solutions

#endif