/*
 * Solution for Euler problem 016
 *
 * Power digit sum
 *
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.math.BigInteger;

public class Solution016 implements Solution {
  public String solve() {
    BigInteger power = BigInteger.valueOf(2).pow(1000);
    String powerStr = power.toString();
    int sum = 0;
    for (char c : powerStr.toCharArray()) {
      sum += c - '0';
    }
    return Integer.toString(sum);
  }
}