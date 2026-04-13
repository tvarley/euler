// Problem 87: Prime power triples
// https://projecteuler.net/problem=87
// Find the number of numbers below fifty million that can be expressed as the sum of a prime square, prime cube, and prime fourth power.

#include <iostream>
#include <vector>
#include <set>

const long long LIMIT = 50000000;

std::vector<int> primes;

void generate_primes(int max_n) {
    std::vector<bool> is_prime(max_n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i <= max_n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j <= max_n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

long long prime_power_triples() {
    int max_prime = 0;
    while ((long long)max_prime * max_prime < LIMIT) max_prime++;
    max_prime--;
    generate_primes(max_prime);

    std::set<long long> numbers;
    for (int p4 : primes) {
        long long fourth = (long long)p4 * p4 * p4 * p4;
        if (fourth >= LIMIT) break;
        for (int p3 : primes) {
            long long cube = (long long)p3 * p3 * p3;
            if (fourth + cube >= LIMIT) break;
            for (int p2 : primes) {
                long long square = (long long)p2 * p2;
                long long sum = fourth + cube + square;
                if (sum >= LIMIT) break;
                numbers.insert(sum);
            }
        }
    }
    return numbers.size();
}

#ifndef UNITTEST_MODE
int main() {
    std::cout << prime_power_triples() << std::endl;
    return 0;
}
#endif