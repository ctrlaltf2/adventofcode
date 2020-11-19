#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

void y17day3(std::ostream& os, std::istream& is, bool part2) {
    int port;
    is >> port;

    auto squareCeil = [](const int num) -> int {
        int square = std::ceil(std::sqrt(num));

        if(square % 2 == 0)
            square += 1;

        return std::pow(square, 2);
    };

    int const cellNum  = std::ceil(std::sqrt(squareCeil(port)) / 2);
    int const gridSize = 2 * cellNum - 1;

    std::vector<std::vector<int>> grid(gridSize, std::vector<int>(gridSize, 0));
    std::array<int, 4> dx = {1, 0, -1, 0}, dy = {0, -1, 0, 1};

    int x = gridSize / 2, y = gridSize / 2, jump = 1, prev = -1;

    grid[y][x] = 1;
    for(int i = grid[y][x], k = 0; (prev < port) && (i < port); ++k) {
        for(int j = 0; (j < jump) && (i != port) && (prev < port);
            ++j, i += part2, prev = grid[y][x]) {
            x += dx[k % 4], y += dy[k % 4];

            if(part2) {
                for(int cy = -1; cy <= 1; ++cy) {
                    for(int cx = -1; cx <= 1; ++cx) {
                        if(cx == 0 && cy == 0)
                            continue;

                        try {
                            grid[y][x] += grid.at(cy + y).at(cx + x);
                        } catch(std::out_of_range& e) {
                        }
                    }
                }
            } else
                grid[y][x] = ++i;
        }

        if(k % 2 == 1)
            ++jump;
    }

    if(part2)
        os << prev << '\n';
    else
        os << (std::abs(x - gridSize / 2) + std::abs(y - gridSize / 2)) << '\n';
}
