// https://projecteuler.net/problem=85
// Counting Rectangles
//
// By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains eighteen rectangles:
//
// Although there exists no rectangular grid that contains exactly two million rectangles, find the area of the grid with the nearest solution.
//
// Answer: 2772

#include <iostream>
#include <cmath>
#include <climits>

int counting_rectangles() {
    long long target = 2000000;
    long long min_diff = LLONG_MAX;
    int best_area = 0;
    for (int m = 1; m <= 2000; ++m) {
        for (int n = 1; n <= 2000; ++n) {
            long long rect = (long long)m * (m + 1) / 2 * n * (n + 1) / 2;
            long long diff = std::abs(rect - target);
            if (diff < min_diff) {
                min_diff = diff;
                best_area = m * n;
            }
        }
    }
    return best_area;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    std::cout << "Answer: " << counting_rectangles() << std::endl;
}
#endif