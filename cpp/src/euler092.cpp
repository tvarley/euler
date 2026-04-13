// Problem 92: Square digit chains
// https://projecteuler.net/problem=92
// Find how many starting numbers below ten million will arrive at 89.

#include <iostream>
#include <vector>

const int MAX_SUM = 9 * 9 * 7 + 1; // 7 digits max for 10^7 -1

std::vector<int> memo(MAX_SUM, 0); // 0 not computed, 1 leads to 1, 2 leads to 89

int sum_square_digits(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

int get_chain_end(int n) {
    if (n == 1) return 1;
    if (n == 89) return 2;
    if (memo[n] != 0) return memo[n];
    return memo[n] = get_chain_end(sum_square_digits(n));
}

long long square_digit_chains() {
    long long count = 0;
    for (int i = 1; i < 10000000; ++i) {
        if (get_chain_end(sum_square_digits(i)) == 2) count++;
    }
    return count;
}

#ifndef UNITTEST_MODE
int main() {
    std::cout << square_digit_chains() << std::endl;
    return 0;
}
#endif