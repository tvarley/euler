// https://projecteuler.net/problem=43

// The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

// Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

// d2d3d4=406 is divisible by 2

// d3d4d5=063 is divisible by 3

// d4d5d6=635 is divisible by 5

// d5d6d7=357 is divisible by 7

// d6d7d8=572 is divisible by 11

// d7d8d9=728 is divisible by 13

// d8d9d10=289 is divisible by 17

// Find the sum of all 0 to 9 pandigital numbers with this property.

// Answer: 16695334890

// Authored by: Tim Varley 💘

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

long long substring_divisibility() {
    std::string digits = "0123456789";
    std::sort(digits.begin(), digits.end());
    std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17};
    long long sum = 0;
    do {
        bool valid = true;
        for (int i = 0; i < 7; i++) {
            int num = std::stoi(digits.substr(i + 1, 3));
            if (num % primes[i] != 0) {
                valid = false;
                break;
            }
        }
        if (valid) {
            sum += std::stoll(digits);
        }
    } while (std::next_permutation(digits.begin(), digits.end()));
    return sum;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << substring_divisibility() << std::endl;
}
#endif // UNITTEST_MODE