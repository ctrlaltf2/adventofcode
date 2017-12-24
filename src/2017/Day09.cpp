#include <iostream>
#include <string>

enum state {
    brace,
    ignore,
    garbage
};

void y17day9(std::ostream& os, std::istream& is, bool part2) {
    int s = state::brace, total{0}, depth{0}, removed{0};
    for(char c;is >> c;) {
        switch(s) {
            case state::ignore:
                s = state::brace;
                break;
            case state::brace:
            {
                switch(c) {
                    case '{':
                        depth += 1;
                        break;
                    case '}':
                        total += depth--;
                        break;
                    case '!':
                        s = state::ignore;
                        break;
                    case '<':
                        s = state::garbage;
                }
            }
            break;

            case state::garbage:
            {
                switch(c) {
                    case '!':
                        is >> c;
                        break;
                    case '>':
                        s = state::brace;
                        break;
                    default:
                        ++removed;
                }
            }
        }
    }

    os << (part2 ? removed : total) << '\n';
}
