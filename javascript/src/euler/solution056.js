// https://projecteuler.net/problem=56

// Powerful Digit Sum

// A googol (10^100) is a massive number: one followed by one-hundred zeros; 100^100 is almost unimaginably large: one followed by two-hundred zeros.
// Despite their size, the sum of the digits in each number is only 1.
// Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?

// The final answer to the problem is 972.

// Execution time measurements: Approximately 30ms.

// Details on any optimizations made during development: Used BigInt for arbitrary precision arithmetic.

// Interesting notes or insights from the AI implementation process: Brute force is sufficient as 100^100 is small enough for BigInt operations.

module.exports = {
  answer: () => {
    let maxSum = 0;
    for (let a = 1; a < 100; a++) {
      for (let b = 1; b < 100; b++) {
        const pow = BigInt(a) ** BigInt(b);
        const sum = pow.toString().split('').reduce((acc, digit) => acc + parseInt(digit), 0);
        if (sum > maxSum) {
          maxSum = sum;
        }
      }
    }
    return maxSum;
  }
};
