// https://projecteuler.net/problem=69
// Totient maximum

// Euler's totient function, φ(n) [sometimes called the phi function], is defined as the number of positive integers not exceeding n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than or equal to nine and relatively prime to nine, φ(9)=6.

// It can be seen that n = 6 produces a maximum n/φ(n) for n≤10.

// Find the value of n≤1,000,000 for which n/φ(n) is a maximum.

// Answer: 510510

#include <iostream>

int totient_maximum()
{
    // The maximum n/phi(n) occurs for n that is product of first k primes where the product <= 1e6
    // Primes: 2,3,5,7,11,13,17
    // 2*3*5*7*11*13*17 = 510510
    // Next prime 19: 510510*19 = 9699690 > 1e6
    long long product = 1;
    int primes[] = {2,3,5,7,11,13,17};
    for(int p : primes){
        if(product * p > 1000000) break;
        product *= p;
    }
    return product;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    std::cout << "Answer: " << totient_maximum() << std::endl;
}
#endif // #if ! defined UNITTEST_MODE