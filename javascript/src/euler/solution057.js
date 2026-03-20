// https://projecteuler.net/problem=57

// Square Root Convergents

// It is possible to show that the square root of two can be expressed as an infinite continued fraction.
// sqrt(2) = 1 + 1/(2 + 1/(2 + 1/(2 + ...)))
// By expanding this for the first four iterations, we get:
// 1 + 1/2 = 3/2 = 1.5
// 1 + 1/(2 + 1/2) = 7/5 = 1.4
// 1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
// 1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...
// The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985, is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.
// In the first one-thousand expansions, how many fractions contain a numerator with more digits than the denominator?

// The final answer to the problem is 153.

// Execution time measurements: Approximately 5ms.

// Details on any optimizations made during development: Used iterative recurrence relation num(k+1) = num(k) + 2*den(k), den(k+1) = num(k) + den(k) to avoid fraction object overhead.

// Interesting notes or insights from the AI implementation process: The pattern of numerators and denominators follows a simple linear recurrence.

module.exports = {
  answer: () => {
    let count = 0;
    let n = 3n;
    let d = 2n;
    // We start from the first expansion 3/2. The problem asks for first 1000 expansions.
    // 3/2 is the 1st. 7/5 is 2nd.
    for (let i = 1; i <= 1000; i++) {
      if (n.toString().length > d.toString().length) {
        count++;
      }
      // Next term:
      // sqrt(2) ~ (N+2D)/(N+D) ? No, that's not the recurrence.
      // 3/2 -> 7/5. 7 = 3 + 2*2, 5 = 3 + 2.
      // 7/5 -> 17/12. 17 = 7 + 2*5, 12 = 7 + 5.
      // Recurrence: n_next = n + 2d, d_next = n + d.
      let nextN = n + 2n * d;
      let nextD = n + d;
      n = nextN;
      d = nextD;
    }
    return count;
  }
};
