#include <cctype>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

template<typename T>
T get(std::istream& is) {
    T t;
    is >> t;
    return t;
}

struct Instruction {
    std::string op, param1, param2;
};

void y16day12(std::ostream& os, std::istream& is, bool part2) {
    std::map<char, int> registers;
    std::vector<Instruction> memory;

    if(part2)
        registers['c'] = 1;

    for(std::string ln; std::getline(is, ln, '\n');) {
        std::istringstream iss{ln};
        memory.insert(memory.end(),
                      {{get<std::string>(iss), get<std::string>(iss), get<std::string>(iss)}});
    }

    int instr_ptr{0};
    while(instr_ptr < static_cast<int>(memory.size())) {
        auto& instr = memory[instr_ptr];
        if(instr.op == "cpy")
            if(std::isalpha(instr.param1[0]))
                registers[instr.param2[0]] = registers[instr.param1[0]];
            else
                registers[instr.param2[0]] = std::stoi(instr.param1);
        else if(instr.op == "inc")
            registers[instr.param1[0]]++;
        else if(instr.op == "dec")
            registers[instr.param1[0]]--;
        else if(instr.op == "jnz") {
            bool jump{false};
            if(std::isalpha(instr.param1[0]))
                jump = registers[instr.param1[0]] != 0;
            else
                jump = std::stoi(instr.param1) != 0;

            if(jump) {
                instr_ptr += std::stoi(instr.param2);
                continue;
            }
        }

        ++instr_ptr;
    }

    os << registers['a'] << '\n';
}
