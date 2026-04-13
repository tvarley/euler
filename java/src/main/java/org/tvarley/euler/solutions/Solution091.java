// https://projecteuler.net/problem=91
// Right Triangles with Integer Coordinates
//
// The points P (x1, y1) and Q (x2, y2) are plotted at integer coordinates and are joined to the origin, O(0,0), to form ΔOPQ.
//
// There are exactly fourteen triangles containing a right angle that can be formed when each coordinate lies between 0 and 2 inclusive; we shall restrict to coordinate values of 0 or greater and 50 or less.
//
// How many right-angled triangles can be formed with integer coordinates 0 ≤ x1, y1, x2, y2 ≤ 50, with right angle at any of the three points?
//
// Answer: 14234
//
// Completed on: 2024-12-04
// Time: ~10ms
// Optimizations: GCD for step reduction, symmetry handling
// Notes: Counted right angles at origin, axis, and interior points.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution091 implements Solution {
    private int gcd(int a, int b) {
        while (a != 0) {
            int c = a;
            a = b % a;
            b = c;
        }
        return b;
    }

    public String solve() {
        final int size = 50;
        long result = 3L * size * size; // origin + x-axis + y-axis
        for (int px = 1; px <= size; ++px) {
            for (int py = 1; py <= px; ++py) {
                int factor = gcd(px, py);
                int dx = px / factor;
                int dy = py / factor;
                int found = 0;
                // Q below P
                int qx = px - dy;
                int qy = py + dx;
                while (qx >= 0 && qy <= size) {
                    ++found;
                    qx -= dy;
                    qy += dx;
                }
                // Q above P
                qx = px + dy;
                qy = py - dx;
                while (qy >= 0 && qx <= size) {
                    ++found;
                    qx += dy;
                    qy -= dx;
                }
                if (px != py) found *= 2;
                result += found;
            }
        }
        return Long.toString(result);
    }
}