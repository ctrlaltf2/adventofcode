#include <iostream>

constexpr int basement{-1};

void y15day1(std::ostream& os, std::istream& is, bool part2) {
    // '(' -> +1, ')' -> -1
    int floor{0};
    unsigned current_position{0};
    for(char c; is >> c;) {
        if(c == '(')
            ++floor;
        else if(c == ')')
            --floor;

        ++current_position;

        // Part2: first time current floor hits the basement
        if(part2 && (floor == basement)) {
            os << current_position << '\n';
            return;
        }
    }

    os << floor << '\n';
}
