#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>
#include <vector>

void y17day4(std::ostream& os, std::istream& is, bool part2) {
    int valid{0};
    for(std::string ln; std::getline(is, ln, '\n');) {
        std::istringstream ss{ln};
        std::vector<std::string> const words(std::istream_iterator<std::string>{ss}, {});

        std::set<std::string> seen;
        valid += std::all_of(words.begin(), words.end(), [&seen, part2](auto word) {
            if(part2)
                std::sort(word.begin(), word.end());
            return seen.insert(word).second;
        });
    }

    os << valid << '\n';
}
