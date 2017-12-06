#include <iostream>
#include <iterator>
#include <vector>

void y17day5(std::ostream& os, std::istream& is, bool part2) {
    std::vector<int> instructions(std::istream_iterator<int>{is}, {});
    int steps{0};
    for(int instr_ptr = 0; instr_ptr < instructions.size();++steps)
        instr_ptr += instructions[instr_ptr]++;

    os << steps << '\n';
}
