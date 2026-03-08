/*
 * Solution for Euler problem 024
 *
 * Lexicographic permutations
 *
 * A permutation is an ordered arrangement of objects. For example, 3124 is one
 * possible permutation of the digits 1, 2, 3 and 4. If all of the permutations
 * are listed numerically or alphabetically, we call it lexicographic order.
 * The lexicographic permutations of 0, 1 and 2 are:
 * 012  021  102  120  201  210
 *
 * What is the millionth lexicographic permutation of the digits 0-9?
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution024 implements Solution {
  public String solve() {
    List<Integer> digits = new ArrayList<>(Arrays.asList(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
    int target = 999999;
    StringBuilder result = new StringBuilder();

    for (int i = 9; i >= 0; i--) {
      int fact = factorial(i);
      int index = target / fact;
      result.append(digits.remove(index));
      target %= fact;
    }

    return result.toString();
  }

  private int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
      result *= i;
    }
    return result;
  }
}
