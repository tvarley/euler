/*
Permuted Multiples

It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

Answer: 142857

*/
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.util.*;

public class Solution052 implements Solution {
  public String solve() {
    for (int x = 1; ; x++) {
      String s = Integer.toString(x);
      char[] digits = s.toCharArray();
      Arrays.sort(digits);
      boolean allSame = true;
      for (int mul = 2; mul <= 6; mul++) {
        String ms = Integer.toString(x * mul);
        if (ms.length() != s.length()) {
          allSame = false;
          break;
        }
        char[] mDigits = ms.toCharArray();
        Arrays.sort(mDigits);
        if (!Arrays.equals(digits, mDigits)) {
          allSame = false;
          break;
        }
      }
      if (allSame) {
        return Integer.toString(x);
      }
    }
  }
}