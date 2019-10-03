#include "Utill.h"

std::vector<std::string> split(const std::string& str, const std::string& substr)
{
    std::vector<std::string> strings;

    if (substr.length() == 0) return strings;

    if (substr == str) {
        strings.push_back(substr);
        return strings;
    }

    auto start = 0;
    auto pos = str.find(substr, start);
    const auto size = str.length();
    if (pos == std::string::npos) return strings;

    while(true) {
        strings.push_back(str.substr(start, pos - start));
        start = pos + 1;

        if (pos == std::string::npos || pos == size - 1) break;
        pos = str.find(substr, start);
    }

    return strings;
}