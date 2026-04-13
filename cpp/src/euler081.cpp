// https://projecteuler.net/problem=81
// Path Sum: Two Ways
//
// In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down, is indicated in bold red and is equal to 2427.
//
// $$ \begin{pmatrix} \color{red}{131} & 673 & 234 & 103 & 18\\ \color{red}{201} & \color{red}{96} & \color{red}{342} & 965 & 150\\ 630 & 803 & \color{red}{746} & \color{red}{422} & 111\\ 537 & 699 & 497 & \color{red}{121} & 956\\ 805 & 732 & 524 & \color{red}{37} & \color{red}{331} \end{pmatrix} $$
//
// Find the minimal path sum from the top left to the bottom right by only moving right and down in matrix.txt (right click and 'Save Link/Target As...'), a 31K text file containing an 80 by 80 matrix.
//
// Answer: 427337

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

int path_sum_two_ways() {
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
    std::vector<std::vector<int>> dp = matrix;
    for (int j = 1; j < 80; ++j) {
        dp[0][j] += dp[0][j - 1];
    }
    for (int i = 1; i < 80; ++i) {
        dp[i][0] += dp[i - 1][0];
        for (int j = 1; j < 80; ++j) {
            dp[i][j] += std::min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[79][79];
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    std::cout << "Answer: " << path_sum_two_ways() << std::endl;
}
#endif