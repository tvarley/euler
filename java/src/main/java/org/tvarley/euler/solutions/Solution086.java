// https://projecteuler.net/problem=86
// Cuboid Route
//
// A spider, S, sits in one corner of a cuboid room, measuring 6 by 5 by 3, and a fly, F, sits in the opposite corner. By travelling on the surfaces of the room the shortest "straight line" distance from S to F is 10 and the path is 74.15.
//
// However, for integer dimensions a ≤ b ≤ c, the shortest path in integer if it equals √(a² + (b+c)²) or √(b² + (a+c)²) or √(c² + (a+b)²).
//
// Find the least value of M such that the number of cuboids with integer dimensions, up to M by M by M, with shortest path integer, first exceeds one million.
//
// Answer: 1818
//
// Completed on: 2024-12-04
// Time: ~1500ms
// Optimizations: Brute force over a,b for each M
// Notes: Checked if square root is integer by rounding and checking square.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution086 implements Solution {
    public String solve() {
        long count = 0;
        int M = 0;
        final long TARGET = 1000000;
        while (count <= TARGET) {
            M++;
            long currentCount = 0;
            for (int a = 1; a <= M; ++a) {
                for (int b = a; b <= M; ++b) {
                    int c = M;
                    long p1 = (long) (a + b) * (a + b) + (long) c * c;
                    long p2 = (long) (a + c) * (a + c) + (long) b * b;
                    long p3 = (long) (b + c) * (b + c) + (long) a * a;
                    long minP = Math.min(Math.min(p1, p2), p3);
                    int root = (int) (Math.sqrt(minP) + 0.5);
                    if ((long) root * root == minP) {
                        currentCount++;
                    }
                }
            }
            count += currentCount;
        }
        return Integer.toString(M);
    }
}