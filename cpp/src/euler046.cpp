// https://projecteuler.net/problem=46

// It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

// 9 = 7 + 2×1²
// 15 = 7 + 2×2²
// 21 = 3 + 2×3²
// 25 = 7 + 2×3²
// 27 = 19 + 2×2²
// 33 = 31 + 2×1²

// It turns out that the conjecture was false.

// What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

// Answer: 5777

// Authored by: Tim Varley 💘

#include <iostream>
#include "sieve_eratos.h"

int goldbach_other() {
    const int LIMIT = 10000;
    CSieveOfEratosthenes primes(LIMIT);
    for (int n = 9; ; n += 2) {
        if (!primes.is_prime(n)) { // odd composite
            bool found = false;
            for (int p = 2; p < n; ++p) {
                if (primes.is_prime(p)) {
                    int sq = (n - p) / 2;
                    int k = 1;
                    while (k * k < sq) ++k;
                    if (k * k == sq) {
                        found = true;
                        break;
                    }
                }
            }
            if (!found) return n;
        }
    }
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << goldbach_other() << std::endl;
}
#endif // UNITTEST_MODE