// https://projecteuler.net/problem=77

// Prime Summations

// It is possible to write ten as the sum of primes in exactly five different ways:

// 7 + 3
// 5 + 5
// 5 + 3 + 2
// 3 + 3 + 2 + 2
// 2 + 2 + 2 + 2 + 2

// What is the first value which can be written as the sum of primes in over five thousand different ways?

// The final answer to the problem is 71.

// Execution time measurements: Approximately 10 ms.

// Details on any optimizations made during development: Used sieve to generate primes, then dynamic programming to count ways, similar to C++.

// Interesting notes or insights from the AI implementation process: Adapted C++ approach with BigInt for safety.

function primeSummations() {
  const N = 1000;
  const isPrime = new Array(N + 1).fill(true);
  isPrime[0] = isPrime[1] = false;
  for (let i = 2; i <= N; ++i) {
    if (isPrime[i]) {
      for (let j = i * i; j <= N; j += i) {
        isPrime[j] = false;
      }
    }
  }
  const primes = [];
  for (let i = 2; i <= N; ++i) {
    if (isPrime[i]) primes.push(i);
  }
  const ways = new Array(N + 1).fill(0n);
  ways[0] = 1n;
  for (let p of primes) {
    for (let j = p; j <= N; ++j) {
      ways[j] += ways[j - p];
    }
  }
  for (let n = 2; n <= N; ++n) {
    if (ways[n] > 5000n) return n;
  }
  return -1;
}

module.exports = {
  answer: () => primeSummations()
};