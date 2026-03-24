// https://projecteuler.net/problem=63

// Powerful Digit Counts

// The 5-digit number, 16807=7^5, is also a fifth power. Similarly, the 9-digit number, 134217728=8^9, is a ninth power.
// How many n-digit positive integers exist which are also an nth power?

// The final answer to the problem is 49.

// Execution time measurements: Approximately 0 ms.

// Details on any optimizations made during development: Mathematical logarithmic approach using log10 to compute exact count without power calculations
// Interesting notes or insights from the AI implementation process: AI-generated solution using logarithmic calculation

function powerfulDigitCounts() {
  let count = 0;
  for (let a = 1; a <= 9; a++) {
    const logA = Math.log10(a);
    const maxN = Math.floor(1.0 / (1.0 - logA));
    count += maxN;
  }
  return count;
}

module.exports = {
  answer: () => powerfulDigitCounts()
};