#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

void y17day8(std::ostream& os, std::istream& is, bool part2) {
    std::map<std::string, int> registers;
    int max{0};

    for(std::string ln;std::getline(is, ln, '\n');) {
        std::istringstream iss{ln};
        std::string dst, op, comp, comp_op;
        int amount, comp_amt;
        iss >> dst >> op >> amount >> comp >> comp >> comp_op >> comp_amt;

        bool doWrite{false};
        if(comp_op == "<")
            doWrite = registers[comp] < comp_amt;
        else if(comp_op == ">")
            doWrite = registers[comp] > comp_amt;
        else if(comp_op == "==")
            doWrite = registers[comp] == comp_amt;
        else if(comp_op == "!=")
            doWrite = registers[comp] != comp_amt;
        else if(comp_op == "<=")
            doWrite = registers[comp] <= comp_amt;
        else if(comp_op == ">=")
            doWrite = registers[comp] >= comp_amt;

        if(doWrite) {
            if(op == "inc")
                registers[dst] += amount;
            else if(op == "dec")
                registers[dst] -= amount;

            max = std::max(registers[dst], max);
        }


    }
    if(part2)
        os << max << '\n';
    else
        os << std::max_element(registers.begin(), registers.end(), [](const auto& a, const auto& b) { return a.second < b.second; })->second << '\n';
}
