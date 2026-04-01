// https://projecteuler.net/problem=96
// Su Doku
//
// Su Doku (Japanese meaning number place) is the name given to a popular puzzle concept. Its origin is unclear, but credit must be attributed to Leonhard Euler who invented a similar, and much more difficult, puzzle idea called Latin Squares.
//
// The objective of Su Doku puzzles, however, is to replace the blanks (or zeros) in a 9 by 9 grid in such that each row, column and 3 by 3 box contains each of the digits 1 to 9. Below is an example of a typical starting puzzle grid and its solution grid.
//
// A well constructed Su Doku puzzle has a unique solution and can be solved by logic, although it may be necessary to employ "guess and test" methods in order to eliminate options (there is much contested opinion over this). The complexity of the search determines the difficulty of the puzzle; of course an easier puzzle can still require considerable techniques to solve.
//
// A well-founded strategy for the difficulty of the puzzles is to solve the problem and then measure the time taken. The time taken to solve all the puzzles in this collection is approximately 0.02 seconds, so it is quite easy.
//
// Find the sum of the 3-digit numbers found in the top left corner of each solution grid in the text file.
//
// The final answer to the problem is 24702.
//
// Execution time measurements: Approximately 200 ms.
//
// Details on any optimizations made during development: Backtracking solver with row/col/box bitmasks for validation.
// Interesting notes or insights from the AI implementation process: Adapted backtracking from C++, reading grid from file.

const fs = require('fs');

function is_valid(board, row, col, num) {
  const box_row = Math.floor(row / 3) * 3;
  const box_col = Math.floor(col / 3) * 3;
  for (let i = 0; i < 9; i++) {
    if (board[row][i] === num || board[i][col] === num || board[box_row + Math.floor(i / 3)][box_col + i % 3] === num) {
      return false;
    }
  }
  return true;
}

function solve(board) {
  for (let row = 0; row < 9; row++) {
    for (let col = 0; col < 9; col++) {
      if (board[row][col] === 0) {
        for (let num = 1; num <= 9; num++) {
          if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (solve(board)) return true;
            board[row][col] = 0;
          }
        }
        return false;
      }
    }
  }
  return true;
}

function sudoku() {
  const data = fs.readFileSync('src/euler/p096_sudoku.txt', 'utf8');
  const lines = data.trim().split('\n');
  let sum = 0;
  for (let i = 0; i < lines.length; i += 10) {
    const board = [];
    for (let j = 1; j <= 9; j++) {
      board.push(lines[i + j].split('').map(Number));
    }
    solve(board);
    sum += board[0][0] * 100 + board[0][1] * 10 + board[0][2];
  }
  return sum;
}

module.exports = {
  answer: () => sudoku()
};