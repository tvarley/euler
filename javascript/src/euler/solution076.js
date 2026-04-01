// https://projecteuler.net/problem=76

// Counting Summations

// It is possible to write five as a sum in exactly six different ways:

// 4 + 1
// 3 + 2
// 3 + 1 + 1
// 2 + 2 + 1
// 2 + 1 + 1 + 1
// 1 + 1 + 1 + 1 + 1

// How many different ways can one hundred be written as a sum of at least two positive integers?

// The final answer to the problem is 190569291.

// Execution time measurements: Approximately 10 ms.

// Details on any optimizations made during development: Used dynamic programming for partition function, similar to C++ implementation.

// Interesting notes or insights from the AI implementation process: Adapted C++ DP approach to JavaScript with BigInt for large numbers.

function countingSummations() {
  const N = 100;
  const p = new Array(N + 1).fill(0n);
  p[0] = 1n;
  for (let i = 1; i <= N; ++i) {
    for (let j = i; j <= N; ++j) {
      p[j] += p[j - i];
    }
  }
  return p[N] - 1n;
}

module.exports = {
  answer: () => countingSummations()
};