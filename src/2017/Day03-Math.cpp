#include <cmath>
#include <iostream>

void y17day3(std::ostream& os, std::istream& is, bool part2) {
    int port;
    is >> port;

    // 'Round' number up to the nearest odd perfect square
    auto squareCeil = [](const int num) -> int {
        int square = std::ceil(std::sqrt(num));

        if(square % 2 == 0)
            square += 1;

        return std::pow(square, 2);
    };

    int const cellNum = std::ceil(std::sqrt(squareCeil(port)) / 2); // Number of squares surrounding the center number (1)
    int const gridSize = 2 * cellNum - 1;

    // Bounds for line from upper right to lower left
    auto uRbLBound = [](const int x) -> int {
        // x^2 - x + 1
        return std::pow(x, 2) - x + 1;
    };

    int const bottomLeft    = uRbLBound(cellNum * 2 - 1); // f(2x - 1)
    int const topRight      = uRbLBound(cellNum * 2 - 2); // f(2(x-1))
    int const bottomRight   = squareCeil(port);
    // (sqrt(bottomRight) - 1)^2 + 1
    int const topLeft       = std::pow(std::sqrt(squareCeil(port)) - 1, 2) + 1;

    /* Find what 'quadrant' the number is in and based on that, the number's coordinates in
     * a 2d matrix where the quadrants are laid out like
     * \ 2 /
     *3 \ /
     *  / \ 1
     * / 4 \
     *
     */

    // Absolute value of coordinate *relative* to the center
    int x{0}, y{0};

    if((topRight - gridSize - 1) <= port && port < topRight) { // Quadrant 1
        int center = topRight - cellNum + 1; // Center point between the two quadrant bounds
        x = cellNum - 1, y = std::abs(port - center);
    } else if(topRight <= port && port < topLeft) { // Quadrant 2
        int center = topLeft - cellNum + 1;
        y = cellNum - 1, x = std::abs(port - center);
    } else if(topLeft <= port && port < bottomLeft) { // Quadrant 3
        int center = bottomLeft - cellNum + 1;
        x = cellNum - 1, y = std::abs(port - center);
    } else if(bottomLeft <= port && port < bottomRight) { // Quadrant 4
        int center = bottomRight - cellNum + 1;
        y = cellNum - 1, x = std::abs(port - center);
    } else if(port == bottomRight) { // Edge case because of spiral pattern
        x = gridSize / 2, y = gridSize / 2;
    }

    os << x + y << '\n';
}
