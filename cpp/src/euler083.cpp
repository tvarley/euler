// https://projecteuler.net/problem=83
// Path Sum: Four Ways
//
// NOTE: This problem is a significantly more challenging version of Problem 81.
//
// In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by moving left, right, up, and down, is indicated in bold red and is equal to 2297.
//
// $$ \begin{pmatrix} \color{red}{131} & 673 & \color{red}{234} & \color{red}{103} & \color{red}{18}\\ \color{red}{201} & \color{red}{96} & \color{red}{342} & 965 & \color{red}{150}\\ 630 & 803 & 746 & \color{red}{422} & \color{red}{111}\\ 537 & 699 & 497 & \color{red}{121} & 956\\ 805 & 732 & 524 & \color{red}{37} & \color{red}{331} \end{pmatrix} $$
//
// Find the minimal path sum from the top left to the bottom right by moving left, right, up, and down in matrix.txt (right click and "Save Link/Target As..."), a 31K text file containing an 80 by 80 matrix.
//
// Answer: 425185

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <algorithm>
#include <climits>

int path_sum_four_ways() {
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
    std::vector<std::vector<int>> dist(80, std::vector<int>(80, INT_MAX));
    dist[0][0] = matrix[0][0];
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> pq;
    pq.push({matrix[0][0], 0, 0});
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};
    while (!pq.empty()) {
        auto [cost, i, j] = pq.top(); pq.pop();
        if (cost > dist[i][j]) continue;
        for (int d = 0; d < 4; ++d) {
            int ni = i + di[d], nj = j + dj[d];
            if (ni >= 0 && ni < 80 && nj >= 0 && nj < 80) {
                int ncost = cost + matrix[ni][nj];
                if (ncost < dist[ni][nj]) {
                    dist[ni][nj] = ncost;
                    pq.push({ncost, ni, nj});
                }
            }
        }
    }
    return dist[79][79];
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
    std::cout << "Answer: " << path_sum_four_ways() << std::endl;
}
#endif