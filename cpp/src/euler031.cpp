// https://projecteuler.net/problem=31

// In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:
// 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
// It is possible to make £2 in the following way:
// 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
// How many different ways can £2 be made using any number of coins?

// Answer: 73682

// Authored by: Tim Varley 💘
// Assisted-by: Grok Code Fast via Crush 💘 &lt;crush@charm.land&gt;

#include <iostream>
#include <vector>

int coin_sums() {
    const int amount = 200;
    std::vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    std::vector<long long> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << coin_sums() << std::endl;
}
#endif // UNITTEST_MODE