// https://projecteuler.net/problem=97
// Large non-Mersenne prime
//
// The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 2^6972593−1; it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2^p−1, have been found which contain more digits.
//
// However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433×2^7830457+1.
//
// Find the last ten digits of this prime number.
//
// The final answer to the problem is 8739992577.
//
// Execution time measurements: Approximately 10 ms.
//
// Details on any optimizations made during development: Modular exponentiation with BigInt for large powers.
// Interesting notes or insights from the AI implementation process: Direct computation using BigInt modular arithmetic.

function large_non_mersenne_prime() {
  const base = 28433n;
  const exp = 7830457n;
  const mod = 10000000000n;
  let result = 1n;
  let b = 2n; // base for exponentiation is 2
  let e = exp;
  while (e > 0n) {
    if (e % 2n === 1n) result = (result * b) % mod;
    b = (b * b) % mod;
    e /= 2n;
  }
  // Now result is 2^exp % mod
  result = (result * (base % mod)) % mod;
  result = (result + 1n) % mod;
  return Number(result);
}

module.exports = {
  answer: () => large_non_mersenne_prime()
};