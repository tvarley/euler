/*
 * Solution for Euler problem 021
 *
 * Amicable numbers
 *
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n
 * which divide evenly into n). If d(a) = b and d(b) = a, where a ≠ b, then a
 * and b are an amicable pair and each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
 * 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
 * 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution021 implements Solution {
  public String solve() {
    int[] divisorSums = new int[10000];
    for (int i = 1; i < 10000; i++) {
      divisorSums[i] = sumOfDivisors(i);
    }

    int sum = 0;
    for (int a = 1; a < 10000; a++) {
      int b = divisorSums[a];
      if (b < 10000 && b != a && divisorSums[b] == a) {
        sum += a;
      }
    }

    return Integer.toString(sum);
  }

  private int sumOfDivisors(int n) {
    int sum = 1;
    for (int i = 2; (long) i * i <= n; i++) {
      if (n % i == 0) {
        sum += i;
        if (i != n / i) sum += n / i;
      }
    }
    return sum;
  }
}
