#include <solutions/16/day_16_part_2.h>

#include <solutions/16/day_16_part_1.h>

#include <utils/utils.h>

namespace solutions
{

auto EvaluatePackageValues(const std::string_view& input) -> ulong
{
	std::string bits{};
	bits.reserve(input.size() * 4UL);

	for(const char& c : input) {
		bits += CharToBits(c);
	}

	size_t pos = 0UL;
	auto rootPackage = GetNextPackage(bits, pos);

	ulong result = rootPackage->GetPackageValue();
	return result;
}

} // namespace solutions