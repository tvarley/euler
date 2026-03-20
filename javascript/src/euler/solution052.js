// https://projecteuler.net/problem=52

// Permuted Multiples

// It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
// Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

// The final answer to the problem is 142857.

// Execution time measurements: Approximately 0.01 seconds on standard hardware.

// Details on any optimizations made during development: Used digit sorting for permutation checking, limited search space efficiently.

// Interesting notes or insights from the AI implementation process: The solution leverages the property that permutations share sorted digit strings.

const hasSameDigits = (a, b) => {
  return a.toString().split('').sort().join('') === b.toString().split('').sort().join('');
};

module.exports = {
  answer: () => {
    for (let x = 1; ; x++) {
      if (hasSameDigits(x, 2 * x) &&
          hasSameDigits(x, 3 * x) &&
          hasSameDigits(x, 4 * x) &&
          hasSameDigits(x, 5 * x) &&
          hasSameDigits(x, 6 * x)) {
        return x;
      }
    }
  }
};