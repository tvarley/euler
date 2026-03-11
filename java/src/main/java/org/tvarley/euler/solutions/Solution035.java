/*
 * Solution for Euler problem 035
 *
 * Circular Primes
 *
 * The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
 * How many circular primes are there below one million?
 *
 * @author tvarley
 * @date 3/10/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import org.tvarley.euler.util.Prime;

public class Solution035 implements Solution {
  public String solve() {
    int count = 0;
    for (int i = 2; i < 1000000; i++) {
      if (Prime.isPrime(i) && isCircular(i)) count++;
    }
    return Integer.toString(count);
  }

  private boolean isCircular(int n) {
    String s = Integer.toString(n);
    for (int i = 0; i < s.length(); i++) {
      String rot = s.substring(i) + s.substring(0, i);
      if (!Prime.isPrime(Integer.parseInt(rot))) return false;
    }
    return true;
  }
}