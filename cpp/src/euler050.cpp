// https://projecteuler.net/problem=50

// The prime 41, can be written as the sum of six consecutive primes:

// 41 = 2 + 3 + 5 + 7 + 11 + 13.

// This is the longest sum of consecutive primes that adds to a prime below one-hundred.

// The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

// Which prime, below one-million, can be written as the sum of the most consecutive primes?

// Answer: 997651

// Authored by: Tim Varley 💘

#include <iostream>
#include <vector>
#include "sieve_eratos.h"

int consecutive_prime_sum() {
    const int LIMIT = 1000000;
    CSieveOfEratosthenes primes(LIMIT);
    std::vector<int> prime_list;
    for (int i = 2; i < LIMIT; ++i) {
        if (primes.is_prime(i)) prime_list.push_back(i);
    }
    int max_length = 0;
    int result = 0;
    for (size_t start = 0; start < prime_list.size(); ++start) {
        long long sum = 0;
        for (size_t end = start; end < prime_list.size(); ++end) {
            sum += prime_list[end];
            if (sum >= LIMIT) break;
            int length = end - start + 1;
            if (length > max_length && primes.is_prime(sum)) {
                max_length = length;
                result = sum;
            }
        }
    }
    return result;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << consecutive_prime_sum() << std::endl;
}
#endif // UNITTEST_MODE