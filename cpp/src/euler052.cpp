// https://projecteuler.net/problem=52

// Permuted Multiples

// It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
// Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

// Answer: 142857

#include <iostream>
#include <string>
#include <algorithm>

bool same_digits(long long a, long long b) {
    std::string sa = std::to_string(a);
    std::string sb = std::to_string(b);
    if (sa.size() != sb.size()) return false;
    std::sort(sa.begin(), sa.end());
    std::sort(sb.begin(), sb.end());
    return sa == sb;
}

long long permuted_multiples() {
    long long x = 1;
    while (true) {
        bool ok = true;
        for (int m = 2; m <= 6; ++m) {
            if (!same_digits(x, x * m)) {
                ok = false;
                break;
            }
        }
        if (ok) return x;
        ++x;
    }
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << permuted_multiples() << std::endl;
}
#endif // UNITTEST_MODE