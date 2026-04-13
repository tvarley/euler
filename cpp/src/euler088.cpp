// Problem 88: Product-sum numbers
// https://projecteuler.net/problem=88
// Find the sum of all the minimal product-sum numbers for 2 ≤ k ≤ 12000.

#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

const int MAX_K = 12000;
const long long MAX_N = 200000LL;

std::vector<long long> min_ps(MAX_K + 1, LLONG_MAX);

void find_min_ps(long long prod, long long sumf, int numf, int minf) {
    if (numf >= 2) {
        int k = static_cast<int>(prod - sumf + numf);
        if (k >= 2 && k <= MAX_K && prod < min_ps[k]) {
            min_ps[k] = prod;
        }
    }
    if (prod > MAX_N / 2) return;
    for (int i = minf; ; ++i) {
        long long new_prod = prod * static_cast<long long>(i);
        if (new_prod > MAX_N || new_prod / i != prod) break; // overflow or too big
        long long new_sum = sumf + i;
        int new_num = numf + 1;
        int est_k = static_cast<int>(new_prod - new_sum + new_num);
        if (est_k > MAX_K) break;
        find_min_ps(new_prod, new_sum, new_num, i);
    }
}

long long product_sum_numbers() {
    std::fill(min_ps.begin(), min_ps.end(), LLONG_MAX);
    find_min_ps(1LL, 0LL, 0, 2);
    std::set<long long> uniques;
    for (int k = 2; k <= MAX_K; ++k) {
        if (min_ps[k] != LLONG_MAX) {
            uniques.insert(min_ps[k]);
        }
    }
    long long total = 0;
    for (auto v : uniques) total += v;
    return total;
}

#ifndef UNITTEST_MODE
int main() {
    std::cout << product_sum_numbers() << std::endl;
    return 0;
}
#endif
