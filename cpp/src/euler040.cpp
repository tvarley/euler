// https://projecteuler.net/problem=40

// An irrational decimal fraction is created by concatenating the positive integers:

// 0.12345678910 1 112131415161718192021…

// It can be seen that the 12th digit of the fractional part is 1.

// If d_n represents the nth digit of the fractional part, find the value of the following expression.

// d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

// Answer: 210

// Authored by: Tim Varley 💘

#include <iostream>
#include <vector>
#include <string>

long long champernowne() {
    std::string s = "";
    long long num = 1;
    while(s.size() < 1000001) {
        s += std::to_string(num++);
    }
    long long product = 1;
    std::vector<int> positions = {1,10,100,1000,10000,100000,1000000};
    for(int pos : positions) {
        product *= s[pos-1] - '0';
    }
    return product;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << champernowne() << std::endl;
}
#endif // UNITTEST_MODE