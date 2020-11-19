#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

struct Program {
    std::string name;
    int weight, total;
    Program* parent{nullptr};

    std::vector<std::string> cnames;
    std::vector<Program*> children;
};

class Tower {
    std::map<std::string, Program> m_lookup;

  public:
    Tower(std::istream& is) {
        for(std::string ln; std::getline(is, ln, '\n');) {
            std::regex const re{R"([^\w])"};
            std::string modified = std::regex_replace(ln, re, " "), name;
            int weight;
            std::istringstream ss{modified};
            ss >> name >> weight;

            std::vector<std::string> names;
            for(std::string s; ss >> s;)
                names.emplace_back(s);

            m_lookup[name] = Program{name, weight, 0, nullptr, names};
        }

        for(auto& p : m_lookup) {
            auto& prog = p.second;

            for(auto& cname : prog.cnames) {
                prog.children.push_back(&m_lookup.at(cname));
                m_lookup.at(cname).parent = &prog;
            }
        }
    }

    Program* findRoot() {
        Program* p = &(m_lookup.begin()->second);

        while(p->parent)
            p = p->parent;

        return p;
    }

    // Poor name for this but basically it fills out the 'total' member for all the nodes below the given parameter
    // Total is equal to the program's weight + the total weight of all the programs below it
    int memoize(Program* p) {
        if(p->children.size() == 0)
            return (p->total = p->weight);
        else
            return (p->total = std::accumulate(
                      p->children.begin(), p->children.end(), p->weight, [&](auto t, auto& elem) {
                          return t + memoize(elem);
                      }));
    }

    //    void badNodes() {
    //        this->memoize(this->findRoot());
    //            auto f = [](Program* p) {
    //                if(p->children.size() < 2)
    //                    return;
    //
    //                std::vector<int> ctotals;
    //                for(auto& child : p->children)
    //                    ctotals.push_back(child->total);
    //
    //                std::sort(ctotals.begin(), ctotals.end());
    //
    //                int oddOneOut{0};
    //                // Sort then compare the first two and last two to see which is the odd one out if any
    //                if(std::min(*ctotals.begin(), *std::next(ctotals.begin(), 1)) != *ctotals.begin())
    //                    oddOneOut = *ctotals.begin();
    //                else if(std::max(*std::prev(ctotals.end(), 2), *std::prev(ctotals.end(), 1)) != *std::prev(ctotals.end(), 2))
    //                    oddOneOut = *std::prev(ctotals.end(), 1);
    //
    //                if(oddOneOut != 0) {
    //                    std::cout << p->name << ':' << oddOneOut << std::endl;
    //                    for(auto& child : p->children)
    //                        if(p->total == oddOneOut)
    //                            return f(child);
    //                } else {
    //                    return
    //                }
    //            };
    //    }

    void print() {
        for(const auto& pair : m_lookup) {
            auto& prog = pair.second;
            std::cout << prog.name << ' ' << prog.weight << ':' << prog.total << " supports ";
            for(const auto& child : prog.children) {
                std::cout << (*child).name << ' ' << (*child).weight << ':' << (*child).total
                          << ", ";
            }
            std::cout << '\n';
        }
    }
};

void y17day7(std::ostream& os, std::istream& is, bool part2) {
    Tower t(is);

    if(!part2)
        os << t.findRoot()->name << '\n';
    else
        //      t.badNodes();

        t.print();
}
