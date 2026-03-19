// https://projecteuler.net/problem=58

// Spiral Primes

// Starting with 1 and spiralling anticlockwise in the following way,
// a square spiral with side length 7 is formed.

// It is interesting to note that the odd squares lie along the bottom right diagonal,
// but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime;
// that is, a ratio of 8/13 ≈ 62%.

// If one complete new layer is wrapped around the spiral above,
// a square spiral with side length 9 will be formed.
// If this process is continued, what is the side length of the square spiral
// for which the ratio of primes along both diagonals first falls below 10%?

// Answer: 26241

#include <iostream>
#include <cstdint>

// Miller-Rabin primality test for 32-bit integers
static bool is_prime(uint32_t n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    // Write n-1 as d * 2^s
    uint32_t d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        ++s;
    }

    // Deterministic bases for 32-bit integers
    const uint32_t bases[] = {2, 7, 61};
    for (uint32_t a : bases) {
        if (a >= n) continue;
        uint64_t x = 1;
        uint64_t base = a;
        uint32_t exp = d;
        // modular exponentiation: x = a^d mod n
        while (exp > 0) {
            if (exp & 1) x = (x * base) % n;
            base = (base * base) % n;
            exp >>= 1;
        }
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (int r = 1; r < s; ++r) {
            x = (x * x) % n;
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

// Find side length where prime ratio falls below 10%
int spiral_primes() {
    uint64_t num_primes = 0;
    uint64_t total_diagonals = 1; // include center 1
    uint32_t side = 1;
    while (true) {
        side += 2; // next odd side length
        uint32_t lower_right = side * side;
        uint32_t lower_left = lower_right - (side - 1);
        uint32_t upper_left = lower_left - (side - 1);
        // upper_right = upper_left - (side - 1) is a square (odd square) and not prime
        // check three corners
        if (is_prime(lower_left)) ++num_primes;
        if (is_prime(upper_left)) ++num_primes;
        // upper_right is square, skip
        total_diagonals += 4;
        // compute ratio: primes / total_diagonals
        if (num_primes * 100 < total_diagonals * 10) { // ratio < 10%
            return side;
        }
    }
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << spiral_primes() << std::endl;
}
#endif // UNITTEST_MODE