// https://projecteuler.net/problem=56

// Powerful Digit Sum

// A googol (10^100) is a massive number: one followed by one-hundred zeros; 100^100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.
// Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?

// Answer: 972

#include <iostream>
#include <string>
#include <algorithm>

// Multiply a big integer represented as a string by a small integer (<= 99)
static std::string multiply(const std::string& a, int b) {
    std::string result;
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; --i) {
        int prod = (a[i] - '0') * b + carry;
        carry = prod / 10;
        prod %= 10;
        result.push_back(prod + '0');
    }
    while (carry) {
        result.push_back((carry % 10) + '0');
        carry /= 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

// Compute a^b as a string
static std::string power(int a, int b) {
    std::string result = "1";
    for (int i = 0; i < b; ++i) {
        result = multiply(result, a);
    }
    return result;
}

// Compute sum of digits of a number represented as a string
static int digit_sum(const std::string& s) {
    int sum = 0;
    for (char c : s) {
        sum += c - '0';
    }
    return sum;
}

// Find the maximum digital sum for a^b where a, b < 100
int max_digital_sum() {
    int max_sum = 0;
    for (int a = 2; a < 100; ++a) {
        for (int b = 2; b < 100; ++b) {
            std::string num = power(a, b);
            int sum = digit_sum(num);
            if (sum > max_sum) max_sum = sum;
        }
    }
    return max_sum;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << max_digital_sum() << std::endl;
}
#endif // UNITTEST_MODE