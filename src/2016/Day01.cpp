#include <complex>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

void y16day1(std::ostream& os, std::istream& is, bool part2) {
    char op;
    int amount;
    bool foundAnswer{false};

    std::complex<int> location(0, 0), bearing(0, 1);
    std::set<std::pair<int, int>> visited;
    std::complex<int> answer;
    while((is >> op >> amount) && not foundAnswer) {
        is.ignore(1, ',');
        using namespace std::complex_literals;
        switch(op) {
            case 'R':
                bearing /= 1i;
                break;
            case 'L':
                bearing *= 1i;
                break;
        }
        if(part2) {
            for(int i = 1;i <= amount;++i) {
                auto temp = location + bearing * i;
                if(!visited.emplace(temp.real(), temp.imag()).second) {
                        answer = std::complex<int>(temp);
                        foundAnswer = true;
                }
            }
        }

        location += bearing * amount;

    }

    if(part2)
        os << std::abs(answer.real()) + std::abs(answer.imag()) << '\n';
    else
        os << std::abs(location.real()) + std::abs(location.imag()) << '\n';
}
