#include <complex>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

int main() {
    std::ifstream directions("input/1.txt");

    char comma, op;
    int amount;
    bool foundAnswer{false};

    std::complex<int> location(0, 0), bearing(0, 1);
    std::set<std::pair<int, int>> visited;
    std::complex<int> answer;
    while((directions >> op >> amount) && not foundAnswer) {
        directions >> comma;

        using namespace std::complex_literals;
        switch(op) {
            case 'R':
                bearing /= 1i;
                break;
            case 'L':
                bearing *= 1i;
                break;
        }

        for(int i = 1;i <= amount;++i) {
            auto temp = location + bearing * i;
            if(!visited.emplace(temp.real(), temp.imag()).second) {
                    answer = std::complex<int>(temp);
                    foundAnswer = true;
            }
        }

        location += bearing * amount;

    }

    std::cout << std::abs(answer.real()) + std::abs(answer.imag()) << std::endl;
}
