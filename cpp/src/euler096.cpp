// Problem 96: Su Doku
// https://projecteuler.net/problem=96
// Find the sum of the 3-digit numbers found in the top left corner of each solution grid.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

bool is_valid(const std::vector<std::vector<int>>& grid, int row, int col, int num) {
    for (int i = 0; i < 9; ++i) {
        if (grid[row][i] == num || grid[i][col] == num) return false;
    }
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[box_row + i][box_col + j] == num) return false;
        }
    }
    return true;
}

bool solve(std::vector<std::vector<int>>& grid) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (is_valid(grid, row, col, num)) {
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

long long su_doku() {
    std::ifstream file("src/p096_sudoku.txt");
    if (!file) return 0;
    long long sum = 0;
    std::string line;
    while (std::getline(file, line)) {
        if (line.substr(0, 4) == "Grid") continue;
        std::vector<std::vector<int>> grid(9, std::vector<int>(9));
        // Parse the first line we already read
        for (int j = 0; j < 9; ++j) {
            grid[0][j] = line[j] - '0';
        }
        // Read remaining 8 lines
        for (int i = 1; i < 9; ++i) {
            std::getline(file, line);
            for (int j = 0; j < 9; ++j) {
                grid[i][j] = line[j] - '0';
            }
        }
        solve(grid);
        int num = grid[0][0] * 100 + grid[0][1] * 10 + grid[0][2];
        sum += num;
    }
    return sum;
}

#ifndef UNITTEST_MODE
int main() {
    std::cout << su_doku() << std::endl;
    return 0;
}
#endif