// https://projecteuler.net/problem=82
// Path Sum: Three Ways
//
// NOTE: This problem is a more challenging version of Problem 81.
//
// The minimal path sum in the 5 by 5 matrix below, by starting in any cell in the left column and finishing in any cell in the right column, and only moving up, down, and right, is indicated in red and bold; the sum is equal to 994.
//
// $$ \begin{pmatrix} 131 & 673 & \color{red}{234} & \color{red}{103} & \color{red}{18}\\ \color{red}{201} & \color{red}{96} & \color{red}{342} & 965 & 150\\ 630 & 803 & 746 & 422 & 111\\ 537 & 699 & 497 & 121 & 956\\ 805 & 732 & 524 & 37 & 331 \end{pmatrix} $$
//
// Find the minimal path sum from the left column to the right column in matrix.txt (right click and "Save Link/Target As..."), a 31K text file containing an 80 by 80 matrix.
//
// Answer: 260324
//
// Completed on: 2024-12-04
// Time: ~1ms
// Optimizations: DP with iterative updates per column
// Notes: Similar to Problem 81 but allowing up/down moves. Used 2D DP array to track minimal paths to each cell.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Solution082 implements Solution {
    public String solve() {
        int[][] matrix = readMatrix();
        int n = 80;
        int[][] dp = new int[n][n];
        for (int[] row : dp) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        for (int i = 0; i < n; ++i) {
            dp[i][0] = matrix[i][0];
        }
        for (int j = 1; j < n; ++j) {
            // from left
            for (int i = 0; i < n; ++i) {
                dp[i][j] = dp[i][j - 1] + matrix[i][j];
            }
            // from up
            for (int i = 1; i < n; ++i) {
                dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + matrix[i][j]);
            }
            // from down
            for (int i = n - 2; i >= 0; --i) {
                dp[i][j] = Math.min(dp[i][j], dp[i + 1][j] + matrix[i][j]);
            }
        }
        int minSum = Integer.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            minSum = Math.min(minSum, dp[i][n - 1]);
        }
        return Integer.toString(minSum);
    }

    private int[][] readMatrix() {
        int[][] matrix = new int[80][80];
        try (BufferedReader br = new BufferedReader(new InputStreamReader(
                getClass().getResourceAsStream("/matrix.txt")))) {
            String line;
            int row = 0;
            while ((line = br.readLine()) != null && row < 80) {
                String[] tokens = line.split(",");
                for (int col = 0; col < 80 && col < tokens.length; ++col) {
                    matrix[row][col] = Integer.parseInt(tokens[col]);
                }
                ++row;
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return matrix;
    }
}