#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

void y17day2(std::ostream& os, std::istream& is, bool part2) {
    int total{0};
    std::string ln;
    while(std::getline(is, ln, '\n')) {
        std::stringstream ss(ln);
        std::vector<int> const V(std::istream_iterator<int>{ss}, {});
        if(part2) {
            for(auto bitr = V.begin(); bitr != V.end() - 1; ++bitr) {
                auto search = std::find_if(bitr + 1, V.end(), [b = *bitr](const auto& a) {
                    return (a % b == 0) || (b % a == 0);
                });

                if(search != V.end())
                    total += std::max(*search / *bitr, *bitr / *search);
            }
        } else {
            auto [min, max] = std::minmax_element(V.begin(), V.end());
            total += *max - *min;
        }
    }
    os << total << '\n';
}
