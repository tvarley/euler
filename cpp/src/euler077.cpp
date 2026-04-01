// https://projecteuler.net/problem=77
// Prime Summations
//
// It is possible to write ten as the sum of primes in exactly five different ways:
//
// 7 + 3
// 5 + 5
// 5 + 3 + 2
// 3 + 3 + 2 + 2
// 2 + 2 + 2 + 2 + 2
//
// What is the first value which can be written as the sum of primes in over five thousand different ways?
//
// Answer: 71

#include <iostream>
#include <vector>

int prime_summations()
{
    const int N = 1000;
    std::vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            for (long long j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    std::vector<int> primes;
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
    std::vector<long long> ways(N + 1, 0);
    ways[0] = 1;
    for (int p : primes) {
        for (int j = p; j <= N; ++j) {
            ways[j] += ways[j - p];
        }
    }
    for (int n = 2; n <= N; ++n) {
        if (ways[n] > 5000) return n;
    }
    return -1;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    std::cout << "Answer: " << prime_summations() << std::endl;
}
#endif