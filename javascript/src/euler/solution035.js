// https://projecteuler.net/problem=35

// The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime. There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97. How many circular primes are there below one million?
//
// Answer: 55

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

    function isCircular(p) {
      const s = p.toString();
      for (let i = 0; i < s.length; i++) {
        const rotated = s.slice(i) + s.slice(0, i);
        if (!primes.has(parseInt(rotated))) return false;
      }
      return true;
    }

    let count = 0;
    for (const p of primes) {
      if (p < 10 || isCircular(p)) count++;
    }
    return count;
  }
};