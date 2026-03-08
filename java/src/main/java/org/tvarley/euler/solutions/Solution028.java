/*
 * Solution for Euler problem 028
 *
 * Number spiral diagonals
 *
 * Starting with the number 1 and moving to the right in a clockwise direction
 * a 5 by 5 spiral is formed. It can be verified that the sum of the numbers
 * on the diagonals is 101.
 *
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
 * formed in the same way?
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution028 implements Solution {
  public String solve() {
    long sum = 1;
    long num = 1;

    for (int step = 2; step <= 1001; step += 2) {
      for (int corner = 0; corner < 4; corner++) {
        num += step;
        sum += num;
      }
    }

    return Long.toString(sum);
  }
}
