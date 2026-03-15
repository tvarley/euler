// https://projecteuler.net/problem=29

// Consider all integer combinations of a^b for 2 ≤ a ≤ 5 and 2 ≤ b ≤ 5:
//
// 2^2=4, 2^3=8, 2^4=16, 2^5=32
// 3^2=9, 3^3=27, 3^4=81, 3^5=243
// 4^2=16, 4^3=64, 4^4=256, 4^5=1024
// 5^2=25, 5^3=125, 5^4=625, 5^5=3125
//
// If they are then placed in numerical order, with any repeats removed, we get the following sequence of 15 distinct terms:
//
// 4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125
//
// How many distinct terms are there for 2 ≤ a ≤ 100 and 2 ≤ b ≤ 100?
//
// Answer: 9183

// Authored by: Tim Varley 💘

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

std::string multiply(const std::string& a, int b) {
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

std::string power(int a, int b) {
    std::string result = "1";
    for (int i = 0; i < b; ++i) {
        result = multiply(result, a);
    }
    return result;
}

int distinct_powers(int max_a, int max_b) {
    std::set<std::string> terms;
    for (int a = 2; a <= max_a; ++a) {
        for (int b = 2; b <= max_b; ++b) {
            terms.insert(power(a, b));
        }
    }
    return terms.size();
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << distinct_powers(100, 100) << std::endl;
}
#endif // UNITTEST_MODE