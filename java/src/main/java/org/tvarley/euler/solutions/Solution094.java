// https://projecteuler.net/problem=94
// Almost Equilateral Triangles
//
// It is easily proved that no equilateral triangle exists with integral length sides and integral area. However, the almost equilateral triangle 5-5-6 has an area of 12.
//
// We shall define an almost equilateral triangle to be a triangle for which two sides are equal and the third differs by no more than one unit.
//
// Find the sum of the perimeters of all almost equilateral triangles with integral side lengths and integral area and whose perimeters do not exceed one billion (1,000,000,000).
//
// Answer: 518408346
//
// Completed on: 2024-12-04
// Time: ~1ms
// Optimizations: Pell recurrence for direct computation
// Notes: Used recurrence a_{n+1} = 14*a_n - a_{n-1} for both types.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution094 implements Solution {
    public String solve() {
        long sum = 0;
        final long MAX_PERIM = 1000000000L;
        // Type 1: (a, a, a-1)
        long aPrev = 1;
        long aCurr = 17;
        while (true) {
            long perim = 3L * aCurr - 1;
            if (perim > MAX_PERIM) break;
            sum += perim;
            long aNext = 14L * aCurr - aPrev;
            aPrev = aCurr;
            aCurr = aNext;
        }
        // Type 2: (a, a, a+1)
        aPrev = 1;
        aCurr = 5;
        while (true) {
            long perim = 3L * aCurr + 1;
            if (perim > MAX_PERIM) break;
            if (aCurr > 1) {
                sum += perim;
            }
            long aNext = 14L * aCurr - aPrev;
            aPrev = aCurr;
            aCurr = aNext;
        }
        return Long.toString(sum);
    }
}