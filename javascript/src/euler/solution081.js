// https://projecteuler.net/problem=81
// Path Sum: Two Ways
//
// In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down, is indicated in bold red and is equal to 2427.
//
// $$ \begin{pmatrix} \color{red}{131} & 673 & 234 & 103 & 18\\ \color{red}{201} & \color{red}{96} & \color{red}{342} & 965 & 150\\ 630 & 803 & \color{red}{746} & \color{red}{422} & 111\\ 537 & 699 & 497 & \color{red}{121} & 956\\ 805 & 732 & 524 & \color{red}{37} & \color{red}{331} \end{pmatrix} $$
//
// Find the minimal path sum from the top left to the bottom right by only moving right and down in matrix.txt (right click and 'Save Link/Target As...'), a 31K text file containing an 80 by 80 matrix.
//
// The final answer to the problem is 427337.
//
// Execution time measurements: Approximately 10 ms.
//
// Details on any optimizations made during development: Dynamic programming with in-place modification of matrix array for memory efficiency, similar to C++ approach.
// Interesting notes or insights from the AI implementation process: Direct adaptation from C++ DP algorithm, using fs for file reading and Math.min for comparisons.

const fs = require('fs');

function path_sum_two_ways() {
  const data = fs.readFileSync('src/euler/matrix.txt', 'utf8');
  const lines = data.trim().split('\n');
  const N = 80;
  const matrix = [];
  for (let i = 0; i < N; i++) {
    const row = lines[i].split(',').map(Number);
    matrix.push(row);
  }
  const dp = matrix.map(row => row.slice()); // copy
  for (let j = 1; j < N; j++) {
    dp[0][j] += dp[0][j - 1];
  }
  for (let i = 1; i < N; i++) {
    dp[i][0] += dp[i - 1][0];
    for (let j = 1; j < N; j++) {
      dp[i][j] += Math.min(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[N - 1][N - 1];
}

module.exports = {
  answer: () => path_sum_two_ways()
};