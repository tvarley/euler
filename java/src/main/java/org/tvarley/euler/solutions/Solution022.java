/*
 * Solution for Euler problem 022
 *
 * Names scores
 *
 * Using names.txt, a 46K text file containing over five-thousand first names,
 * begin by sorting it into alphabetical order. Then working out the alphabetical
 * value for each name, multiply this value by its alphabetical position in the
 * list to obtain a name score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which is
 * worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN
 * would obtain a score of 938 × 53 = 49714.
 *
 * What is the total of all the name scores in the file?
 *
 * @author tvarley
 * @date 3/8/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;

public class Solution022 implements Solution {
  public String solve() {
    String[] names;
    try {
      String raw = new String(Files.readAllBytes(Paths.get("../cpp/src/p022_names.txt")));
      names = raw.split(",");
      for (int i = 0; i < names.length; i++) {
        names[i] = names[i].replace("\"", "");
      }
    } catch (IOException e) {
      return "error: " + e.getMessage();
    }

    Arrays.sort(names);

    long totalScore = 0;
    for (int i = 0; i < names.length; i++) {
      int nameValue = 0;
      for (char c : names[i].toCharArray()) {
        nameValue += c - 'A' + 1;
      }
      totalScore += (long) nameValue * (i + 1);
    }

    return Long.toString(totalScore);
  }
}
