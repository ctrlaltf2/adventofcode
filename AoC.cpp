#include "Days.h"

#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>

void usage(char * progname) {
    std::cout << "Usage: " << progname << " <year> " << "<day> " << " <part> [eval]\n";
    std::exit(-1);
}

int main(int argc, char ** argv) {
    std::map<std::string, std::function<void(std::ostream&, std::istream&, bool)>> funcMap {
        {"2016-1", y16day1},
        {"2016-2", y16day2},
        {"2016-3", y16day3},
        {"2017-1", y17day1},
        {"2017-2", y17day2},
        {"2017-3", y17day3},
        {"2017-4", y17day4},
        {"2017-5", y17day5} };
  
    std::string mapkey;
    bool part2 = false, eval = false;
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

    if(argc > 4)
        if(std::string(argv[4]) == "eval")
            eval = true;

    if(mapkey != "all") {
        try {
            auto f = funcMap.at(mapkey);
            if(!eval) {
                std::ifstream data("data/" + mapkey + ".txt");
                f(std::cout, data, part2);
            } else
                f(std::cout, std::cin, part2);
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


