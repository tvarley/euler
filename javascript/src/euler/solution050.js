// https://projecteuler.net/problem=50

// The prime 41, can be written as the sum of six consecutive primes:
// 41 = 2 + 3 + 5 + 7 + 11 + 13.
// This is the longest sum of consecutive primes that adds to a prime below one-hundred.
// The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
// Which prime, below one-million, can be written as the sum of the most consecutive primes?

// Answer: 997651

const isPrime = (n) => {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 === 0 || n % 3 === 0) return false;
  for (let i = 5; i * i <= n; i += 6) {
    if (n % i === 0 || n % (i + 2) === 0) return false;
  }
  return true;
};

module.exports = {
  answer: () => {
    const primes = [];
    for (let i = 2; i < 1000000; i++) {
      if (isPrime(i)) primes.push(i);
    }
    let maxLength = 0;
    let maxPrime = 0;
    const n = primes.length;
    for (let i = 0; i < n; i++) {
      let sum = 0;
      for (let j = i; j < n; j++) {
        sum += primes[j];
        if (sum >= 1000000) break;
        if (j - i + 1 > maxLength && isPrime(sum)) {
          maxLength = j - i + 1;
          maxPrime = sum;
        }
      }
    }
    return maxPrime;
  }
};