/*
 * Solution for Euler problem 034
 *
 * Digit Factorials
 *
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 * Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 * Note: As 1! = 1 and 2! = 2 are not sums they are not included.
 *
 * @author tvarley
 * @date 3/10/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution034 implements Solution {
  public String solve() {
    long[] fact = new long[10];
    fact[0] = 1;
    for (int i = 1; i < 10; i++) fact[i] = fact[i-1] * i;
    long sum = 0;
    for (int i = 10; i < 10000000; i++) {
      if (isSumFact(i, fact)) sum += i;
    }
    return Long.toString(sum);
  }

  private boolean isSumFact(int n, long[] fact) {
    int s = 0;
    int temp = n;
    while (temp > 0) {
      s += fact[temp % 10];
      temp /= 10;
    }
    return s == n;
  }
}