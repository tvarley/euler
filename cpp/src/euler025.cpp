// https://projecteuler.net/problem=25
// 1000-digit Fibonacci number
//
// The Fibonacci sequence is defined by the recurrence relation:
// 
// Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
// Hence the first 12 terms will be:
// 
// F1 = 1
// F2 = 1
// F3 = 2
// F4 = 3
// F5 = 5
// F6 = 8
// F7 = 13
// F8 = 21
// F9 = 34
// F10 = 55
// F11 = 89
// F12 = 144
// The 12th term, F12, is the first term to contain three digits.
// 
// What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

// Answer: 4782

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "simple_timer.h"

typedef std::vector<uint32_t> Zbigint;

Zbigint add(const Zbigint& a, const Zbigint& b) {
    Zbigint result;
    uint32_t carry = 0;
    size_t max_size = std::max(a.size(), b.size());
    result.reserve(max_size + 1);
    for (size_t i = 0; i < max_size || carry; ++i) {
        uint32_t sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        result.push_back(sum % 1000000000);  // base 1e9
        carry = sum / 1000000000;
    }
    return result;
}

size_t get_digit_count(const Zbigint& num) {
    if (num.empty()) return 1;
    size_t digits = (num.size() - 1) * 9;  // 9 digits per uint32_t except last
    uint32_t last = num.back();
    while (last > 0) {
        digits++;
        last /= 10;
    }
    return digits;
}

int z1000_digit_fibinacci_number() {
    Zbigint fib1 = {1};
    Zbigint fib2 = {1};
    int index = 2;
    while (get_digit_count(fib1) < 1000) {
        Zbigint next = add(fib1, fib2);
        fib2 = fib1;
        fib1 = next;
        index++;
    }
    return index;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
  std::cout << "Answer: " << z1000_digit_fibinacci_number() << std::endl;
}
#endif //#if ! defined UNITTEST_MODE
