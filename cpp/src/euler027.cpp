// https://projecteuler.net/problem=27

// Euler discovered the remarkable quadratic formula:
// n² + n + 41
//
// It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39.
// However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 = 41² = 1681 is divisible by 41,
// and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.
//
// The incredible formula n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79.
// The product of the coefficients, −79 and 1601, is −126479.
//
// Considering quadratics of the form:
// n² + a*n + b, where |a| < 1000 and |b| < 1000
//
// where |n| is the modulus/absolute value of n
// e.g. |11| = 11 and |−4| = 4
//
// Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
//
// Answer: -59231

// Authored by: Tim Varley 💘

#include <iostream>
#include <cmath>

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int quadratic_primes_max_product(int max_a, int max_b) {
    int max_streak = 0;
    int best_product = 0;
    for (int a = -max_a + 1; a < max_a; ++a) {
        for (int b = 2; b <= max_b; ++b) {  // b must be prime
            if (!is_prime(b)) continue;
            int n = 0;
            while (true) {
                long long val = (long long)n * n + a * n + b;
                if (!is_prime(val)) break;
                ++n;
            }
            if (n > max_streak) {
                max_streak = n;
                best_product = a * b;
            }
        }
    }
    return best_product;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << quadratic_primes_max_product(1000, 1000) << std::endl;
}
#endif // UNITTEST_MODE