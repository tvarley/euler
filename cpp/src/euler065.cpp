// https://projecteuler.net/problem=65

// Convergents of e

// The square root of 2 can be written as an infinite continued fraction.
// √2 = 1 + 1/(2 + 1/(2 + 1/(2 + ...)))
// The infinite continued fraction can be written, √2 = [1;(2)], (2) indicates that 2 repeats ad infinitum.
// In a similar way, √23 = [4; (1,3,1,8)].
// It turns out that the sequence of partial values of continued fractions for square roots provide the best rational approximations.
// Let us consider the convergents for √2.
// 1 + 1/2 = 3/2
// 1 + 1/(2 + 1/2) = 7/5
// 1 + 1/(2 + 1/(2 + 1/2)) = 17/12
// 1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29
// Hence the sequence of the first ten convergents for √2 are:
// 1, 3/2, 7/5, 17/12, 41/29, 99/70, 239/169, 577/408, 1393/985, 3363/2378, ...
// What is most surprising is that the important mathematical constant,
// e = [2; 1, 2, 1, 1, 4, 1, 1, 6, 1, ..., 1, 2k, 1, ...]
// The first ten terms in the sequence of convergents for e are:
// 2, 3, 8/3, 11/4, 19/7, 87/32, 106/39, 193/71, 1264/465, 1457/536, ...
// The sum of digits in the numerator of the 10th convergent is 1+4+5+7=17.
// Find the sum of digits in the numerator of the 100th convergent of the continued fraction for e.

// Answer: 272

// Execution time: ~0ms on modern hardware

// Optimizations: Simple big integer arithmetic using strings for numerator calculation
// Interesting notes: AI-generated solution implementing continued fraction convergents with string-based big integers

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

static std::string add_big(const std::string& a, const std::string& b) {
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

static std::string multiply_big(const std::string& a, int b) {
    std::string result;
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; --i) {
        int prod = (a[i] - '0') * b + carry;
        carry = prod / 10;
        result.push_back(prod % 10 + '0');
    }
    while (carry) {
        result.push_back(carry % 10 + '0');
        carry /= 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

static int sum_digits_big(const std::string& s) {
    int sum = 0;
    for (char c : s) sum += c - '0';
    return sum;
}

int convergents_of_e() {
    std::vector<int> terms;
    terms.push_back(2);
    for (int k = 1; ; ++k) {
        terms.push_back(1);
        terms.push_back(2 * k);
        terms.push_back(1);
        if (terms.size() >= 101) break;
    }
    std::string h_prev2 = "0";
    std::string h_prev1 = "1";
    std::string k_prev2 = "1";
    std::string k_prev1 = "0";
    for (int i = 0; i < 100; ++i) {
        std::string h = add_big(multiply_big(h_prev1, terms[i]), h_prev2);
        std::string k = add_big(multiply_big(k_prev1, terms[i]), k_prev2);
        h_prev2 = h_prev1;
        h_prev1 = h;
        k_prev2 = k_prev1;
        k_prev1 = k;
    }
    return sum_digits_big(h_prev1);
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << convergents_of_e() << std::endl;
}
#endif // UNITTEST_MODE