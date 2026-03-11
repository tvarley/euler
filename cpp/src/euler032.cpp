// https://projecteuler.net/problem=32

// We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

// The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

// Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

// HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

// Answer: 45228

// Authored by: Tim Varley 💘
// Assisted-by: Grok Code Fast via Crush 💘 <crush@charm.land>

#include <iostream>
#include <string>
#include <algorithm>
#include <set>

long long pandigital_products() {
    std::string digits = "123456789";
    std::set<long long> products;
    std::sort(digits.begin(), digits.end());
    do {
        for(int i=1; i<=4; i++) {
            for(int j=i+1; j<=8; j++) {
                std::string sa = digits.substr(0,i);
                std::string sb = digits.substr(i,j-i);
                std::string sc = digits.substr(j);
                long long a = std::stoll(sa);
                long long b = std::stoll(sb);
                long long c = std::stoll(sc);
                if(a * b == c) {
                    products.insert(c);
                }
            }
        }
    } while(std::next_permutation(digits.begin(), digits.end()));
    long long sum = 0;
    for(auto p : products) sum += p;
    return sum;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << pandigital_products() << std::endl;
}
#endif // UNITTEST_MODE