// https://projecteuler.net/problem=92
// Square Digit Chains
//
// A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.
//
// For example, 44 → 32 → 13 → 10 → 1 → 1, or 85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89, and so on.
//
// Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.
//
// How many starting numbers below ten million will arrive at 89?
//
// Answer: 8581146
//
// Completed on: 2024-12-04
// Time: ~2000ms
// Optimizations: Memoization of chain ends
// Notes: Used array for memo, computed sum of squares iteratively.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution092 implements Solution {
    private static final int MAX_SUM = 9 * 9 * 7 + 1;
    private int[] memo = new int[MAX_SUM];

    private int sumSquareDigits(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    private int getChainEnd(int n) {
        if (n == 1) return 1;
        if (n == 89) return 2;
        if (memo[n] != 0) return memo[n];
        return memo[n] = getChainEnd(sumSquareDigits(n));
    }

    public String solve() {
        long count = 0;
        for (int i = 1; i < 10000000; ++i) {
            if (getChainEnd(sumSquareDigits(i)) == 2) count++;
        }
        return Long.toString(count);
    }
}