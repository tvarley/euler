// https://projecteuler.net/problem=37

// The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7.

// Similarly we can work from right to left: 3797, 379, 37, and 3.

// Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

// NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

// Answer: 748317

// Authored by: Tim Varley 💘

#include <iostream>
#include <vector>
#include <string>

int truncatable_primes() {
    const int MAX = 1000000;
    std::vector<bool> is_prime(MAX+1, true);
    is_prime[0] = is_prime[1] = false;
    for(long long i=2; i*i<=MAX; i++) {
        if(is_prime[i]) {
            for(long long j=i*i; j<=MAX; j+=i) {
                is_prime[j] = false;
            }
        }
    }
    int sum = 0;
    int count = 0;
    for(int n=11; n<MAX && count<11; n++) {
        if(!is_prime[n]) continue;
        std::string s = std::to_string(n);
        bool left_ok = true;
        for(size_t len=1; len<s.size(); len++) {
            std::string left = s.substr(len);
            int lnum = std::stoi(left);
            if(!is_prime[lnum]) {left_ok=false; break;}
        }
        if(!left_ok) continue;
        bool right_ok = true;
        for(int len=s.size()-1; len>0; len--) {
            std::string right = s.substr(0,len);
            int rnum = std::stoi(right);
            if(!is_prime[rnum]) {right_ok=false; break;}
        }
        if(right_ok) {
            sum += n;
            count++;
        }
    }
    return sum;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << truncatable_primes() << std::endl;
}
#endif // UNITTEST_MODE