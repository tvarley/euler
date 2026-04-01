// https://projecteuler.net/problem=88
// Product-sum Numbers
//
// A natural number, N, that can be written as the sum and product of a given set of at least two natural numbers, {a1, a2, ..., ak} is called a product-sum number: N = a1 + a2 + ... + ak = a1 × a2 × ... × ak.
//
// For a given set of size, k, we shall call the smallest N with this property a minimal product-sum number. The minimal product-sum numbers for sets of size, k = 2, 3, 4, 6 are as follows.
//
// If lists the products of these together in a single set you get 25. The sum of all the minimal product-sum numbers for 2 ≤ k ≤ 12000 is 7587457.
//
// Answer: 7587457
//
// Completed on: 2024-12-04
// Time: ~50ms
// Optimizations: Recursive search with pruning
// Notes: Used long for calculations, HashSet for unique values.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.util.HashSet;
import java.util.Set;

public class Solution088 implements Solution {
    private static final int MAX_K = 12000;
    private static final long MAX_N = 200000L;
    private long[] minPs = new long[MAX_K + 1];

    public String solve() {
        for (int i = 0; i <= MAX_K; ++i) {
            minPs[i] = Long.MAX_VALUE;
        }
        findMinPs(1L, 0L, 0, 2);
        Set<Long> uniques = new HashSet<>();
        for (int k = 2; k <= MAX_K; ++k) {
            if (minPs[k] != Long.MAX_VALUE) {
                uniques.add(minPs[k]);
            }
        }
        long total = 0;
        for (long v : uniques) total += v;
        return Long.toString(total);
    }

    private void findMinPs(long prod, long sumf, int numf, int minf) {
        if (numf >= 2) {
            int k = (int) (prod - sumf + numf);
            if (k >= 2 && k <= MAX_K && prod < minPs[k]) {
                minPs[k] = prod;
            }
        }
        if (prod > MAX_N / 2) return;
        for (int i = minf; ; ++i) {
            long newProd = prod * i;
            if (newProd > MAX_N || newProd / i != prod) break;
            long newSum = sumf + i;
            int newNum = numf + 1;
            int estK = (int) (newProd - newSum + newNum);
            if (estK > MAX_K) break;
            findMinPs(newProd, newSum, newNum, i);
        }
    }
}