// https://projecteuler.net/problem=33

// The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

// We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

// There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

// If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

// Answer: 100

// Authored by: Tim Varley 💘

#include <iostream>
#include <numeric>

int digit_cancelling_fractions() {
    long long num = 16LL * 19 * 26 * 49;
    long long den = 64LL * 95 * 65 * 98;
    long long g = std::gcd(num, den);
    num /= g;
    den /= g;
    return den;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << digit_cancelling_fractions() << std::endl;
}
#endif // UNITTEST_MODE