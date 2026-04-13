// https://projecteuler.net/problem=92
// Square digit chains
//
// A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.
//
// For example,
//
// 44 → 32 → 13 → 10 → 1 → 1
// 85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89
//
// Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.
//
// How many starting numbers below ten million will arrive at 89?
//
// The final answer to the problem is 8581146.
//
// Execution time measurements: Approximately 2000 ms.
//
// Details on any optimizations made during development: Memoization of chain ends for sums up to 569, avoiding recomputation.
// Interesting notes or insights from the AI implementation process: Adapted recursive memoization from C++, handling large loop efficiently.

const MAX_SUM = 9 * 9 * 7 + 1;

const memo = new Array(MAX_SUM).fill(0);

function sum_square_digits(n) {
  let sum = 0;
  while (n > 0) {
    const d = n % 10;
    sum += d * d;
    n = Math.floor(n / 10);
  }
  return sum;
}

function get_chain_end(n) {
  if (n === 1) return 1;
  if (n === 89) return 2;
  if (memo[n] !== 0) return memo[n];
  return memo[n] = get_chain_end(sum_square_digits(n));
}

function square_digit_chains() {
  let count = 0;
  for (let i = 1; i < 10000000; i++) {
    if (get_chain_end(sum_square_digits(i)) === 2) count++;
  }
  return count;
}

module.exports = {
  answer: () => square_digit_chains()
};