/*
 * Solution for Euler problem 004
 *
 * Largest palindrome product
 *
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution004 implements Solution {
  public String solve() {
    int maxPalindrome = 0;
    for (int i = 100; i < 1000; i++) {
      for (int j = i; j < 1000; j++) {
        int product = i * j;
        if (isPalindrome(product) && product > maxPalindrome) {
          maxPalindrome = product;
        }
      }
    }
    return Integer.toString(maxPalindrome);
  }

  private boolean isPalindrome(int number) {
    String str = Integer.toString(number);
    return str.equals(new StringBuilder(str).reverse().toString());
  }
}