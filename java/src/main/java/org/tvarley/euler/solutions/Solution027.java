/*
 * Solution for Euler problem 027
 *
 * Quadratic primes
 *
 * Euler discovered the remarkable quadratic formula: n^2 + n + 41.
 * Considering quadratics of the form: n^2 + an + b, where |a| < 1000 and
 * |b| <= 1000, find the product of the coefficients a and b for the quadratic
 * expression that produces the maximum number of primes for consecutive values
 * of n, starting with n = 0.
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution027 implements Solution {
  public String solve() {
    int maxCount = 0;
    int result = 0;

    for (int a = -999; a < 1000; a++) {
      for (int b = -1000; b <= 1000; b++) {
        int count = consecutivePrimes(a, b);
        if (count > maxCount) {
          maxCount = count;
          result = a * b;
        }
      }
    }

    return Integer.toString(result);
  }

  private int consecutivePrimes(int a, int b) {
    int n = 0;
    while (isPrime(n * n + a * n + b)) {
      n++;
    }
    return n;
  }

  private boolean isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; (long) i * i <= n; i += 2) {
      if (n % i == 0) return false;
    }
    return true;
  }
}
