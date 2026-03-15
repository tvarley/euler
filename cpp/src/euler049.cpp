// https://projecteuler.net/problem=49

// The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

// There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

// What 12-digit number do you form by concatenating the three terms in this sequence?

// Answer: 296962999629

// Authored by: Tim Varley 💘
// Assisted-by: Grok Code Fast via Crush 💘 <crush@charm.land>

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "sieve_eratos.h"

std::string prime_permutations() {
    const int LIMIT = 10000;
    CSieveOfEratosthenes primes(LIMIT);
    std::vector<int> four_digit_primes;
    for (int i = 1000; i < LIMIT; ++i) {
        if (primes.is_prime(i)) four_digit_primes.push_back(i);
    }
    for (size_t i = 0; i < four_digit_primes.size(); ++i) {
        for (size_t j = i + 1; j < four_digit_primes.size(); ++j) {
            for (size_t k = j + 1; k < four_digit_primes.size(); ++k) {
                int a = four_digit_primes[i], b = four_digit_primes[j], c = four_digit_primes[k];
                if (a != 1487 && b - a == 3330 && c - b == 3330) {
                    std::string sa = std::to_string(a), sb = std::to_string(b), sc = std::to_string(c);
                    std::sort(sa.begin(), sa.end());
                    std::sort(sb.begin(), sb.end());
                    std::sort(sc.begin(), sc.end());
                    if (sa == sb && sb == sc) {
                        return std::to_string(a) + std::to_string(b) + std::to_string(c);
                    }
                }
            }
        }
    }
    return "";
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << prime_permutations() << std::endl;
}
#endif // UNITTEST_MODE