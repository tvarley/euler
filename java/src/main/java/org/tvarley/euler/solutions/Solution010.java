/*
 * Solution for Euler problem 010
 *
 * Summation of primes
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution010 implements Solution {
  public String solve() {
    int limit = 2000000;
    boolean[] isComposite = new boolean[limit + 1];
    long sum = 0;

    for (int i = 2; i <= limit; i++) {
      if (!isComposite[i]) {
        sum += i;
        for (int j = i * 2; j <= limit; j += i) {
          isComposite[j] = true;
        }
      }
    }

    return Long.toString(sum);
  }
}