#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>

#include <boost/program_options.hpp>

#include "Days.h"



int main(int argc, char ** argv) {
    using namespace boost;

    std::map<std::string, std::function<void(std::ostream&, std::istream&, bool)>> const funcMap {
        {"2015-1", y15day1},
        {"2016-1", y16day1},
        {"2016-2", y16day2},
        {"2016-12", y16day12},
        {"2017-1", y17day1},
        {"2017-2", y17day2},
        {"2017-3", y17day3},
        {"2017-4", y17day4},
        {"2017-5", y17day5},
        {"2017-6", y17day6},
        {"2017-7", y17day7},
        {"2017-8", y17day8},
        {"2017-9", y17day9},
        {"2017-10", y17day10},
        {"2017-11", y17day11},
        {"2017-12", y17day12} };

    try {
        program_options::options_description desc{"Options"};
        desc.add_options()
            ("help,h", "Help")
            ("year,y", program_options::value<int>(), "Year")
            ("day,d", program_options::value<int>(), "Day")
            ("part,p", program_options::value<std::string>(), "Part")
            ("eval", "Eval")
            ("all,a", "All");

        program_options::variables_map vm;
        program_options::store(
                program_options::parse_command_line(argc, argv, desc),
                vm
        );

        if(vm.count("help")) {
            std::cout << desc << '\n';
            return 0;
        } else if(vm.count("all")) {
            for(const auto& p : funcMap) {
                std::ifstream data("data/" + p.first + ".txt");
                std::cout << p.first << "-part1: ";
                p.second(std::cout, data, false);

                data.clear();
                data.seekg(0, std::ios::beg);

                std::cout << p.first << "-part2: ";
                p.second(std::cout, data, true);
            }
            return 0;
        }

        std::string mapkey;

        if(vm.count("year"))
            mapkey += std::to_string(vm["year"].as<int>()) + '-';

        if(vm.count("day"))
            mapkey += std::to_string(vm["day"].as<int>());

        bool eval{false};
        if(vm.count("eval"))
            eval = true;

        std::string part = "both";
        if(vm.count("part"))
            part = vm["part"].as<std::string>();

        try {
            auto f = funcMap.at(mapkey);
            std::ifstream data("data/" + mapkey + ".txt");

            if(part == "1")
                f(std::cout, (eval ? std::cin : data), false);
            else if(part == "2")
                f(std::cout, (eval ? std::cin : data), true);
            else if(part == "both") {
                f(std::cout, (eval ? std::cin : data), false);

                data.clear();
                data.seekg(0, std::ios::beg);

                f(std::cout, (eval ? std::cin : data), true);
            }

        } catch(std::out_of_range e) {
            std::cout << "Invalid year/problem\n";
            std::cout << desc << '\n';
            return -1;
        }
    } catch (const program_options::error& e) {
        std::cout << e.what() << '\n';
    }
}


