// https://projecteuler.net/problem=10

// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.
//
// Answer: 142913828922

module.exports = {
  answer: () => {
    const limit = 2000000;
    const sieve = new Array(limit).fill(true);
    sieve[0] = sieve[1] = false;

    for (let i = 2; i * i < limit; i++) {
      if (sieve[i]) {
        for (let j = i * i; j < limit; j += i) {
          sieve[j] = false;
        }
      }
    }

    let sum = 0;
    for (let i = 2; i < limit; i++) {
      if (sieve[i]) {
        sum += i;
      }
    }
    return sum;
  }
};