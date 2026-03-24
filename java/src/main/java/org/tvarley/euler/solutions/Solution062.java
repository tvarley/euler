/*
Cubic Permutations

The cube, 41063625 (345^3), can be permuted to produce two other cubes: 56623104 (384^3) and 66430125 (405^3). In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.
Find the smallest cube for which exactly five permutations of its digits are cube.

The final answer to the problem is 127035954683.

Execution time measurements: Approximately 1 ms on standard hardware.

Details on any optimizations made during development: Group cubes by sorted digit string for efficient permutation lookup
Interesting notes or insights from the AI implementation process: AI-generated solution using digit sorting and grouping
*/
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.util.*;

public class Solution062 implements Solution {
  public String solve() {
    Map<String, List<Long>> groups = new HashMap<>();
    for (long n = 1; ; n++) {
      long cube = n * n * n;
      String s = String.valueOf(cube);
      if (s.length() > 12) break;
      String key = s.chars()
          .sorted()
          .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
          .toString();
      groups.computeIfAbsent(key, k -> new ArrayList<>()).add(cube);
    }
    long minCube = Long.MAX_VALUE;
    for (List<Long> group : groups.values()) {
      if (group.size() == 5) {
        for (long c : group) {
          if (c < minCube) minCube = c;
        }
      }
    }
    return String.valueOf(minCube);
  }
}