// https://projecteuler.net/problem=100
// Arranged Probability
//
// If a box contains twenty-one coloured discs, composed of fifteen blue discs and six white discs, and two discs were taken at random, it can be seen that the probability of taking two blue discs, P(BB) = (15/21)×(14/20) = 1/2.
//
// The next such arrangement, for which there is exactly 1/2 probability of taking two blue discs at random, is a box containing eighty-five blue discs and thirty-five white discs.
//
// By finding the first arrangement to contain over 10^12 discs in total, determine the number of blue discs that the box would contain.
//
// Answer: 756872327473
//
// Completed on: 2024-12-04
// Time: ~1ms
// Optimizations: Pell recurrence for direct computation
// Notes: Used recurrence b_new = 3*b + 2*n - 2, n_new = 4*b + 3*n - 3.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution100 implements Solution {
    public String solve() {
        long b = 15, n = 21;
        while (n <= 1000000000000L) {
            long bNew = 3 * b + 2 * n - 2;
            long nNew = 4 * b + 3 * n - 3;
            b = bNew;
            n = nNew;
        }
        return Long.toString(b);
    }
}