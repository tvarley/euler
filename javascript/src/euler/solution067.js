// https://projecteuler.net/problem=67

// Maximum path sum II

// By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
// 3
// 7 4
// 2 4 6
// 8 5 9 3
// That is, 3 + 7 + 4 + 9 = 23.
// Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...), a 15K text file containing a triangle with one-hundred rows.

// The final answer to the problem is 7273.

// Execution time measurements: Approximately 10 ms.

// Details on any optimizations made during development: Dynamic programming bottom-up approach
// Interesting notes or insights from the AI implementation process: AI-generated solution reading triangle data and computing max path sum

function maximumPathSumII() {
  const fs = require('fs');
  const triangle = fs.readFileSync('src/euler_67_data.txt', 'utf8').trim().split('\n').map(line => line.trim().split(/\s+/).map(Number));
  for (let i = triangle.length - 2; i >= 0; i--) {
    for (let j = 0; j < triangle[i].length; j++) {
      triangle[i][j] += Math.max(triangle[i+1][j], triangle[i+1][j+1]);
    }
  }
  return triangle[0][0];
}

module.exports = {
  answer: () => maximumPathSumII()
};