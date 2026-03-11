/*
 * Solution for Euler problem 039
 *
 * Integer Right Triangles
 *
 * If p is the perimeter of a right angle triangle with integral length sides, {a, b, c}, there are exactly three solutions for p = 120.
 * {20,48,52}, {24,45,51}, {30,40,50}
 * For which value of p ≤ 1000, is the number of solutions maximised?
 *
 * @author tvarley
 * @date 3/10/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution039 implements Solution {
  public String solve() {
    int max = 0;
    int maxP = 0;
    for (int p = 1; p <= 1000; p++) {
      int count = 0;
      for (int a = 1; a < p; a++) {
        for (int b = a; b < p - a; b++) {
          int c = p - a - b;
          if (a * a + b * b == c * c) count++;
        }
      }
      if (count > max) {
        max = count;
        maxP = p;
      }
    }
    return Integer.toString(maxP);
  }
}