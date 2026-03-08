/*
 * Solution for Euler problem 015
 *
 * Lattice paths
 *
 * Starting in the top left corner of a 2×2 grid, and only being able to move to
 * the right and down, there are exactly 6 routes to the bottom right corner.
 *
 * How many such routes are there through a 20×20 grid?
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.math.BigInteger;

public class Solution015 implements Solution {
  public String solve() {
    // C(40, 20) = 40! / (20! * 20!)
    return binomialCoefficient(40, 20).toString();
  }

  private BigInteger binomialCoefficient(int n, int k) {
    BigInteger result = BigInteger.ONE;
    for (int i = 1; i <= k; i++) {
      result = result.multiply(BigInteger.valueOf(n - i + 1));
      result = result.divide(BigInteger.valueOf(i));
    }
    return result;
  }
}