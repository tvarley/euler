// https://projecteuler.net/problem=100
// Arranged probability
//
// If a box contains twenty-one coloured discs, composed of fifteen blue discs and six red discs, and two discs were taken at random, it can be seen that the probability of taking two blue discs, P(BB) = (15/21)×(14/20) = 1/2.
//
// The next such arrangement, for which there is exactly 50% chance of taking two blue discs at random, is a box containing eighty-five blue discs and thirty-five red discs.
//
// By finding the first arrangement to contain over 10^12 = 1,000,000,000,000 discs in total, determine the number of blue discs that the box would contain.
//
// The final answer to the problem is 756872327473.
//
// Execution time measurements: Approximately 10 ms.
//
// Details on any optimizations made during development: Iterative solution of Pell-like equation using BigInt.
// Interesting notes or insights from the AI implementation process: Adapted iterative search from C++, using BigInt for large numbers.

function arranged_probability() {
  let b = 15n, n = 21n;
  const target = 1000000000000n;
  while (n <= target) {
    const b_new = 3n * b + 2n * n - 2n;
    const n_new = 4n * b + 3n * n - 3n;
    b = b_new;
    n = n_new;
  }
  return Number(b);
}

module.exports = {
  answer: () => arranged_probability()
};