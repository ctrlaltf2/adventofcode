#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <set>
#include <vector>

void y17day6(std::ostream& os, std::istream& is, bool part2) {
    std::vector<int> bank(std::istream_iterator<int>{is}, {});

    std::set<std::vector<int>> seen;
    for(int cycles = 0;seen.insert(bank).second;++cycles) {
        auto max = std::max_element(bank.begin(), bank.end());
        int left = *max;
        *max = 0;
        for(;left --> 0;++*max) {
            if(++max == bank.end())
                max = bank.begin();
        }
    }

    os << seen.size() << '\n';
}
