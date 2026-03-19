// https://projecteuler.net/problem=55

// Lychrel Numbers

// If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

// Not all numbers produce palindromes so quickly. For example,
// 349 + 943 = 1292
// 1292 + 2921 = 4213
// 4213 + 3124 = 7337
// That is, 349 took three iterations to arrive at a palindrome.

// Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome.
// A number that never forms a palindrome through the reverse and add process is called a Lychrel number.
// Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume
// that a number is Lychrel until proven otherwise.
// In addition you are given that for every number below ten-thousand, it will either
// (i) become a palindrome in less than fifty iterations, or,
// (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome.
// In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome:
// 4668731596684224866951378664 (53 iterations, 28-digits).

// Surprisingly, there are palindromic numbers that are themselves Lychrel numbers;
// the first example is 4994.

// How many Lychrel numbers are there below ten-thousand?

// Answer: 249

#include <iostream>
#include <string>
#include <algorithm>

static std::string add_strings(const std::string& a, const std::string& b) {
    std::string result;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }
    std::reverse(result.begin(), result.end());
    return result;
}

static bool is_palindrome_lychrel(const std::string& s) {
    std::string rev = s;
    std::reverse(rev.begin(), rev.end());
    return s == rev;
}

bool is_lychrel(long long n) {
    std::string n_str = std::to_string(n);
    for (int iter = 0; iter < 50; ++iter) {
        std::string rev = n_str;
        std::reverse(rev.begin(), rev.end());
        std::string sum_str = add_strings(n_str, rev);
        if (is_palindrome_lychrel(sum_str)) return false;
        n_str = sum_str;
    }
    return true;
}

int lychrel_numbers() {
    int count = 0;
    for (long long i = 1; i < 10000; ++i) {
        if (is_lychrel(i)) ++count;
    }
    return count;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << lychrel_numbers() << std::endl;
}
#endif // UNITTEST_MODE