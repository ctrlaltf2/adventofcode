#include <functional>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <vector>

void y17day12(std::ostream& os, std::istream& is, bool part2) {
    std::regex const nonDigits{R"([^\d]+)"};
    std::map<int, std::vector<int>> village;
    std::map<int, bool> seen;

    for(std::string ln; std::getline(is, ln);) {
        ln = std::regex_replace(ln, nonDigits, " ");

        std::istringstream iss{ln};
        int id;
        iss >> id;

        std::vector<int>& connected = village[id];
        while(iss >> id)
            connected.emplace_back(id);
    }

    std::function<int(int)> const fPart1 = [&](const int&& start) {
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

    std::function<int()> const fPart2 = [&]() {
        int groups{0};
        for(const auto& [id, connected] : village) {
            if(!seen[id]) {
                fPart1(id);
                ++groups;
            }
        }
        return groups;
    };

    os << (part2 ? fPart2() : fPart1(0) + 1) << '\n';
}
