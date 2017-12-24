#include <iostream>
#include <functional>
#include <map>
#include <regex>
#include <sstream>
#include <vector>

using ProgramID = int;
using Pipes = std::vector<ProgramID>;

class Village {
    std::map<ProgramID, Pipes> m_village;
    std::map<ProgramID, bool> m_seen;

    public:
        void operator()(std::string line) {
            std::regex re{R"([^\d]+)"};
            line = std::regex_replace(line, re, " ");

            std::istringstream iss{line};
            int id;
            iss >> id;

            Pipes& connected = m_village[id];

            for(int temp;iss >> temp;)
                connected.push_back(temp);
        }

        int part1(int start) {
            int total{0};
            m_seen[start] = true;
            for(const auto& connection : m_village[start]) {
                if(m_seen[connection] == false) {
                    ++total;
                    total += part1(connection);

                    m_seen[connection] = true;
                }
            }
            return total;
        }

        int part2() {
            int groups{0};
            for(const auto& [id, connections] : m_village) {
                if(!m_seen[id]) {
                    part1(id);
                    ++groups;
                }
            }
            return groups;
        }
};

void y17day12(std::ostream& os, std::istream& is, bool part2) {
    Village ville;

    for(std::string ln;std::getline(is, ln, '\n');)
        ville(ln);

    if(part2)
        std::cout << ville.part2() << '\n';
    else
        std::cout << ville.part1(0) + 1 << '\n';

}
