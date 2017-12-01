#include <iostream>
#include <string>

void y17day1(std::ostream& os, std::istream& is, bool part2) {

    std::string s;
    is >> s;
    int offset = (part2 ? s.size() / 2 : 1), sum{0};

    for(int i = 0; i < s.size();++i) {
        if(s.at(i) == s.at( (i + offset) % s.size() ))
            sum += s.at(i) - '0';
    }

    os << sum << '\n';
}
