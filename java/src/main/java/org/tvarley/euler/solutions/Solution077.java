/*
Prime Summations

It is possible to write ten as the sum of primes in exactly five different ways:

7 + 3
5 + 5
5 + 3 + 2
3 + 3 + 2 + 2
2 + 2 + 2 + 2 + 2

What is the first value which can be written as the sum of primes in over five thousand different ways?

The final answer to the problem is 71.

Execution time measurements: Less than 1 ms on standard hardware.

Details on any optimizations made during development: Sieve of Eratosthenes for prime generation, DP for counting prime partitions.

Interesting notes or insights from the AI implementation process: AI-generated solution using sieve and DP for prime partition counting.
*/
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution077 implements Solution {
  public String solve() {
    final int N = 1000;
    boolean[] is_prime = new boolean[N + 1];
    for (int i = 0; i <= N; ++i) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (long i = 2; i <= N; ++i) {
      if (is_prime[(int)i]) {
        for (long j = i * i; j <= N; j += i) {
          is_prime[(int)j] = false;
        }
      }
    }
    int[] primes = new int[N];
    int count = 0;
    for (int i = 2; i <= N; ++i) {
      if (is_prime[i]) primes[count++] = i;
    }
    long[] ways = new long[N + 1];
    ways[0] = 1;
    for (int i = 0; i < count; ++i) {
      int p = primes[i];
      for (int j = p; j <= N; ++j) {
        ways[j] += ways[j - p];
      }
    }
    for (int n = 2; n <= N; ++n) {
      if (ways[n] > 5000) return String.valueOf(n);
    }
    return "-1";
  }
}