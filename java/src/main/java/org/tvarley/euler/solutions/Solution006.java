/*
 * Solution for Euler problem 006
 *
 * Sum square difference
 *
 * The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution006 implements Solution {
  public String solve() {
    int n = 100;
    long sumOfSquares = n * (n + 1) * (2 * n + 1) / 6;
    long squareOfSum = n * n * (n + 1) * (n + 1) / 4;
    long difference = squareOfSum - sumOfSquares;
    return Long.toString(difference);
  }
}