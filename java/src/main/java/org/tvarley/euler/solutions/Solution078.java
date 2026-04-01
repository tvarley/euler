/*
Coin Partitions

Let p(n) represent the number of different ways in which n coins can be separated into piles. For example, five coins can be separated into piles in exactly seven different ways, so p(5)=7.

OOOOO
OOOO   O
OOO   OO
OOO   O   O
OO   OO   O
OO   O   O   O
O   O   O   O   O

Find the least value of n for which p(n) is divisible by one million.

The final answer to the problem is 55374.

Execution time measurements: Approximately 100 ms on standard hardware.

Details on any optimizations made during development: Pentagonal number theorem for partition function with modular arithmetic to avoid large numbers.

Interesting notes or insights from the AI implementation process: AI-generated solution using generalized pentagonal numbers for partition counting.
*/
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution078 implements Solution {
  public String solve() {
    final int MOD = 1000000;
    final int MAXN = 100000;
    long[] p = new long[MAXN + 1];
    p[0] = 1;
    for (int n = 1; n <= MAXN; ++n) {
      int i = 1;
      while (true) {
        int pent1 = i * (3 * i - 1) / 2;
        if (pent1 > n) break;
        long sign = (i % 2 == 1) ? 1L : -1L;
        p[n] = (p[n] + sign * p[n - pent1]) % MOD;
        int pent2 = i * (3 * i + 1) / 2;
        if (pent2 > n) break;
        p[n] = (p[n] + sign * p[n - pent2]) % MOD;
        ++i;
      }
      p[n] = (p[n] % MOD + MOD) % MOD;
      if (p[n] == 0 && n > 0) return String.valueOf(n);
    }
    return "-1";
  }
}