#include <iostream>
#include <algorithm>

template<int X, int Y>
class KeyPad {
public:
    int maxX{X}, maxY{Y};
    char buttons[X][Y];
    KeyPad(std::initializer_list<char>&& ilist) {
        std::copy(ilist.begin(), ilist.end(), &buttons[0][0]);
    }
};

void y16day2(std::ostream& os, std::istream& is, bool part2) {
    KeyPad<3, 3> p1pad{'1', '2', '3',
                       '4', '5', '6',
                       '7', '8', '9'};

    KeyPad<5, 5> p2pad{' ', ' ', '1', ' ', ' ',
                       ' ', '2', '3', '4', ' ',
                       '5', '6', '7', '8', '9',
                       ' ', 'A', 'B', 'C', ' ',
                       ' ', ' ', 'D', ' ', ' '};

    auto solve = [&os, &is](int startx, int starty, auto pad) {
        int x{startx}, y{starty};
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
                dx = std::clamp(dx, 0, pad.maxX - 1);
                dy = std::clamp(dy, 0, pad.maxY - 1);

                if(pad.buttons[dy][dx] != ' ') {
                    x = dx;
                    y = dy;
                }
            }
            os << pad.buttons[y][x];
        }
    };

    if(part2)
        solve(2, 2, p2pad);
    else
        solve(1, 1, p1pad);
}
