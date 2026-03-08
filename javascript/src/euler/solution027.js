// https://projecteuler.net/problem=27

// Euler discovered the remarkable quadratic formula: n² + n + 41
// It turns out that the formula will produce 40 primes for the consecutive
// integer values 0 ≤ n ≤ 39.
// The incredible formula n² − 79n + 1601 was discovered, which produces 80
// primes for the consecutive values 0 ≤ n ≤ 79.
// Considering quadratics of the form: n² + an + b, where |a| < 1000 and |b| ≤ 1000
// Find the product of the coefficients, a and b, for the quadratic expression
// that produces the maximum number of primes for consecutive values of n,
// starting with n = 0.
//
// Answer: -59231

function isPrime(n) {
  if (n < 2) return false;
  if (n === 2) return true;
  if (n % 2 === 0) return false;
  for (let i = 3; i * i <= n; i += 2) {
    if (n % i === 0) return false;
  }
  return true;
}

function consecutivePrimes(a, b) {
  let n = 0;
  while (isPrime(n * n + a * n + b)) {
    n++;
  }
  return n;
}

module.exports = {
  answer: () => {
    let maxCount = 0;
    let result = 0;

    for (let a = -999; a < 1000; a++) {
      for (let b = -1000; b <= 1000; b++) {
        const count = consecutivePrimes(a, b);
        if (count > maxCount) {
          maxCount = count;
          result = a * b;
        }
      }
    }

    return result;
  }
};
