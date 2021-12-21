#ifndef SOLUTION_6_1
#define SOLUTION_6_1

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

	LanternFish& operator=(const LanternFish& other) = default;
	LanternFish& operator=(LanternFish&& other) = default;

	[[nodiscard]] inline constexpr bool CountDown()	{
		if(--m_numDaysUntilSpawn < 0) {
			m_numDaysUntilSpawn = daysUntilRespawn;
			return true;
		}
		return false;
	}
	[[nodiscard]] inline constexpr int DaysLeft() const { return m_numDaysUntilSpawn; }

	static const int daysUntilRespawn = 6;
	static const int initDaysUntilSpawn = 8;

  private:
	int m_numDaysUntilSpawn = initDaysUntilSpawn;
};

// cppcheck-suppress unusedFunction
[[gnu::used]] [[maybe_unused]]
int CalculateNumberOfLanternFishAfterNDays(const std::string& input , int numDays);

}

#endif