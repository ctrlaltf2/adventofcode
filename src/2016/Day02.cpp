#include <iostream>

void y16day2(std::ostream& os, std::istream& is, bool part2) {
    int pos = 5;
    for(std::string str;std::getline(is, str, '\n');) {
        for(const auto& c : str) {
            switch(c) {
                case 'U':
                    pos -= (pos <= 3 ? 0 : 3);
                    break;
                case 'D':
                    pos += (pos <= 9 && pos >= 7 ? 0 : 3);
                    break;
                case 'L':
                    pos -= ( (pos - 1) % 3 == 0 ? 0 : 1);
                    break;
                case 'R':
                    pos += (pos % 3 == 0 ? 0 : 1);
                    break;
            }
        }
        os << pos;
    }
    os << '\n';
}
