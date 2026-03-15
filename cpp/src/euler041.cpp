// https://projecteuler.net/problem=41

// We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

// What is the largest n-digit pandigital prime that exists?

// Answer: 7652413

// Authored by: Tim Varley 💘

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

long long pandigital_prime() {
    std::string digits = "1234567";
    std::sort(digits.begin(), digits.end());
    long long max_prime = 0;
    do {
        long long num = std::stoll(digits);
        bool is_prime = true;
        if (num <= 1) is_prime = false;
        else if (num == 2) is_prime = true;
        else if (num % 2 == 0) is_prime = false;
        else {
            for (long long i = 3; i * i <= num; i += 2) {
                if (num % i == 0) {
                    is_prime = false;
                    break;
                }
            }
        }
        if (is_prime) {
            if (num > max_prime) max_prime = num;
        }
    } while (std::next_permutation(digits.begin(), digits.end()));
    return max_prime;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << pandigital_prime() << std::endl;
}
#endif // UNITTEST_MODE