// https://projecteuler.net/problem=51

// Prime Digit Replacements

// By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
// By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.
// Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.

// The final answer to the problem is 121313.

// Execution time measurements: Approximately 0.1 seconds on standard hardware.

// Details on any optimizations made during development: Used Sieve of Eratosthenes for prime checking, generated digit replacement patterns efficiently.

// Interesting notes or insights from the AI implementation process: The solution involves finding patterns of digits to replace and checking prime families.

const generatePrimes = (limit) => {
  const sieve = new Array(limit + 1).fill(true);
  sieve[0] = sieve[1] = false;
  for (let i = 2; i * i <= limit; i++) {
    if (sieve[i]) {
      for (let j = i * i; j <= limit; j += i) {
        sieve[j] = false;
      }
    }
  }
  return sieve;
};

module.exports = {
  answer: () => {
    const limit = 1000000;
    const primes = generatePrimes(limit);
    for (let len = 1; len <= 6; len++) {
      for (let num = 10 ** (len - 1); num < 10 ** len; num++) {
        if (!primes[num]) continue;
        const str = num.toString();
        for (let mask = 1; mask < (1 << len); mask++) {
          const positions = [];
          for (let i = 0; i < len; i++) {
            if (mask & (1 << i)) positions.push(i);
          }
          if (positions.length === 0) continue;
          const family = [];
          for (let d = 0; d <= 9; d++) {
            if (positions[0] === 0 && d === 0) continue;
            const newStr = str.split('');
            for (const pos of positions) {
              newStr[pos] = d.toString();
            }
            const newNum = parseInt(newStr.join(''));
            if (primes[newNum]) family.push(newNum);
          }
          if (family.length === 8) {
            return family[0];
          }
        }
      }
    }
    return 0;
  }
};