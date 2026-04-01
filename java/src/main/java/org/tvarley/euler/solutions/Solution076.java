/*
Counting Summations

It is possible to write five as a sum in exactly six different ways:

4 + 1
3 + 2
3 + 1 + 1
2 + 2 + 1
2 + 1 + 1 + 1
1 + 1 + 1 + 1 + 1

How many different ways can one hundred be written as a sum of at least two positive integers?

The final answer to the problem is 190569291.

Execution time measurements: Less than 1 ms on standard hardware.

Details on any optimizations made during development: Dynamic programming for partition function, using long array to avoid overflow.

Interesting notes or insights from the AI implementation process: AI-generated solution using DP to count integer partitions.
*/
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution076 implements Solution {
  public String solve() {
    final int N = 100;
    long[] p = new long[N + 1];
    p[0] = 1;
    for (int i = 1; i <= N; ++i) {
      for (int j = i; j <= N; ++j) {
        p[j] += p[j - i];
      }
    }
    return String.valueOf(p[N] - 1);
  }
}