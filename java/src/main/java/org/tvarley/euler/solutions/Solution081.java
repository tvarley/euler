/*
Path Sum: Two Ways

In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down, is indicated in bold red and is equal to 2427.

$$ \begin{pmatrix} \color{red}{131} & 673 & 234 & 103 & 18\\ \color{red}{201} & \color{red}{96} & \color{red}{342} & 965 & 150\\ 630 & 803 & \color{red}{746} & \color{red}{422} & 111\\ 537 & 699 & 497 & \color{red}{121} & 956\\ 805 & 732 & 524 & \color{red}{37} & \color{red}{331} \end{pmatrix} $$

Find the minimal path sum from the top left to the bottom right by only moving right and down in matrix.txt (right click and 'Save Link/Target As...'), a 31K text file containing an 80 by 80 matrix.

The final answer to the problem is 427337.

Execution time measurements: Less than 1 ms on standard hardware.

Details on any optimizations made during development: Dynamic programming for minimal path sum in grid.

Interesting notes or insights from the AI implementation process: AI-generated solution using DP to find minimal path in matrix.
*/
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.io.*;
import java.util.*;

public class Solution081 implements Solution {
  public String solve() {
    int[][] matrix = new int[80][80];
    try (InputStream is = getClass().getResourceAsStream("/matrix.txt");
         BufferedReader br = new BufferedReader(new InputStreamReader(is))) {
      String line;
      int row = 0;
      while ((line = br.readLine()) != null && row < 80) {
        String[] tokens = line.split(",");
        for (int col = 0; col < 80; ++col) {
          matrix[row][col] = Integer.parseInt(tokens[col]);
        }
        ++row;
      }
    } catch (IOException e) {
      return "";
    }
    int[][] dp = new int[80][80];
    for (int i = 0; i < 80; ++i) {
      for (int j = 0; j < 80; ++j) {
        dp[i][j] = matrix[i][j];
      }
    }
    for (int j = 1; j < 80; ++j) {
      dp[0][j] += dp[0][j - 1];
    }
    for (int i = 1; i < 80; ++i) {
      dp[i][0] += dp[i - 1][0];
      for (int j = 1; j < 80; ++j) {
        dp[i][j] += Math.min(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return String.valueOf(dp[79][79]);
  }
}