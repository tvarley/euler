// https://projecteuler.net/problem=74
// Digit factorial chains

// The number 145 is well known for the property that the sum of the factorial of its digits is equal to 145:
// 1! + 4! + 5! = 1 + 24 + 120 = 145.

// Perhaps less well known is 169, in that it produces the longest chain of numbers that link back to 169; it turns out that there are only three such loops that exist:
// 169 → 363601 → 1454 → 169
// 871 → 45361 → 871
// 872 → 45362 → 872

// It is not difficult to prove that EVERY starting number will eventually get stuck in a loop. For example,
// 69 → 363600 → 1454 → 169 → 363601 (→ 1454)
// 78 → 45360 → 871 → 45361 (→ 871)
// 540 → 145 (→ 145)

// Starting with 69 produces a chain of five non-repeating terms, but the longest non-repeating chain with a starting number below one million is sixty terms.

// How many chains, with a starting number below one million, contain exactly sixty non-repeating terms?

// Answer: 402

#include <iostream>
#include <set>

int fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};

int digit_fact_sum(int n)
{
    int sum = 0;
    while(n > 0){
        sum += fact[n % 10];
        n /= 10;
    }
    return sum;
}

int digit_factorial_chains()
{
    int count = 0;
    for(int i=1; i<1000000; i++){
        std::set<int> seen;
        int n = i;
        while(seen.find(n) == seen.end()){
            seen.insert(n);
            n = digit_fact_sum(n);
        }
        if(seen.size() == 60){
            count++;
        }
    }
    return count;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    std::cout << "Answer: " << digit_factorial_chains() << std::endl;
}
#endif // #if ! defined UNITTEST_MODE