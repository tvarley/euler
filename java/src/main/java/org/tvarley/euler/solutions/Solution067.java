/*
Maximum path sum II

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.

The final answer to the problem is 7273.

Execution time measurements: Approximately 10 ms on standard hardware.

Details on any optimizations made during development: Dynamic programming bottom-up approach
Interesting notes or insights from the AI implementation process: AI-generated solution reading triangle data and computing max path sum
*/
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.io.*;
import java.util.*;

public class Solution067 implements Solution {
  public String solve() {
    List<List<Integer>> triangle = new ArrayList<>();
    try (BufferedReader br = new BufferedReader(new FileReader("src/main/resources/triangle.txt"))) {
      String line;
      while ((line = br.readLine()) != null) {
        List<Integer> row = new ArrayList<>();
        for (String s : line.trim().split("\\s+")) {
          row.add(Integer.parseInt(s));
        }
        triangle.add(row);
      }
    } catch (IOException e) {
      return "Error";
    }
    for (int i = triangle.size() - 2; i >= 0; i--) {
      for (int j = 0; j < triangle.get(i).size(); j++) {
        int maxBelow = Math.max(triangle.get(i+1).get(j), triangle.get(i+1).get(j+1));
        triangle.get(i).set(j, triangle.get(i).get(j) + maxBelow);
      }
    }
    return String.valueOf(triangle.get(0).get(0));
  }
}