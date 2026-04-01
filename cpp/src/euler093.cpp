// Problem 93: Arithmetic expressions
// https://projecteuler.net/problem=93
// Find the set of four distinct digits, a < b < c < d, for which the longest set of consecutive positive integers, 1 to n, can be found.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

std::set<double> evaluate_rec(const std::vector<double>& nums) {
    int n = nums.size();
    std::set<double> results;
    if (n == 1) {
        results.insert(nums[0]);
        return results;
    }
    // try all ways to split
    for (int i = 1; i < n; ++i) {
        auto left = std::vector<double>(nums.begin(), nums.begin() + i);
        auto right = std::vector<double>(nums.begin() + i, nums.end());
        auto left_vals = evaluate_rec(left);
        auto right_vals = evaluate_rec(right);
        for (double lv : left_vals) {
            for (double rv : right_vals) {
                results.insert(lv + rv);
                results.insert(lv - rv);
                results.insert(lv * rv);
                if (rv != 0) results.insert(lv / rv);
            }
        }
    }
    return results;
}

std::set<int> evaluate(const std::vector<double>& nums) {
    auto doubles = evaluate_rec(nums);
    std::set<int> ints;
    for (double d : doubles) {
        if (d > 0 && d == (int)d) ints.insert((int)d);
    }
    return ints;
}

long long arithmetic_expressions() {
    std::vector<int> digits = {1,2,3,4,5,6,7,8,9};
    int max_n = 0;
    std::string best_set;
    for (int a = 0; a < 9; ++a) {
        for (int b = a + 1; b < 9; ++b) {
            for (int c = b + 1; c < 9; ++c) {
                for (int d = c + 1; d < 9; ++d) {
                    std::vector<int> set = {digits[a], digits[b], digits[c], digits[d]};
                    std::set<int> values;
                    // generate all permutations of set
                    do {
                        std::vector<double> nums(set.begin(), set.end());
                        auto res = evaluate(nums);
                        values.insert(res.begin(), res.end());
                    } while (std::next_permutation(set.begin(), set.end()));
                    // find longest consecutive from 1
                    int n = 0;
                    while (values.count(n + 1)) n++;
                    if (n > max_n) {
                        max_n = n;
                        best_set = std::to_string(set[0]) + std::to_string(set[1]) + std::to_string(set[2]) + std::to_string(set[3]);
                    }
                }
            }
        }
    }
    return std::stoi(best_set);
}

#ifndef UNITTEST_MODE
int main() {
    std::cout << arithmetic_expressions() << std::endl;
    return 0;
}
#endif