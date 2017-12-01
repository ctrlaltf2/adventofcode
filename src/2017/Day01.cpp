#include <iostream>
#include <string>
#include <cstdlib>

void y17day1(std::ostream& os, std::istream& is, bool part2) {

    int sum = 0;
    std::string s;
    is >> s;

    for(int i = 0; i < s.size();++i) {
        if(i == s.size() - 1) {
            if(s.front() == s.back()) {
                sum += s.front() - '0';
            }
        } else if(s.at(i) == s.at(i + 1))
            sum += s.at(i) - '0';
    }

    os << sum << '\n';
}
