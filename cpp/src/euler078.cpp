// https://projecteuler.net/problem=78
// Coin Partitions
//
// Let p(n) represent the number of different ways in which n coins can be separated into piles. For example, five coins can be separated into piles in exactly seven different ways, so p(5)=7.
//
// OOOOO
// OOOO   O
// OOO   OO
// OOO   O   O
// OO   OO   O
// OO   O   O   O
// O   O   O   O   O
//
// Find the least value of n for which p(n) is divisible by one million.
//
// Answer: 55374

#include <iostream>
#include <vector>

int coin_partitions()
{
    const int MOD = 1000000;
    const int MAXN = 100000;
    std::vector<long long> p(MAXN + 1, 0);
    p[0] = 1;
    for (int n = 1; n <= MAXN; ++n) {
        int i = 1;
        while (true) {
            int pent1 = i * (3 * i - 1) / 2;
            if (pent1 > n) break;
            long long sign = (i % 2 == 1) ? 1LL : -1LL;
            p[n] = (p[n] + sign * p[n - pent1]) % MOD;
            int pent2 = i * (3 * i + 1) / 2;
            if (pent2 > n) break;
            p[n] = (p[n] + sign * p[n - pent2]) % MOD;
            ++i;
        }
        p[n] = (p[n] % MOD + MOD) % MOD;
        if (p[n] == 0 && n > 0) return n;
    }
    return -1;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    std::cout << "Answer: " << coin_partitions() << std::endl;
}
#endif