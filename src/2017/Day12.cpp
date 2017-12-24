#include <iostream>
#include <functional>
#include <map>
#include <regex>
#include <sstream>
#include <vector>

void y17day12(std::ostream& os, std::istream& is, bool part2) {

    std::regex const nonDigits{R"([^\d]+)"};
    std::map<int, std::vector<int>> village;
    std::map<int, bool> seen;

    for(std::string ln;std::getline(is, ln, '\n');) {
        ln = std::regex_replace(ln, nonDigits, " ");

        std::istringstream iss{ln};
        int id;
        iss >> id;

        std::vector<int>& connected = village[id];

        for(;iss >> id;)
            connected.push_back(id);
    }


    std::function<int(int)> fPart1 = [&](int start) {
        int total{0};
        seen[start] = true;
        for(const auto& connection : village[start]) {
            if(seen[connection] == false) {
                ++total;
                total += fPart1(connection);

                seen[connection] = true;
            }
        }
        return total;
    };

    std::function<int()> fPart2 = [&]() {
        int groups{0};
        for(const auto& [id, connections] : village) {
            if(!seen[id]) {
                fPart1(id);
                ++groups;
            }
        }
            return groups;
    };

    os << (part2 ? fPart2() : fPart1(0) + 1) << '\n';

}
