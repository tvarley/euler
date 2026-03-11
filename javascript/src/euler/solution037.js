// https://projecteuler.net/problem=37

// The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3. Find the sum of the only eleven primes that are both truncatable from left to right and right to left. NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
//
// Answer: 748317

module.exports = {
  answer: () => {
    const limit = 1000000;
    const sieve = new Array(limit).fill(true);
    sieve[0] = sieve[1] = false;
    for (let i = 2; i * i < limit; i++) {
      if (sieve[i]) {
        for (let j = i * i; j < limit; j += i) {
          sieve[j] = false;
        }
      }
    }
    const primes = new Set();
    for (let i = 2; i < limit; i++) {
      if (sieve[i]) primes.add(i);
    }

    function isTruncatable(p) {
      const s = p.toString();
      // left truncate
      for (let i = 1; i < s.length; i++) {
        if (!primes.has(parseInt(s.slice(i)))) return false;
      }
      // right truncate
      for (let i = s.length - 1; i > 0; i--) {
        if (!primes.has(parseInt(s.slice(0, i)))) return false;
      }
      return true;
    }

    let sum = 0;
    let count = 0;
    for (const p of primes) {
      if (p > 7 && isTruncatable(p)) {
        sum += p;
        count++;
        if (count === 11) break;
      }
    }
    return sum;
  }
};