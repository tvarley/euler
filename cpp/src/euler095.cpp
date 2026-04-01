// Problem 95: Amicable chains
// https://projecteuler.net/problem=95
// Find the smallest member of the longest amicable chain with no element exceeding one million.
// 
// Solution approach:
// 1. Precompute sum of proper divisors for all numbers up to MAX using sieve-like method
// 2. For each starting number i (2 to MAX), traverse the chain: i -> sum_div[i] -> sum_div[sum_div[i]] -> ...
// 3. Use visited array to avoid processing numbers already seen in any chain
// 4. Use chain_set to detect cycles within current chain traversal
// 5. When a cycle is detected (current number already in chain), extract the cycle portion
// 6. Track the longest cycle length and smallest member in that cycle
// 7. Return the smallest member of the longest cycle found
//
// Key insight: The algorithm correctly identifies cycles by checking if the next number in the chain
// is already present in the current chain being built. This handles both amicable pairs (length 2)
// and longer chains. The visited array prevents redundant traversals.
//
// Time complexity: O(MAX) since each number is visited at most once.
// Space complexity: O(MAX) for the sum_div and visited arrays.

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

const int MAX = 1000000;

std::vector<int> sum_div(MAX + 1, 0);

void compute_sum_div() {
    for (int i = 1; i <= MAX; ++i) {
        for (int j = i * 2; j <= MAX; j += i) {
            sum_div[j] += i;
        }
    }
}

long long amicable_chains() {
    compute_sum_div();
    int max_length = 0;
    int min_member = MAX;
    std::vector<bool> visited(MAX + 1, false);

    for (int i = 2; i <= MAX; ++i) {
        if (visited[i] || sum_div[i] > MAX) continue;

        std::vector<int> chain;
        std::set<int> chain_set;
        int current = i;

        while (current <= MAX && sum_div[current] != current && chain_set.find(current) == chain_set.end()) {
            chain.push_back(current);
            chain_set.insert(current);
            current = sum_div[current];
        }

        // Check if we found a cycle (current is already in chain)
        if (chain_set.find(current) != chain_set.end() && chain.size() > 1) {
            // Find where the cycle starts
            int cycle_start = -1;
            for (int j = 0; j < (int)chain.size(); ++j) {
                if (chain[j] == current) {
                    cycle_start = j;
                    break;
                }
            }
            int cycle_length = chain.size() - cycle_start;
            
            if (cycle_length > max_length) {
                max_length = cycle_length;
                // Find smallest member in the cycle
                int smallest = MAX;
                for (size_t j = cycle_start; j < chain.size(); ++j) {
                    if (chain[j] < smallest) smallest = chain[j];
                    visited[chain[j]] = true;  // Mark cycle numbers as visited
                }
                min_member = smallest;
            }
        }
    }

    return min_member;
}

#ifndef UNITTEST_MODE
int main() {
    std::cout << amicable_chains() << std::endl;
    return 0;
}
#endif