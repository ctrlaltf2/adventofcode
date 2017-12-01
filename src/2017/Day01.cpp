#include <iostream>
#include <string>
#include <cstdlib>

void y17day1p2(std::ostream& os, std::istream& is, bool part2);

void y17day1(std::ostream& os, std::istream& is, bool part2) {

    if(part2) {
        y17day1p2(os, is, part2);
        return;
    }

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

void y17day1p2(std::ostream& os, std::istream& is, bool part2) {
    int sum = 0;
    std::string s;
    is >> s;

    for(int i = 0; i < s.size();++i) {
        int comp = (i + (s.size() / 2)) % s.size();
        if(s.at(i) == s.at(comp))
            sum += s.at(i) - '0';
    }

    os << sum << '\n';
}
