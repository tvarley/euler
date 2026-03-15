/*
 * Solution for Euler problem 048
 *
 * Self Powers
 *
 * The series, 1¹ + 2² + 3³ + … + 10¹⁰ = 10405071317.
 * Find the last ten digits of the series, 1¹ + 2² + 3³ + … + 1000¹⁰⁰⁰.
 *
 * @author tvarley
 * @date 3/14/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.math.BigInteger;

public class Solution048 implements Solution {
  public String solve() {
    BigInteger sum = BigInteger.ZERO;
    for (int i = 1; i <= 1000; i++) {
      BigInteger pow = BigInteger.valueOf(i).pow(i);
      sum = sum.add(pow);
    }
    String s = sum.toString();
    return s.substring(s.length() - 10);
  }
}