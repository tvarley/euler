/*
 * Solution for Euler problem 042
 *
 * Coded Triangle Numbers
 *
 * The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 * By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
 * Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
 *
 * @author tvarley
 * @date 3/14/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Solution042 implements Solution {
  public String solve() {
    String[] words;
    try {
      String raw = new String(Files.readAllBytes(Paths.get("src/main/resources/p042_words.txt")));
      words = raw.split(",");
      for (int i = 0; i < words.length; i++) {
        words[i] = words[i].replace("\"", "");
      }
    } catch (IOException e) {
      return "error";
    }
    int count = 0;
    for (String word : words) {
      int sum = 0;
      for (char c : word.toCharArray()) {
        sum += c - 'A' + 1;
      }
      if (isTriangular(sum)) {
        count++;
      }
    }
    return Integer.toString(count);
  }

  private boolean isTriangular(int n) {
    int k = (int) Math.sqrt(2 * n);
    return k * (k + 1) / 2 == n;
  }
}