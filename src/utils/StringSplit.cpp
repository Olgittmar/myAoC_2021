#include <StringSplit.h>

#include <algorithm>
#include <cassert>

namespace utils
{

auto SplitString(const std::string_view& str, const char& delim, bool greedy) -> std::vector<std::string_view>
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

auto SplitString(const std::string_view& str, const std::string_view& delimStr) -> std::vector<std::string_view>
{
	assert(!delimStr.empty());
    std::vector<std::string_view> _ret{};
    size_t prev = 0UL;
	size_t delimPos = 0UL;

	do {
		delimPos = str.find(delimStr, prev);
		_ret.push_back(str.substr(prev, delimPos - prev));
		prev = delimPos + delimStr.size();
	} while(delimPos != std::string_view::npos);
    
    return _ret;
}

auto SplitStringToInt(const std::string_view& toConvert, const char& delim, bool greedy, int base) -> std::vector<int>
{
    std::vector<int> _ret{};
	try {
    	auto strView = SplitString(toConvert, delim, greedy);
    	std::transform(strView.cbegin(), strView.cend(), std::back_inserter(_ret),
			[&](const std::string_view& str) { return StringViewToInt(str, base); });
	} catch(std::invalid_argument err) {
		_ret.clear();
		// See if it works if we remove unconvertible chars
		std::string tmp{toConvert.begin(), toConvert.end()};
		tmp.erase( std::remove_if(tmp.begin(), tmp.end(),
			[&](unsigned char c) -> bool { return !std::isdigit(c) && !(c == delim); }),
			tmp.end());
		
		auto strView = SplitString(tmp, delim, greedy);
    	std::transform(strView.cbegin(), strView.cend(), std::back_inserter(_ret),
			[&](const std::string_view& str) { return StringViewToInt(str, base); });
	}
    return _ret;
}

auto SplitStringToULong(const std::string_view& toConvert, const char& delim, bool greedy, int base) -> std::vector<ulong>
{
    std::vector<ulong> _ret{};
	try {
    auto strView = SplitString(toConvert, delim, greedy);
    std::transform(strView.cbegin(), strView.cend(), std::back_inserter(_ret),
		[&](const std::string_view& str) { return StringViewToULong(str, base); });
	} catch(std::invalid_argument err) {
		_ret.clear();
		// See if it works if we remove unconvertible chars
		std::string tmp{toConvert.begin(), toConvert.end()};
		tmp.erase( std::remove_if(tmp.begin(), tmp.end(),
			[&](unsigned char c) -> bool { return !std::isdigit(c) && !(c == delim); }),
			tmp.end());
		
		auto strView = SplitString(tmp, delim, greedy);
    	std::transform(strView.cbegin(), strView.cend(), std::back_inserter(_ret),
			[&](const std::string_view& str) { return StringViewToInt(str, base); });
	}
    return _ret;
}

}  // namespace utils