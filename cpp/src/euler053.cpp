// https://projecteuler.net/problem=53

// Combinatoric Selections

// There are exactly ten ways of selecting three from five, 12345:
// 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

// In combinatorics, we use the notation, \binom 5 3 = 10.
// In general, \binom n r = \dfrac{n!}{r!(n-r)!}, where r ≤ n, n! = n × (n-1) × ... × 3 × 2 × 1, and 0! = 1.

// It is not until n = 23, that a value exceeds one-million: \binom {23} {10} = 1144066.

// How many, not necessarily distinct, values of \binom n r for 1 ≤ n ≤ 100, are greater than one-million?

// Answer: 4075

#include <iostream>

int combinatoric_selections() {
    int count = 0;
    for (int n = 1; n <= 100; ++n) {
        for (int r = 0; r <= n; ++r) {
            long double c = 1.0L;
            for (int i = 1; i <= r; ++i) {
                c *= (n - r + i);
                c /= i;
            }
            if (c > 1000000.0L) ++count;
        }
    }
    return count;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << combinatoric_selections() << std::endl;
}
#endif // UNITTEST_MODE