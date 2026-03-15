// https://projecteuler.net/problem=47

// The first two consecutive numbers to have two distinct prime factors are:

// 14 = 2 × 7
// 15 = 3 × 5.

// The first three consecutive numbers to have three distinct prime factors are:

// 644 = 2² × 7 × 23
// 645 = 3 × 5 × 43
// 646 = 2 × 17 × 19.

// Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?

// Answer: 134043

// Authored by: Tim Varley 💘
// Assisted-by: Grok Code Fast via Crush 💘 <crush@charm.land>

#include <iostream>
#include <vector>
#include <set>

int count_distinct_factors(int n) {
    std::set<int> factors;
    int num = n;
    for (int i = 2; i * i <= num; ++i) {
        while (num % i == 0) {
            factors.insert(i);
            num /= i;
        }
    }
    if (num > 1) factors.insert(num);
    return factors.size();
}

int distinct_prime_factors() {
    int n = 2;
    while (true) {
        if (count_distinct_factors(n) == 4 &&
            count_distinct_factors(n+1) == 4 &&
            count_distinct_factors(n+2) == 4 &&
            count_distinct_factors(n+3) == 4) {
            return n;
        }
        ++n;
    }
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << distinct_prime_factors() << std::endl;
}
#endif // UNITTEST_MODE