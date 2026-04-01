// https://projecteuler.net/problem=85
// Counting Rectangles
//
// By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains eighteen rectangles:
//
// Although there exists no rectangular grid that contains exactly two million rectangles, find the area of the grid with the nearest solution.
//
// Answer: 2772
//
// Completed on: 2024-12-04
// Time: ~200ms
// Optimizations: Brute force over m,n up to 2000
// Notes: Number of rectangles formula: (m(m+1)/2) * (n(n+1)/2)

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution085 implements Solution {
    public String solve() {
        long target = 2000000;
        long minDiff = Long.MAX_VALUE;
        int bestArea = 0;
        for (int m = 1; m <= 2000; ++m) {
            for (int n = 1; n <= 2000; ++n) {
                long rect = (long) m * (m + 1) / 2 * n * (n + 1) / 2;
                long diff = Math.abs(rect - target);
                if (diff < minDiff) {
                    minDiff = diff;
                    bestArea = m * n;
                }
            }
        }
        return Integer.toString(bestArea);
    }
}