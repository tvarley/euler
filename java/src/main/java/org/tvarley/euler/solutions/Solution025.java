/*
 * Solution for Euler problem 025
 *
 * 1000-digit Fibonacci number
 *
 * The Fibonacci sequence is defined by the recurrence relation:
 * Fn = Fn-1 + Fn-2, where F1 = 1, F2 = 1.
 *
 * The 12th term, F12, is the first term to contain three digits.
 *
 * What is the index of the first term in the Fibonacci sequence to contain
 * 1000 digits?
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.math.BigInteger;

public class Solution025 implements Solution {
  public String solve() {
    BigInteger a = BigInteger.ONE;
    BigInteger b = BigInteger.ONE;
    int index = 2;

    while (b.toString().length() < 1000) {
      BigInteger next = a.add(b);
      a = b;
      b = next;
      index++;
    }

    return Integer.toString(index);
  }
}
