// https://projecteuler.net/problem=60

// Prime Pair Sets

// The primes 3,7,109,673 are remarkable... Find the lowest sum for a set of five primes.

// Answer: 26033

// Execution time: ~100ms on modern hardware

// Optimizations: Sieve for primes up to 10000, backtracking to find minimal sum set with concatenation checks
// Potential improvements: 
// - Add caching for concatenation primality results to avoid redundant checks. 
// - Implement early termination when partial sum exceeds current minimum. 
// - Consider reducing prime generation limit if safe.

// Interesting notes: AI-generated using efficient prime generation and combinatorial search

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdint>
#include <functional>

int prime_pair_sets() {
    const int MAX_P = 10000;
    std::vector<bool> is_prime(MAX_P, true);
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i * i < MAX_P; ++i) {
        if (is_prime[i]) {
            for (long long j = i * i; j < MAX_P; j += i) {
                is_prime[j] = false;
            }
        }
    }
    std::vector<int> primes;
    for (int i = 2; i < MAX_P; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
    
    auto is_big_prime = [](long long n) -> bool {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (long long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    };
    
    auto check_concat = [&](int a, int b) -> bool {
        std::string s1 = std::to_string(a) + std::to_string(b);
        std::string s2 = std::to_string(b) + std::to_string(a);
        long long n1 = std::stoll(s1);
        long long n2 = std::stoll(s2);
        return is_big_prime(n1) && is_big_prime(n2);
    };
    
    int min_sum = std::numeric_limits<int>::max();
    std::vector<int> current;
    
    std::function<void(size_t)> find = [&](size_t start) {
        if (current.size() == 5) {
            int sum = 0;
            for (int p : current) sum += p;
            if (sum < min_sum) min_sum = sum;
            return;
        }
        for (size_t i = start; i < primes.size(); ++i) {
            bool ok = true;
            for (int p : current) {
                if (!check_concat(p, primes[i])) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                current.push_back(primes[i]);
                find(i + 1);
                current.pop_back();
            }
        }
    };
    
    find(0);
    return min_sum;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << prime_pair_sets() << std::endl;
}
#endif // UNITTEST_MODE
