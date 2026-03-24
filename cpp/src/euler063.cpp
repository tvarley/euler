// https://projecteuler.net/problem=63

// Powerful Digit Counts

// The 5-digit number, 16807=7^5, is also a fifth power. Similarly, the 9-digit number, 134217728=8^9, is a ninth power.
// How many n-digit positive integers exist which are also an nth power?

// Answer: 49

// Execution time: ~0ms on modern hardware

// Optimizations: Mathematical logarithmic approach using log10 to compute exact count without power calculations

#include <iostream>
#include <cmath>

int powerful_digit_counts() {
    int count = 0;
    for (int a = 1; a <= 9; ++a) {
        double log_a = std::log10(static_cast<double>(a));
        int max_n = static_cast<int>(1.0 / (1.0 - log_a));
        count += max_n;
    }
    return count;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << powerful_digit_counts() << std::endl;
}
#endif // UNITTEST_MODE