#include "Days.h"

#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>

void usage(char * progname) {
    std::cout << "Usage: " << progname << " <year> " << "<day> " << " <part '1' or '2'>\n";
    std::exit(-1);
}

int main(int argc, char ** argv) {
    std::map<std::string, std::function<void(std::ostream&, std::istream&, bool)>> funcMap { {"2016-1", y16day1} };
  
    std::string mapkey;
    bool part2 = false;
    if(argc > 1) {
        if(std::string(argv[1]) == "all")
            mapkey = "all";
        else {
            mapkey = std::string(argv[1]) + '-' + argv[2];
            if(std::string(argv[3]) == "2")
                part2 = true;
            else if(std::string(argv[3]) == "1")
                ;
            else
                usage(argv[0]);
        }
    }
    else
        usage(argv[0]);

    if(mapkey != "all") {
        try {
            auto f = funcMap.at(mapkey);
            std::ifstream data("data/" + mapkey + ".txt");
            f(std::cout, data, part2);
        } catch(std::out_of_range e) {
            usage(argv[0]);
        }
    } else {
        for(auto& p : funcMap) {
            std::ifstream data("data/" + p.first + ".txt");
            std::cout << p.first << "-part1: ";
            p.second(std::cout, data, false);

            data.clear();
            data.seekg(0, std::ios::beg);

            std::cout << p.first << "-part2: ";
            p.second(std::cout, data, true);
        }
    }
}


