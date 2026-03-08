/*
 * Solution for Euler problem 030
 *
 * Digit fifth powers
 *
 * Surprisingly there are only three numbers that can be written as the sum of
 * fourth powers of their digits:
 * 1634 = 1^4 + 6^4 + 3^4 + 4^4
 * 8208 = 8^4 + 2^4 + 0^4 + 8^4
 * 9474 = 9^4 + 4^4 + 7^4 + 4^4
 *
 * Find the sum of all the numbers that can be written as the sum of fifth
 * powers of their digits.
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution030 implements Solution {
  public String solve() {
    int limit = 354294; // 6 * 9^5
    int sum = 0;

    for (int n = 2; n <= limit; n++) {
      int digitSum = 0;
      int temp = n;
      while (temp > 0) {
        int digit = temp % 10;
        digitSum += digit * digit * digit * digit * digit;
        temp /= 10;
      }
      if (digitSum == n) {
        sum += n;
      }
    }

    return Integer.toString(sum);
  }
}
