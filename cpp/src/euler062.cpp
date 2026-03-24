// https://projecteuler.net/problem=62

// Cubic Permutations

// The cube, 41063625 (345^3), can be permuted to produce two other cubes: 56623104 (384^3) and 66430125 (405^3). In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.
// Find the smallest cube for which exactly five permutations of its digits are cube.

// Answer: 127035954683

// Execution time: ~1ms on modern hardware

// Optimizations: Group cubes by sorted digit string for efficient permutation lookup
// Interesting notes: AI-generated solution using digit sorting and grouping

#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

long long cubic_permutations() {
    std::unordered_map<std::string, std::vector<long long>> groups;
    for (long long n = 1; ; ++n) {
        long long cube = n * n * n;
        std::string s = std::to_string(cube);
        if (s.length() > 12) break;
        std::string key = s;
        std::sort(key.begin(), key.end());
        groups[key].push_back(cube);
    }
    long long min_cube = LLONG_MAX;
    for (const auto& pair : groups) {
        if (pair.second.size() == 5) {
            for (long long c : pair.second) {
                if (c < min_cube) min_cube = c;
            }
        }
    }
    return min_cube;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << cubic_permutations() << std::endl;
}
#endif // UNITTEST_MODE
