/*
 * Solution for Euler problem 037
 *
 * Truncatable Primes
 *
 * The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7.
 * Similarly we can work from right to left: 3797, 379, 37, and 3.
 * Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 *
 * @author tvarley
 * @date 3/10/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import org.tvarley.euler.util.Prime;

public class Solution037 implements Solution {
  public String solve() {
    long sum = 0;
    int count = 0;
    int i = 11;
    while (count < 11) {
      if (Prime.isPrime(i) && isTruncatable(i)) {
        sum += i;
        count++;
      }
      i += 2;
    }
    return Long.toString(sum);
  }

  private boolean isTruncatable(int n) {
    String s = Integer.toString(n);
    for (int j = 1; j < s.length(); j++) {
      if (!Prime.isPrime(Integer.parseInt(s.substring(j)))) return false;
    }
    for (int j = s.length() - 1; j > 0; j--) {
      if (!Prime.isPrime(Integer.parseInt(s.substring(0, j)))) return false;
    }
    return true;
  }
}