/**
 * Copyright [2024] <wangdc1111@gmail.com>
 * for a coding test.
 */
#include <iostream>
#include <limits>
#include "inc/IntensitySegments.hpp"

int main() {
    std::cout << "test case 1:\n";
    auto seg1 = IntensitySegments();
    seg1.toString();

    seg1.add(10, 30, 1);
    seg1.toString();

    seg1.add(20, 40, 1);
    seg1.toString();

    seg1.add(10, 40, -2);
    seg1.toString();

    std::cout << "\ntest case 2:\n";

    auto seg2 = IntensitySegments();
    seg2.toString();

    seg2.add(10, 30, 1);
    seg2.toString();

    seg2.add(20, 40, 1);
    seg2.toString();

    seg2.add(10, 40, -1);
    seg2.toString();

    seg2.add(10, 40, -1);
    seg2.toString();

    std::cout << "\ntest case 3:\n";

    auto seg3 = IntensitySegments();
    seg3.toString();

    seg3.set(10, 40, -1);
    seg3.toString();

    seg3.add(20, 40, std::numeric_limits<int>::min());
    seg3.toString();

    seg3.set(20, 40, 1);
    seg3.toString();

    seg3.add(20, 40, std::numeric_limits<int>::max());
    seg3.toString();

    seg3.set(30, 50, -1);
    seg3.toString();

    std::cout << "\ntest case 4:\n";

    auto seg4 = IntensitySegments();
    seg4.toString();

    seg4.set(5, 50, -1);
    seg4.toString();

    seg4.add(15, 45, 2);
    seg4.toString();

    seg4.set(20, 40, 1);
    seg4.toString();

    seg4.add(20, 40, -2);
    seg4.toString();

    seg4.set(-60, 60, -1);
    seg4.toString();

    seg4.set(0, 0, -1);

    seg4.set(1, 0, -1);

    return 0;
}