// https://projecteuler.net/problem=70
// Totient permutation

// Euler's totient function, φ(n) [sometimes called the phi function], is used to determine the number of positive numbers less than or equal to n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
// The number 1 is considered to be relatively prime to every positive number, so φ(1)=1.

// Interestingly, φ(87109)=79180, and it can be seen that 87109 is a permutation of 79180.

// Find the value of n, 1 < n < 10^7, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.

// Answer: 8319823

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

int totient_permutation()
{
    const int MAXN = 10000000;
    std::vector<long long> phi(MAXN+1);
    for(int i=0; i<=MAXN; i++) phi[i] = i;

    for(int i=2; i<=MAXN; i++){
        if(phi[i] == i){ // prime
            for(long long j=i; j<=MAXN; j+=i){
                phi[j] = phi[j] / i * (i-1);
            }
        }
    }

    double min_ratio = std::numeric_limits<double>::max();
    int result = -1;

    for(int n=2; n<=MAXN; n++){
        std::string s1 = std::to_string(n);
        std::string s2 = std::to_string(phi[n]);
        if(s1.length() != s2.length()) continue;
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());
        if(s1 == s2){
            double ratio = (double)n / phi[n];
            if(ratio < min_ratio){
                min_ratio = ratio;
                result = n;
            }
        }
    }

    return result;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    std::cout << "Answer: " << totient_permutation() << std::endl;
}
#endif // #if ! defined UNITTEST_MODE