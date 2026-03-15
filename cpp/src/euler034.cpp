// https://projecteuler.net/problem=34

// 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

// Find the sum of all numbers which are equal to the sum of the factorial of their digits.

// Note: As 1! = 1 and 2! = 2 are not sums they are not included.

// Answer: 40730

// Authored by: Tim Varley 💘

#include <iostream>
#include <vector>
#include <string>

long long digit_factorials() {
    std::vector<long long> fact(10,1);
    for(int i=2; i<10; i++) fact[i] = fact[i-1] * i;
    long long sum = 0;
    for(long long i=10; i<10000000; i++) {
        std::string s = std::to_string(i);
        long long sf = 0;
        for(char c : s) sf += fact[c-'0'];
        if(sf == i) sum += i;
    }
    return sum;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << digit_factorials() << std::endl;
}
#endif // UNITTEST_MODE