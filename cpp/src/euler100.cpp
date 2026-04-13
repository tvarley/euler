// Problem 100: Arranged probability
// https://projecteuler.net/problem=100
// Find the smallest number of blue discs b such that the total number of discs n > 10^12 and b(b-1)/(n(n-1)) = 1/2.
// Uses Pell-like recurrence to generate solutions to 2b(b-1) = n(n-1).

#include <iostream>
#include <cmath>

long long arranged_probability() {
    // Use the recurrence for solutions to 2b(b-1) = n(n-1)
    // Find the smallest b where n > 10^12
    long long b = 15, n = 21;
    while (n <= 1000000000000LL) {
        long long b_new = 3 * b + 2 * n - 2;
        long long n_new = 4 * b + 3 * n - 3;
        b = b_new;
        n = n_new;
    }
    return b;
}

#ifndef UNITTEST_MODE
int main() {
    std::cout << arranged_probability() << std::endl;
    return 0;
}
#endif