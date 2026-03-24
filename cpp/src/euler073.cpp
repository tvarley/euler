// https://projecteuler.net/problem=73
// Counting fractions in a range

// Consider the fraction, n/d, where n and d are positive integers. If n < d and HCF(n,d)=1, it is called a reduced proper fraction.

// If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:
// 1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

// It can be seen that there are 3 fractions between 1/3 and 1/2.

// How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d ≤ 12,000?

// Answer: 7295372

#include <iostream>
#include <numeric>

int counting_fractions_range()
{
    int count = 0;
    for(int d=1; d<=12000; d++){
        int n_min = d / 3 + 1;
        int n_max = (d - 1) / 2;
        for(int n=n_min; n<=n_max; n++){
            if(std::gcd(n, d) == 1){
                count++;
            }
        }
    }
    return count;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    std::cout << "Answer: " << counting_fractions_range() << std::endl;
}
#endif // #if ! defined UNITTEST_MODE