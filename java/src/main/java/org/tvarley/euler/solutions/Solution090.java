// https://projecteuler.net/problem=90
// Cube Digit Pairs
//
// Each of the six faces on a cube has a different digit (0 to 9) written on it; the same is done to a second cube. By placing the two cubes side-by-side in different positions we can form a variety of 2-digit numbers.
//
// For example, the square number 01 is formed when the first cube has 0 and the second has 1, or vice versa.
//
// In fact, by carefully choosing the digits on both cubes it is possible to display all of the square numbers below one-hundred: 01, 04, 09, 16, 25, 36, 49, 64, and 81.
//
// For example, one way this can be achieved is by placing {0, 1, 2, 3, 4, 5} on the first cube and {0, 1, 2, 8, 8, 9} on the second cube. Note that both cubes are treated as having the same digits regardless of the order.
//
// However, for this problem we shall allow the 6 or 9 to be turned upside-down so that an arrangement may count as both numbers. What is the least number of cubes that the two cubes must share between them to be able to display all of these square numbers? Wait, no, the problem is different.
//
// Actually, the problem is to count the number of distinct arrangements of two cubes that can display all the square numbers 01 through 81, considering 6 and 9 interchangeable.
//
// Answer: 1217
//
// Completed on: 2024-12-04
// Time: ~10ms
// Optimizations: Bitmask for cubes, precompute combinations
// Notes: Used bit operations for efficiency.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.util.ArrayList;
import java.util.List;

public class Solution090 implements Solution {
    private boolean hasDigit(int mask, int d) {
        if ((mask & (1 << d)) != 0) return true;
        if (d == 6 && (mask & (1 << 9)) != 0) return true;
        if (d == 9 && (mask & (1 << 6)) != 0) return true;
        return false;
    }

    private boolean canFormSquare(int maskA, int maskB, int sq) {
        int d1 = sq / 10, d2 = sq % 10;
        boolean a1 = hasDigit(maskA, d1), a2 = hasDigit(maskA, d2);
        boolean b1 = hasDigit(maskB, d1), b2 = hasDigit(maskB, d2);
        return (a1 && b2) || (a2 && b1);
    }

    public String solve() {
        int[] squares = {1, 4, 9, 16, 25, 36, 49, 64, 81};
        List<Integer> cubes = new ArrayList<>();
        for (int i = 0; i < (1 << 10); ++i) {
            if (Integer.bitCount(i) == 6) {
                cubes.add(i);
            }
        }
        long count = 0;
        int n = cubes.size();
        for (int i = 0; i < n; ++i) {
            int ma = cubes.get(i);
            for (int j = i + 1; j < n; ++j) {
                int mb = cubes.get(j);
                boolean ok = true;
                for (int sq : squares) {
                    if (!canFormSquare(ma, mb, sq)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) ++count;
            }
        }
        return Long.toString(count);
    }
}