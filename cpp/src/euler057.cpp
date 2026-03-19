// https://projecteuler.net/problem=57

// Square Root Convergents

// It is possible to show that the square root of two can be expressed as an infinite continued fraction.

// \sqrt 2 =1+ \frac 1 {2+ \frac 1 {2 +\frac 1 {2+ \dots}}}

// By expanding this for the first four iterations, we get:
// 1 + \frac 1 2 = \frac 32 = 1.5
// 1 + \frac 1 {2 + \frac 1 2} = \frac 7 5 = 1.4
// 1 + \frac 1 {2 + \frac 1 {2+\frac 1 2}} = \frac {17}{12} = 1.41666 \dots
// 1 + \frac 1 {2 + \frac 1 {2+\frac 1 {2+\frac 1 2}}} = \frac {41}{29} = 1.41379 \dots

// The next three expansions are \frac {99}{70}, \frac {239}{169}, and \frac {577}{408},
// but the eighth expansion, \frac {1393}{985}, is the first example where the number of digits
// in the numerator exceeds the number of digits in the denominator.

// In the first one-thousand expansions, how many fractions contain a numerator
// with more digits than the denominator?

// Answer: 153

#include <iostream>
#include <string>
#include <algorithm>

// Add two big integers represented as strings
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

// Multiply a big integer by 2 (just add to itself)
static std::string multiply_by_2(const std::string& s) {
    return add_strings(s, s);
}

// Count expansions where numerator has more digits than denominator
int square_root_convergents() {
    std::string a = "1";  // numerator
    std::string b = "1";  // denominator
    int count = 0;
    for (int i = 0; i < 1000; ++i) {
        // a(n+1) = 2*b(n) + a(n)
        // b(n+1) = b(n) + a(n)
        std::string two_b = multiply_by_2(b);
        std::string next_a = add_strings(two_b, a);
        std::string next_b = add_strings(b, a);
        a = next_a;
        b = next_b;
        if (a.size() > b.size()) {
            ++count;
        }
    }
    return count;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << square_root_convergents() << std::endl;
}
#endif // UNITTEST_MODE