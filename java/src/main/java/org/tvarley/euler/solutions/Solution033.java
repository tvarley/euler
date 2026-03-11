/*
 * Solution for Euler problem 033
 *
 * Digit Cancelling Fractions
 *
 * The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 * There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
 * If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
 *
 * @author tvarley
 * @date 3/10/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution033 implements Solution {
  public String solve() {
    long num = 1;
    long den = 1;
    for (int a = 10; a < 100; a++) {
      for (int b = a + 1; b < 100; b++) {
        if (isCurious(a, b)) {
          num *= a;
          den *= b;
        }
      }
    }
    long gcd = gcd(num, den);
    return Long.toString(den / gcd);
  }

  private boolean isCurious(int a, int b) {
    String as = Integer.toString(a);
    String bs = Integer.toString(b);
    if (as.charAt(1) == bs.charAt(0) && as.charAt(1) != '0') {
      int na = as.charAt(0) - '0';
      int nb = bs.charAt(1) - '0';
      if (nb != 0 && (double)a / b == (double)na / nb) {
        return true;
      }
    }
    return false;
  }

  private long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}