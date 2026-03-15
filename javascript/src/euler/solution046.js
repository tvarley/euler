// https://projecteuler.net/problem=46

// It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
// 9 = 7 + 2×1²
// 15 = 7 + 2×2²
// 21 = 3 + 2×3²
// 25 = 7 + 2×3²
// 27 = 19 + 2×2²
// 33 = 31 + 2×1²
// It turns out that the conjecture was false.
// What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

// Answer: 5777

const isPrime = (n) => {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 === 0 || n % 3 === 0) return false;
  for (let i = 5; i * i <= n; i += 6) {
    if (n % i === 0 || n % (i + 2) === 0) return false;
  }
  return true;
};

const isComposite = (n) => !isPrime(n) && n > 1;

module.exports = {
  answer: () => {
    for (let n = 9; ; n += 2) {
      if (!isComposite(n)) continue;
      let found = false;
      for (let k = 1; 2 * k * k < n; k++) {
        const p = n - 2 * k * k;
        if (isPrime(p)) {
          found = true;
          break;
        }
      }
      if (!found) return n;
    }
  }
};