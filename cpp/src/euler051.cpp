// https://projecteuler.net/problem=51

// Prime Digit Replacements

// By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values:
// 13, 23, 43, 53, 73, and 83, are all prime.

// By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example
// having seven primes among the ten generated numbers, yielding the family:
// 56003, 56113, 56333, 56443, 56663, 56773, and 56993.
// Consequently 56003, being the first member of this family, is the smallest prime with this property.

// Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits)
// with the same digit, is part of an eight prime value family.

// Answer: 121313

// Execution time: <1ms on modern hardware

// Optimizations: Sieve of Eratosthenes, generate digit patterns

// Interesting notes: Pattern generation for digit replacement

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include "sieve_eratos.h"

bool is_prime(const CSieveOfEratosthenes& sieve, int n) {
    return sieve.is_prime(n);
}

int prime_digit_replacements() {
    const int LIMIT = 1000000;
    CSieveOfEratosthenes sieve(LIMIT);
    std::vector<int> primes;
    for (int i = 2; i < LIMIT; ++i) {
        if (sieve.is_prime(i)) primes.push_back(i);
    }
    int result = -1;
    for (int p : primes) {
        if (p < 100000) continue; // start from 6 digits as per Python
        std::string s = std::to_string(p);
        int len = s.size();
        for (int mask = 1; mask < (1 << len); ++mask) {
            std::vector<int> family;
            for (int d = 0; d < 10; ++d) {
                if (d == 0 && (mask & 1)) continue; // no leading zero
                std::string news = s;
                for (int i = 0; i < len; ++i) {
                    if (mask & (1 << i)) {
                        news[i] = '0' + d;
                    }
                }
                int num = std::stoi(news);
                if (sieve.is_prime(num)) {
                    family.push_back(num);
                }
            }
            if (family.size() == 8) {
                int min_in_family = *std::min_element(family.begin(), family.end());
                if (result == -1 || min_in_family < result) result = min_in_family;
            }
        }
    }
    return result;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << prime_digit_replacements() << std::endl;
}
#endif // UNITTEST_MODE