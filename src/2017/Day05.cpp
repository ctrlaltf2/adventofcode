#include <iostream>
#include <iterator>
#include <vector>

void y17day5(std::ostream& os, std::istream& is, bool part2) {
    std::vector<int> instrs(std::istream_iterator<int>{is}, {});
    int steps{0};
    for(int ptr = 0; ptr < (int) instrs.size(); ++steps)
        ptr += ((instrs[ptr] >= 3) && part2 ? instrs[ptr]-- : instrs[ptr]++);

    os << steps << '\n';
}
