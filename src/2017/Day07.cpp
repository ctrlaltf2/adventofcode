#include <algorithm>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

struct Program {
    std::string name;
    int weight;
    Program* parent{nullptr};

    std::vector<std::string> cnames;
    std::vector<Program*> children;
};


class Tower {
    std::map<std::string, Program> m_lookup;

public:
    Tower(std::istream& is) {
        for(std::string ln;std::getline(is, ln, '\n');) {
            std::regex const re {R"([^\w])"};
            std::string modified = std::regex_replace(ln, re, " "), name;
            int weight;
            std::istringstream ss{modified};
            ss >> name >> weight;

            std::vector<std::string> names;
            for(std::string s;ss >> s;)
                names.emplace_back(s);

            m_lookup[name] = Program{name, weight, nullptr, names};
        }

        for(auto& p : m_lookup) {
            [[maybe_unused]]
            auto& [name, prog] = p;

            for(auto& cname : prog.cnames) {
                prog.children.push_back(&m_lookup.at(cname));
                m_lookup.at(cname).parent = &prog;
            }
        }
    }

    std::string findRoot() {
        Program* p = &(m_lookup.begin()->second);

        while(p->parent)
            p = p->parent;

        return (*p).name;
    }
};

void y17day7(std::ostream& os, std::istream& is, bool part2) {
    Tower t(is);

    os << t.findRoot() << '\n';
}
