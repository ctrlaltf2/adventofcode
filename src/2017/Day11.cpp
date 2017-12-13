#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <regex>
#include <sstream>
#include <vector>

#define DIR(X) {#X, dir::X}

enum dir {
    n,
    s,
    ne,
    nw,
    se,
    sw
};

void y17day11(std::ostream& os, std::istream& is, bool part2) {
    std::map<std::string, int> const dirmap { DIR(n), DIR(s) , DIR(ne), DIR(nw), DIR(se), DIR(sw) };
    std::string ln;
    std::getline(is, ln, '\n');

    std::regex re{ R"([^news])" };
    ln = std::regex_replace(ln, re, " ");
    std::istringstream ss{ln};

    std::vector<std::string> directions{std::istream_iterator<std::string>{ss}, {}};

    auto distance = [](const int& x, const int& y) {
        if(std::signbit(x) == std::signbit(y))
            return std::abs(x + y);
        else
            return std::max(std::abs(x), std::abs(y));
    };

    int x{0}, y{0}, max{0};
    for(const auto& dir : directions) {
        switch(dirmap.at(dir)) {
            case dir::nw: --x, ++y; break;
            case dir::se: ++x, --y; break;
            case dir::n:  ++y; break;
            case dir::s:  --y; break;
            case dir::ne: ++x; break;
            case dir::sw: --x; break;
        }
        max = std::max(max, distance(x, y));
    }

    if(part2)
        os << max << '\n';
    else
        os << distance(x, y) << '\n';
}
