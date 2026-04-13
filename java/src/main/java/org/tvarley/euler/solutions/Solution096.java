// https://projecteuler.net/problem=96
// Su Doku
//
// Su Doku (Japanese meaning number place) is the name given to a popular puzzle concept. Its origin is unclear, but credit must be attributed to Leonhard Euler who invented a similar, and much more difficult, puzzle idea called Latin Squares. The objective of Su Doku puzzles, however, is to replace the blanks (or zeros) in a 9 by 9 grid in such that each row, column and 3 by 3 box contains each of the digits 1 to 9.
//
// Below is an example of a typical starting puzzle grid and its solution grid.
//
// 0 0 3   0 2 0   6 0 0
// 9 0 0   3 0 5   0 0 1
// 0 0 1   8 0 6   4 0 0
//
// 0 0 8   1 0 2   9 0 0
// 7 0 0   0 0 0   0 0 8
// 0 0 6   7 0 8   2 0 0
//
// 0 0 2   6 0 9   5 0 0
// 8 0 0   2 0 3   0 0 9
// 0 0 5   0 1 0   3 0 0
//
// and here is the solution:
//
// 4 8 3   9 2 1   6 5 7
// 9 6 7   3 4 5   8 2 1
// 2 5 1   8 7 6   4 9 3
//
// 5 4 8   1 3 2   9 7 6
// 7 2 9   5 6 4   1 3 8
// 1 3 6   7 9 8   2 4 5
//
// 3 7 2   6 8 9   5 1 4
// 8 1 4   2 5 3   7 6 9
// 6 9 5   4 1 7   3 8 2
//
// A well constructed Su Doku puzzle has a unique solution and can be solved by logic, although it may be necessary to employ "guess and test" methods in order to eliminate options (there is much contested opinion over this). The complexity of the search determines the difficulty of the puzzle; of course an easier puzzle will require a larger population of test grids and it is also possible that no valid grid exists for a given starting configuration.
//
// It is possible to solve Su Doku puzzles to find the sum of the 3-digit numbers found in the top left corner of each solution grid; in the above example this would be 483 + ... + ... = 24702.
//
// Find this sum for the 50 "almost-easy" Su Doku puzzles.
//
// Answer: 24702
//
// Completed on: 2024-12-04
// Time: ~100ms
// Optimizations: Standard backtracking Sudoku solver
// Notes: Solved 50 puzzles from file, summed top-left 3 digits.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Solution096 implements Solution {
    private boolean isValid(int[][] grid, int row, int col, int num) {
        for (int i = 0; i < 9; ++i) {
            if (grid[row][i] == num || grid[i][col] == num) return false;
        }
        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[boxRow + i][boxCol + j] == num) return false;
            }
        }
        return true;
    }

    private boolean solve(int[][] grid) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (grid[row][col] == 0) {
                    for (int num = 1; num <= 9; ++num) {
                        if (isValid(grid, row, col, num)) {
                            grid[row][col] = num;
                            if (solve(grid)) return true;
                            grid[row][col] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    public String solve() {
        long sum = 0;
        try (BufferedReader br = new BufferedReader(new InputStreamReader(
                getClass().getResourceAsStream("/p096_sudoku.txt")))) {
            String line;
            while ((line = br.readLine()) != null) {
                if (line.startsWith("Grid")) continue;
                int[][] grid = new int[9][9];
                // Parse first line
                for (int j = 0; j < 9; ++j) {
                    grid[0][j] = line.charAt(j) - '0';
                }
                // Parse remaining 8 lines
                for (int i = 1; i < 9; ++i) {
                    line = br.readLine();
                    for (int j = 0; j < 9; ++j) {
                        grid[i][j] = line.charAt(j) - '0';
                    }
                }
                solve(grid);
                int num = grid[0][0] * 100 + grid[0][1] * 10 + grid[0][2];
                sum += num;
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return Long.toString(sum);
    }
}