#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

void y17day6(std::ostream& os, std::istream& is, bool part2) {
    std::vector<int> bank(std::istream_iterator<int>{is}, {});

    std::map<std::vector<int>, int> seen;
    for(int cycles = 0; seen.emplace(bank, cycles).second; ++cycles) {
        auto max = std::max_element(bank.begin(), bank.end());
        for(int left = std::exchange(*max, 0); left-- > 0; ++*max)
            if(++max == bank.end())
                max = bank.begin();
    }

    os << (part2 ? seen.size() - seen[bank] : seen.size()) << '\n';
}
