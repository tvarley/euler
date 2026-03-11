// https://projecteuler.net/problem=36

// The decimal number, 585 = 1001001001_2 (binary), is palindromic in both bases.

// Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

// (Please note that the palindromic number, in either base, may not include leading zeros.)

// Answer: 872187

// Authored by: Tim Varley 💘
// Assisted-by: Grok Code Fast via Crush 💘 <crush@charm.land>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool is_palindrome(const std::string& s) {
    std::string rev = s;
    std::reverse(rev.begin(), rev.end());
    return s == rev;
}

long long double_base_palindromes() {
    long long sum = 0;
    for(int n=1; n<1000000; n++) {
        std::string dec = std::to_string(n);
        if(!is_palindrome(dec)) continue;
        std::string bin = "";
        int temp = n;
        while(temp > 0) {
            bin += (temp % 2) + '0';
            temp /= 2;
        }
        std::reverse(bin.begin(), bin.end());
        if(is_palindrome(bin)) sum += n;
    }
    return sum;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << double_base_palindromes() << std::endl;
}
#endif // UNITTEST_MODE