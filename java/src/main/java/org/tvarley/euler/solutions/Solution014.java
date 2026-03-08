/*
 * Solution for Euler problem 014
 *
 * Longest Collatz sequence
 *
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 *
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains
 * 10 terms. Although it has not been proved yet (Collatz Problem), it is thought
 * that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution014 implements Solution {
  private static final int MAX = 1000000;
  private int[] cache = new int[MAX];

  public String solve() {
    int maxLength = 0;
    int startingNumber = 0;

    for (int i = 1; i < MAX; i++) {
      int length = getSequenceLength(i);
      if (length > maxLength) {
        maxLength = length;
        startingNumber = i;
      }
    }

    return Integer.toString(startingNumber);
  }

  private int getSequenceLength(long n) {
    if (n < MAX && cache[(int)n] != 0) {
      return cache[(int)n];
    }

    int length = 1;
    long current = n;

    while (current != 1) {
      if (current % 2 == 0) {
        current = current / 2;
      } else {
        current = 3 * current + 1;
      }
      length++;

      if (current < MAX && cache[(int)current] != 0) {
        length += cache[(int)current] - 1;
        break;
      }
    }

    if (n < MAX) {
      cache[(int)n] = length;
    }

    return length;
  }
}