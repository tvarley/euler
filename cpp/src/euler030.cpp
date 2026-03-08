// https://projecteuler.net/problem=30

// Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
//
// 1634 = 1^4 + 6^4 + 3^4 + 4^4
// 8208 = 8^4 + 2^4 + 0^4 + 8^4
// 9474 = 9^4 + 4^4 + 7^4 + 4^4
//
// As 1 = 1^4 is not a sum it is not included.
//
// The sum of these numbers is 1634 + 8208 + 9474 = 19316.
//
// Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
//
// Answer: 443839

// Authored by: Tim Varley 💘
// Assisted-by: Grok Code Fast via Crush 💘 <crush@charm.land>

#include <iostream>
#include <vector>

int sum_of_fifth_powers_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        int power = 1;
        for (int i = 0; i < 5; ++i) power *= digit;
        sum += power;
        n /= 10;
    }
    return sum;
}

int sum_digit_fifth_powers() {
    int total = 0;
    // Upper bound: 6 * 9^5 = 354294
    for (int i = 2; i <= 354294; ++i) {
        if (sum_of_fifth_powers_of_digits(i) == i) {
            total += i;
        }
    }
    return total;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << sum_digit_fifth_powers() << std::endl;
}
#endif // UNITTEST_MODE