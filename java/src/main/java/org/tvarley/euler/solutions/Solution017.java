/*
 * Solution for Euler problem 017
 *
 * Number letter counts
 *
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five,
 * then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out
 * in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
 * forty-two) contains 23 letters and 115 (one hundred and fifteen) contains
 * 20 letters. The use of "and" when writing out numbers is in compliance with
 * British usage.
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;

public class Solution017 implements Solution {
  private static final String[] ONES = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  private static final String[] TEENS = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  private static final String[] TENS = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

  public String solve() {
    int totalLetters = 0;
    for (int i = 1; i <= 1000; i++) {
      totalLetters += countLetters(numberToWords(i));
    }
    return Integer.toString(totalLetters);
  }

  private String numberToWords(int n) {
    if (n == 1000) return "one thousand";

    StringBuilder sb = new StringBuilder();

    if (n >= 100) {
      sb.append(ONES[n / 100]).append(" hundred");
      n %= 100;
      if (n > 0) sb.append(" and ");
    }

    if (n >= 20) {
      sb.append(TENS[n / 10]);
      n %= 10;
      if (n > 0) sb.append("-");
    } else if (n >= 10) {
      sb.append(TEENS[n - 10]);
      return sb.toString();
    }

    if (n > 0) {
      sb.append(ONES[n]);
    }

    return sb.toString();
  }

  private int countLetters(String word) {
    int count = 0;
    for (char c : word.toCharArray()) {
      if (Character.isLetter(c)) {
        count++;
      }
    }
    return count;
  }
}