#include <complex>
#include <fstream>
#include <iostream>

int main() {
    std::ifstream directions("input/1.txt");

    char comma, op;
    int amount;

    using namespace std::complex_literals;
    std::complex<int> location, bearing(0, 1);
    while(directions >> op >> amount) {
        directions >> comma;

        switch(op) {
            case 'R':
                bearing /= 1i;
                break;
            case 'L':
                bearing *= 1i;
                break;
        }
        location += bearing * amount;
    }

    std::cout << location.real() + location.imag() << '\n';
}
