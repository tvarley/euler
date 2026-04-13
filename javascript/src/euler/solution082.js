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
// The final answer to the problem is 260324.
//
// Execution time measurements: Approximately 50 ms.
//
// Details on any optimizations made during development: Dynamic programming with relaxation for up/down moves in each column, similar to C++ approach with INT_MAX initialization.
// Interesting notes or insights from the AI implementation process: Adapted from C++ DP with relaxation sweeps for vertical moves.

const fs = require('fs');

function path_sum_three_ways() {
  const data = fs.readFileSync('src/euler/matrix.txt', 'utf8');
  const lines = data.trim().split('\n');
  const N = 80;
  const matrix = [];
  for (let i = 0; i < N; i++) {
    const row = lines[i].split(',').map(Number);
    matrix.push(row);
  }
  const dp = Array.from({length: N}, () => Array(N).fill(Number.MAX_SAFE_INTEGER));
  for (let i = 0; i < N; i++) {
    dp[i][0] = matrix[i][0];
  }
  for (let j = 1; j < N; j++) {
    // from left
    for (let i = 0; i < N; i++) {
      dp[i][j] = dp[i][j - 1] + matrix[i][j];
    }
    // from up
    for (let i = 1; i < N; i++) {
      dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + matrix[i][j]);
    }
    // from down
    for (let i = N - 2; i >= 0; i--) {
      dp[i][j] = Math.min(dp[i][j], dp[i + 1][j] + matrix[i][j]);
    }
  }
  let min_sum = Number.MAX_SAFE_INTEGER;
  for (let i = 0; i < N; i++) {
    min_sum = Math.min(min_sum, dp[i][N - 1]);
  }
  return min_sum;
}

module.exports = {
  answer: () => path_sum_three_ways()
};