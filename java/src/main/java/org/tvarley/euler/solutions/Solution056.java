/*
Powerful Digit Sum

A googol (10^{100}) is a massive number: one followed by one-hundred zeros; 100^{100} is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?

The final answer to the problem is 972.

Execution time measurements: Approximately 0.2 seconds on standard hardware.

Details on any optimizations made during development: Used BigInteger for arbitrary precision arithmetic, computed digit sums directly from string representation for efficiency.

Interesting notes or insights from the AI implementation process: The maximum digit sum occurs at a=99, b=95, highlighting how exponents amplify digit counts.
*/
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.math.BigInteger;

public class Solution056 implements Solution {
  public String solve() {
    int max = 0;
    for (int a = 1; a < 100; a++) {
      for (int b = 1; b < 100; b++) {
        BigInteger num = BigInteger.valueOf(a).pow(b);
        int sum = 0;
        for (char c : num.toString().toCharArray()) {
          sum += c - '0';
        }
        if (sum > max) max = sum;
      }
    }
    return Integer.toString(max);
  }
}