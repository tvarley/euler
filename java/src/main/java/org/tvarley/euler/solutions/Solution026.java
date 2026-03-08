/*
 * Solution for Euler problem 026
 *
 * Reciprocal cycles
 *
 * A unit fraction contains 1 in the numerator. Find the value of d < 1000
 * for which 1/d contains the longest recurring cycle in its decimal fraction
 * part.
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution026 implements Solution {
  public String solve() {
    int maxCycle = 0;
    int result = 0;

    for (int d = 2; d < 1000; d++) {
      int len = cycleLength(d);
      if (len > maxCycle) {
        maxCycle = len;
        result = d;
      }
    }

    return Integer.toString(result);
  }

  private int cycleLength(int d) {
    int[] remainders = new int[d];
    int remainder = 1;
    int position = 0;

    while (remainder != 0) {
      if (remainders[remainder] != 0) {
        return position - remainders[remainder];
      }
      remainders[remainder] = position;
      remainder = (remainder * 10) % d;
      position++;
    }

    return 0;
  }
}
