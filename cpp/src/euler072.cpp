// https://projecteuler.net/problem=72
// Counting fractions

// Consider the fraction, n/d, where n and d are positive integers. If n < d and HCF(n,d)=1, it is called a reduced proper fraction.

// If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:
// 1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

// It can be seen that there are 21 elements in this set.

// How many elements would be contained in the set of reduced proper fractions for d ≤ 1,000,000?

// Answer: 303963552391

#include <iostream>
#include <vector>

long long counting_fractions()
{
    const int MAXN = 1000000;
    std::vector<long long> phi(MAXN+1);
    for(int i=0; i<=MAXN; i++) phi[i] = i;

    for(int i=2; i<=MAXN; i++){
        if(phi[i] == i){ // prime
            for(long long j=i; j<=MAXN; j+=i){
                phi[j] = phi[j] / i * (i-1);
            }
        }
    }

    long long sum = 0;
    for(int i=2; i<=MAXN; i++){
        sum += phi[i];
    }
    return sum;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    std::cout << "Answer: " << counting_fractions() << std::endl;
}
#endif // #if ! defined UNITTEST_MODE