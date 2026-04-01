// https://projecteuler.net/problem=80
// Square Root Digital Expansion
//
// It is well known that if the square root of a natural number is not an integer, then it is irrational. The decimal expansion of such square roots is infinite without any repeating pattern at all.
//
// The square root of two is 1.41421356237309504880..., and the digital sum of the first one hundred decimal digits is 475.
//
// For the first one hundred natural numbers, find the total of the digital sums of the first one hundred decimal digits for all the irrational square roots.
//
// Answer: 40886

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::string get_sqrt_digits(int n, int digits) {
    int int_part = (int)std::sqrt(n);
    long long remainder = (long long)n - (long long)int_part * int_part;
    std::string result = std::to_string(int_part) + ".";
    long long current = int_part;
    for (int i = 0; i < digits; ++i) {
        remainder *= 100;
        long long x = current * 20;
        int digit = 0;
        for (int d = 0; d < 10; ++d) {
            if ((x + d) * d <= remainder) {
                digit = d;
            }
        }
        result += '0' + digit;
        current = current * 10 + digit;
        remainder -= (x + digit) * digit;
    }
    return result;
}

int square_root_digital_expansion() {
    int total = 0;
    for (int n = 1; n <= 100; ++n) {
        int sqrt_n = (int)std::sqrt(n);
        if (sqrt_n * sqrt_n == n) continue; // integer
        std::string s = get_sqrt_digits(n, 100);
        for (char c : s) {
            if (c >= '0' && c <= '9') total += c - '0';
        }
    }
    return total;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    std::cout << "Answer: " << square_root_digital_expansion() << std::endl;
}
#endif