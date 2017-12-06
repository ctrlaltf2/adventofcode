#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <set>

void y17day4(std::ostream& os, std::istream& is, bool part2) {
    int valid{0};
    for(std::string ln;std::getline(is, ln, '\n');) {
        std::istringstream ss{ln};
        std::vector<std::string> const words(std::istream_iterator<std::string>{ss}, {});

        std::set<std::string> seen;
        valid += std::all_of(words.begin(), words.end(),
            [&seen, part2](const auto& word) {
                std::string c = word;
                if(part2)
                    std::sort(c.begin(), c.end());
                return seen.insert(c).second;
            });
    }

    os << valid << '\n';
}
