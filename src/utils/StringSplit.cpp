#include "MyAoC_2021/utils/StringSplit.h"

#include <algorithm>
#include <charconv>

namespace utils
{

    std::vector<std::string_view> SplitString(const std::string_view& str, const char& delim, bool greedy)
    {
	std::vector<std::string_view> _ret{};
	size_t prev = str.find_first_not_of(delim) * static_cast<size_t>(greedy);

	if (greedy) {
		bool building = false;
		for (size_t pos = prev; pos < str.size(); ++pos) {
			if (!building && str[pos] != delim) {
				building = true;
				prev = pos;
			}
			if (building && str[pos] == delim) {
				building = false;
				size_t length = pos - prev;
				std::string_view item = str.substr(prev, length);
				_ret.push_back(item);
				prev = pos + 1;
			}
		}
	} else {
		for (size_t pos = prev; pos < str.size(); ++pos) {
			if (str[pos] == delim) {
				size_t length = pos - prev;
				std::string_view item = str.substr(prev, length);
				_ret.push_back(item);
				prev = pos + 1;
			}
		}
	}

	if (prev < str.size()) {
		auto lastItem = str.substr(prev);
		if ((greedy && lastItem.find_first_not_of(delim) != std::string_view::npos) || !greedy) {
			_ret.push_back(lastItem);
		}
	}
	return _ret;
    }

    int StringViewToInt(const std::string_view& strView, int base)
    {
	std::string tmp{ strView };
	return std::stoi(tmp, nullptr, base);
    }

    // cppcheck-suppress unusedFunction
    std::vector<int> SplitStringToInt(const std::string_view& str, const char& delim, bool greedy, int base)
    {
	std::vector<int> _ret;
	auto strView = SplitString(str, delim, greedy);
	std::transform(strView.cbegin(), strView.cend(), std::back_inserter(_ret), [&](const std::string_view& str) {
	    return StringViewToInt(str, base);
	});
	return _ret;
    }

}  // namespace utils