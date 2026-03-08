/*
 * Solution for Euler problem 020
 *
 * Factorial digit sum
 *
 * n! means n × (n − 1) × ... × 3 × 2 × 1
 *
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 *
 * Find the sum of the digits in the number 100!
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.math.BigInteger;

public class Solution020 implements Solution {
  public String solve() {
    BigInteger factorial = BigInteger.ONE;
    for (int i = 1; i <= 100; i++) {
      factorial = factorial.multiply(BigInteger.valueOf(i));
    }
    String factorialStr = factorial.toString();
    int sum = 0;
    for (char c : factorialStr.toCharArray()) {
      sum += c - '0';
    }
    return Integer.toString(sum);
  }
}