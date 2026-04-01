// Problem 90: Cube digit pairs
// https://projecteuler.net/problem=90
// Count distinct pairs of 6-sided cubes (digits 0-9) that can form all 2-digit squares (01..81).
// Uses bitmasks (10 bits) for each cube instead of sets; treats 6/9 as interchangeable via bitwise checks.
// Generates C(10,6)=210 cubes, checks unordered pairs (i < j). O(1) per test case.

#include <iostream>
#include <vector>

bool has_digit(int mask, int d) {
    if (mask & (1 << d)) return true;
    if (d == 6 && (mask & (1 << 9))) return true;
    if (d == 9 && (mask & (1 << 6))) return true;
    return false;
}

bool can_form_square(int mask_a, int mask_b, int sq) {
    int d1 = sq / 10, d2 = sq % 10;
    bool a1 = has_digit(mask_a, d1), a2 = has_digit(mask_a, d2);
    bool b1 = has_digit(mask_b, d1), b2 = has_digit(mask_b, d2);
    return (a1 && b2) || (a2 && b1);
}

long long cube_digit_pairs() {
    std::vector<int> squares = {1, 4, 9, 16, 25, 36, 49, 64, 81};
    std::vector<int> cubes;
    for (int i = 0; i < (1 << 10); ++i) {
        if (__builtin_popcount(i) == 6) {
            cubes.push_back(i);
        }
    }
    long long count = 0;
    int n = cubes.size();
    for (int i = 0; i < n; ++i) {
        int ma = cubes[i];
        for (int j = i + 1; j < n; ++j) {
            int mb = cubes[j];
            bool ok = true;
            for (int sq : squares) {
                if (!can_form_square(ma, mb, sq)) {
                    ok = false;
                    break;
                }
            }
            if (ok) ++count;
        }
    }
    return count;
}

#ifndef UNITTEST_MODE
int main() {
    std::cout << cube_digit_pairs() << std::endl;
    return 0;
}
#endif