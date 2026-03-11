/*
 * Solution for Euler problem 038
 *
 * Pandigital Multiples
 *
 * Take the number 192 and multiply it by each of 1, 2, and 3:
 * 192 × 1 = 192
 * 192 × 2 = 384
 * 192 × 3 = 576
 * By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3).
 * The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
 * What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2,…,n) where n > 1?
 *
 * @author tvarley
 * @date 3/10/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution038 implements Solution {
  public String solve() {
    int max = 0;
    for (int i = 1; i < 10000; i++) {
      String concat = "";
      int n = 1;
      while (concat.length() < 9) {
        concat += Integer.toString(i * n);
        n++;
      }
      if (concat.length() == 9 && isPandigital(concat) && Integer.parseInt(concat) > max) max = Integer.parseInt(concat);
    }
    return Integer.toString(max);
  }

  private boolean isPandigital(String s) {
    if (s.length() != 9) return false;
    boolean[] used = new boolean[10];
    for (char c : s.toCharArray()) {
      int d = c - '0';
      if (d == 0 || used[d]) return false;
      used[d] = true;
    }
    return true;
  }
}