/*
 * Solution for Euler problem 046
 *
 * Goldbach's Other Conjecture
 *
 * It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
 * 9 = 7 + 2×1²
 * 15 = 7 + 2×2²
 * 21 = 3 + 2×3²
 * 25 = 7 + 2×3²
 * 27 = 19 + 2×2²
 * 33 = 31 + 2×1²
 * It turns out that the conjecture was false.
 * What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
 *
 * @author tvarley
 * @date 3/14/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import org.tvarley.euler.util.Prime;

public class Solution046 implements Solution {
  public String solve() {
    for (int n = 9; ; n += 2) {
      if (!Prime.isPrime(n)) {
        boolean found = false;
        for (int i = 1; 2 * i * i < n; i++) {
          int p = n - 2 * i * i;
          if (Prime.isPrime(p)) {
            found = true;
            break;
          }
        }
        if (!found) {
          return Integer.toString(n);
        }
      }
    }
  }
}