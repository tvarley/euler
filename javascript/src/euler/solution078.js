// https://projecteuler.net/problem=78

// Coin Partitions

// Let p(n) represent the number of different ways in which n coins can be separated into piles. For example, five coins can be separated into piles in exactly seven different ways, so p(5)=7.

// OOOOO
// OOOO   O
// OOO   OO
// OOO   O   O
// OO   OO   O
// OO   O   O   O
// O   O   O   O   O

// Find the least value of n for which p(n) is divisible by one million.

// The final answer to the problem is 55374.

// Execution time measurements: Approximately 2000 ms.

// Details on any optimizations made during development: Used pentagonal number theorem for partition function, similar to C++.

// Interesting notes or insights from the AI implementation process: Adapted C++ pentagonal recurrence with BigInt.

function coinPartitions() {
  const MOD = 1000000n;
  const MAXN = 100000;
  const p = new Array(MAXN + 1).fill(0n);
  p[0] = 1n;
  for (let n = 1; n <= MAXN; ++n) {
    let i = 1;
    while (true) {
      const pent1 = i * (3 * i - 1) / 2;
      if (pent1 > n) break;
      const sign = (i % 2 === 1) ? 1n : -1n;
      p[n] = (p[n] + sign * p[n - pent1]) % MOD;
      const pent2 = i * (3 * i + 1) / 2;
      if (pent2 > n) break;
      p[n] = (p[n] + sign * p[n - pent2]) % MOD;
      ++i;
    }
    p[n] = (p[n] % MOD + MOD) % MOD;
    if (p[n] === 0n && n > 0) return n;
  }
  return -1;
}

module.exports = {
  answer: () => coinPartitions()
};