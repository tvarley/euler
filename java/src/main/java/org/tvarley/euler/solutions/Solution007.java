/*
 * Solution for Euler problem 007
 *
 * 10001st prime
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import org.tvarley.euler.util.Prime;

public class Solution007 implements Solution {
  public String solve() {
    int count = 0;
    int candidate = 2;
    while (count < 10001) {
      if (Prime.isPrime(candidate)) {
        count++;
      }
      candidate++;
    }
    return Integer.toString(candidate - 1);
  }
}