#include <iostream>
#include <algorithm>

template<int X, int Y>
class KeyPad {
public:
    char buttons[X][Y];
    KeyPad(std::initializer_list<char>&& ilist) {
        std::copy(ilist.begin(), ilist.end(), &buttons[0][0]);
    }
};

void y16day2v2(std::ostream& os, std::istream& is);

void y16day2(std::ostream& os, std::istream& is, bool part2) {
    if(part2) {
        y16day2v2(os, is);
        return;
    }

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
                    pos -= ((pos - 1) % 3 == 0 ? 0 : 1);
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

void y16day2v2(std::ostream& os, std::istream& is) {
    KeyPad<5, 5> pad{' ', ' ', '1', ' ', ' ',
                     ' ', '2', '3', '4', ' ',
                     '5', '6', '7', '8', '9',
                     ' ', 'A', 'B', 'C', ' ',
                     ' ', ' ', 'D', ' ', ' '};

    int x{2}, y{2};
    for(std::string str;std::getline(is, str, '\n');) {
        for(const auto& c : str) {
            int dx = x, dy = y;
            switch(c) {
                case 'U':
                    dy -= 1;
                    break;
                case 'D':
                    dy += 1;
                    break;
                case 'L':
                    dx -= 1;
                    break;
                case 'R':
                    dx += 1;
            }
            dx = std::clamp(dx, 0, 4);
            dy = std::clamp(dy, 0, 4);

            if(pad.buttons[dy][dx] != ' ') {
                x = dx;
                y = dy;
            }
        }
        os << pad.buttons[y][x];
    }
}
