// Problem 97: Large non-Mersenne prime
// https://projecteuler.net/problem=97
// Find the last ten digits of 28433 × 2^7830457 + 1.

#include <iostream>

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            // Use __int128 to avoid overflow in multiplication
            __int128 temp = (__int128)result * base % mod;
            result = temp;
        }
        __int128 temp_base = (__int128)base * base % mod;
        base = temp_base;
        exp /= 2;
    }
    return result;
}

long long large_non_mersenne_prime() {
    const long long MOD = 10000000000LL; // 10^10
    long long pow2 = mod_pow(2, 7830457, MOD);
    // Use __int128 for the final multiplication to avoid overflow
    __int128 temp = (__int128)28433LL * pow2 % MOD;
    long long result = (temp + 1) % MOD;
    return result;
}

#ifndef UNITTEST_MODE
int main() {
    std::cout << large_non_mersenne_prime() << std::endl;
    return 0;
}
#endif