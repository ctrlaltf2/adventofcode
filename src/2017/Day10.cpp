#include <algorithm>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

void y17day10(std::ostream& os, std::istream& is, bool part2) {
    const int kMax = 256;
    std::vector<int> list(kMax, 0), input;
    std::iota(list.begin(), list.end(), 0);

    int pos{0}, skip{0};
    for(char byte, ignore; is;) {
        if(part2)
            is.get(byte);
        else {
            int t;
            is >> t >> ignore;
            byte = t;
        }
        input.push_back(static_cast<int>(static_cast<unsigned char>(byte)));
    }
    input.erase(std::prev(input.end(), 1));

    if(part2)
        input.insert(input.end(), {17, 31, 73, 47, 23});

    for(int i = 0; i < (part2 ? 64 : 1); ++i) {
        for(auto& length : input) {
            std::rotate(list.begin(), std::next(list.begin(), pos), list.end());
            std::reverse(list.begin(), std::next(list.begin(), length));
            std::rotate(list.rbegin(), std::next(list.rbegin(), pos), list.rend());

            pos += length + skip++;
            pos %= kMax;
        }
    }

    if(!part2)
        os << list[0] * list[1] << std::endl;
    else {
        for(auto itr = list.begin(); itr != list.end(); itr += 16) {
            os << std::setw(2) << std::setfill('0') << std::hex
               << std::accumulate(itr, itr + 16, 0, std::bit_xor<void>());
        }
    }
}
