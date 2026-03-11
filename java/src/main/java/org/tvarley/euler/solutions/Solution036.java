/*
 * Solution for Euler problem 036
 *
 * Double-base Palindromes
 *
 * The decimal number, 585 = 1001001001_2 (binary), is palindromic in both bases.
 * Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
 * (Please note that the palindromic number, in either base, may not include leading zeros.)
 *
 * @author tvarley
 * @date 3/10/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution036 implements Solution {
  public String solve() {
    long sum = 0;
    for (int i = 1; i < 1000000; i++) {
      if (isPalindrome(Integer.toString(i)) && isPalindrome(Integer.toBinaryString(i))) sum += i;
    }
    return Long.toString(sum);
  }

  private boolean isPalindrome(String s) {
    return s.equals(new StringBuilder(s).reverse().toString());
  }
}