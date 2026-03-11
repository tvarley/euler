/*
 * Solution for Euler problem 040
 *
 * Champernowne's Constant
 *
 * An irrational decimal fraction is created by concatenating the positive integers:
 * 0.123456789101112131415161718192021…
 * It can be seen that the 12th digit of the fractional part is 1.
 * If d_n represents the nth digit of the fractional part, find the value of the following expression.
 * d_1 × d_10 × d_100 × d_1000 × d_10000 × d_100000 × d_1000000
 *
 * @author tvarley
 * @date 3/10/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution040 implements Solution {
  public String solve() {
    StringBuilder sb = new StringBuilder();
    for (int i = 1; ; i++) {
      sb.append(i);
      if (sb.length() >= 1000000) break;
    }
    String s = sb.toString();
    int prod = 1;
    prod *= s.charAt(0) - '0';
    prod *= s.charAt(9) - '0';
    prod *= s.charAt(99) - '0';
    prod *= s.charAt(999) - '0';
    prod *= s.charAt(9999) - '0';
    prod *= s.charAt(99999) - '0';
    prod *= s.charAt(999999) - '0';
    return Integer.toString(prod);
  }
}