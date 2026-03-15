// https://projecteuler.net/problem=35

// The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

// There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

// How many circular primes are there below one million?

// Answer: 55

// Authored by: Tim Varley 💘

#include <iostream>
#include <vector>
#include <string>

int circular_primes() {
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
    int count = 0;
    for(int n=2; n<MAX; n++) {
        if(!is_prime[n]) continue;
        std::string s = std::to_string(n);
        bool all_prime = true;
        for(size_t rot=1; rot<s.size(); rot++) {
            std::string r = s.substr(rot) + s.substr(0,rot);
            int rn = std::stoi(r);
            if(!is_prime[rn]) { all_prime=false; break; }
        }
        if(all_prime) count++;
    }
    return count;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << circular_primes() << std::endl;
}
#endif // UNITTEST_MODE