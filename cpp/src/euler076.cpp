// https://projecteuler.net/problem=76
// Counting Summations
//
// It is possible to write five as a sum in exactly six different ways:
//
// 4 + 1
// 3 + 2
// 3 + 1 + 1
// 2 + 2 + 1
// 2 + 1 + 1 + 1
// 1 + 1 + 1 + 1 + 1
//
// How many different ways can one hundred be written as a sum of at least two positive integers?
//
// Answer: 190569291

#include <iostream>
#include <vector>

int counting_summations()
{
    const int N = 100;
    std::vector<long long> p(N + 1, 0);
    p[0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            p[j] += p[j - i];
        }
    }
    return p[N] - 1;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    std::cout << "Answer: " << counting_summations() << std::endl;
}
#endif