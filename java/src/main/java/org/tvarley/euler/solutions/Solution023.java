/*
 * Solution for Euler problem 023
 *
 * Non-abundant sums
 *
 * A number n is called abundant if the sum of its proper divisors exceeds n.
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the
 * smallest number that can be written as the sum of two abundant numbers is 24.
 * By mathematical analysis, it can be shown that all integers greater than
 * 28123 can be written as the sum of two abundant numbers.
 *
 * Find the sum of all the positive integers which cannot be written as the sum
 * of two abundant numbers.
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.util.ArrayList;
import java.util.List;

public class Solution023 implements Solution {
  private static final int LIMIT = 28123;

  public String solve() {
    List<Integer> abundant = new ArrayList<>();
    for (int i = 12; i <= LIMIT; i++) {
      if (sumOfDivisors(i) > i) {
        abundant.add(i);
      }
    }

    boolean[] canBeSum = new boolean[LIMIT + 1];
    for (int i = 0; i < abundant.size(); i++) {
      for (int j = i; j < abundant.size(); j++) {
        int sum = abundant.get(i) + abundant.get(j);
        if (sum <= LIMIT) {
          canBeSum[sum] = true;
        } else {
          break;
        }
      }
    }

    long total = 0;
    for (int i = 1; i <= LIMIT; i++) {
      if (!canBeSum[i]) {
        total += i;
      }
    }

    return Long.toString(total);
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
