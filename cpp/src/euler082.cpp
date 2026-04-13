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

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <climits>

int path_sum_three_ways() {
    std::ifstream file("matrix.txt");
    std::vector<std::vector<int>> matrix(80, std::vector<int>(80));
    std::string line;
    int row = 0;
    while (std::getline(file, line) && row < 80) {
        std::stringstream ss(line);
        std::string token;
        int col = 0;
        while (std::getline(ss, token, ',') && col < 80) {
            matrix[row][col] = std::stoi(token);
            ++col;
        }
        ++row;
    }
    std::vector<std::vector<int>> dp(80, std::vector<int>(80, INT_MAX));
    for (int i = 0; i < 80; ++i) {
        dp[i][0] = matrix[i][0];
    }
    for (int j = 1; j < 80; ++j) {
        // from left
        for (int i = 0; i < 80; ++i) {
            dp[i][j] = dp[i][j - 1] + matrix[i][j];
        }
        // from up and down
        for (int i = 1; i < 80; ++i) {
            dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + matrix[i][j]);
        }
        for (int i = 78; i >= 0; --i) {
            dp[i][j] = std::min(dp[i][j], dp[i + 1][j] + matrix[i][j]);
        }
    }
    int min_sum = INT_MAX;
    for (int i = 0; i < 80; ++i) {
        min_sum = std::min(min_sum, dp[i][79]);
    }
    return min_sum;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    std::cout << "Answer: " << path_sum_three_ways() << std::endl;
}
#endif