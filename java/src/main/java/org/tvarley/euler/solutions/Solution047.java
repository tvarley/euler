/*
 * Solution for Euler problem 047
 *
 * Distinct Primes Factors
 *
 * The first two consecutive numbers to have two distinct prime factors are:
 * 14 = 2 × 7
 * 15 = 3 × 5.
 * The first three consecutive numbers to have three distinct prime factors are:
 * 644 = 2² × 7 × 23
 * 645 = 3 × 5 × 43
 * 646 = 2 × 17 × 19.
 * Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
 *
 * @author tvarley
 * @date 3/14/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution047 implements Solution {
  public String solve() {
    for (int n = 2; ; n++) {
      if (distinctPrimeFactors(n) == 4 &&
          distinctPrimeFactors(n + 1) == 4 &&
          distinctPrimeFactors(n + 2) == 4 &&
          distinctPrimeFactors(n + 3) == 4) {
        return Integer.toString(n);
      }
    }
  }

  private int distinctPrimeFactors(int n) {
    int count = 0;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        count++;
        while (n % i == 0) n /= i;
      }
    }
    if (n > 1) count++;
    return count;
  }
}