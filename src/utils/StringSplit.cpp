#include "MyAoC_2021/utils/StringSplit.h"

#include <sstream>

namespace utils {

std::vector<std::string>
SplitString( const std::string& str, const char& delim )
{
    std::vector<std::string> _ret;
    std::stringstream strStrm(str);
    std::string item;
    while( getline(strStrm, item, delim) ){
        _ret.push_back(item);
    }
    return _ret;
}

std::vector<int>
SplitStringToInt(const std::string& str, const char& delim)
{
    std::vector<int> _ret;
    std::stringstream strStrm(str);
    std::string item;
    while( getline(strStrm, item, delim) ){
        _ret.push_back( std::stoi(item) );
    }
    return _ret;
}

}