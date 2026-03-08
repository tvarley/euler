/*
 * Solution for Euler problem 005
 *
 * Smallest multiple
 *
 * 2520 is the smallest number that can be divided by each of the numbers from
 * 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the
 * numbers from 1 to 20?
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution005 implements Solution {
  public String solve() {
    int lcm = 1;
    for (int i = 2; i <= 20; i++) {
      lcm = lcm(lcm, i);
    }
    return Integer.toString(lcm);
  }

  private int lcm(int a, int b) {
    return a * (b / gcd(a, b));
  }

  private int gcd(int a, int b) {
    while (b != 0) {
      int t = b;
      b = a % b;
      a = t;
    }
    return a;
  }
}