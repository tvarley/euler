// https://projecteuler.net/problem=47

// The first two consecutive numbers to have two distinct prime factors are:
// 14 = 2 × 7
// 15 = 3 × 5.
// The first three consecutive numbers to have three distinct prime factors are:
// 644 = 2² × 7 × 23
// 645 = 3 × 5 × 43
// 646 = 2 × 17 × 19.
// Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?

// Answer: 134043

const distinctPrimeFactors = (n) => {
  const factors = new Set();
  let d = 2;
  while (d * d <= n) {
    while (n % d === 0) {
      factors.add(d);
      n /= d;
    }
    d++;
  }
  if (n > 1) factors.add(n);
  return factors.size;
};

module.exports = {
  answer: () => {
    let n = 2;
    while (true) {
      if (distinctPrimeFactors(n) === 4 &&
          distinctPrimeFactors(n + 1) === 4 &&
          distinctPrimeFactors(n + 2) === 4 &&
          distinctPrimeFactors(n + 3) === 4) {
        return n;
      }
      n++;
    }
  }
};