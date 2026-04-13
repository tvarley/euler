// https://projecteuler.net/problem=87
// Prime power triples
//
// The smallest number expressible as the sum of a prime square, prime cube, and prime fourth power is 28. In fact, there are exactly four numbers below fifty that can be expressed in such a way:
//
// 28 = 2² + 2³ + 2⁴
// 33 = 3² + 2³ + 2⁴
// 49 = 5² + 2³ + 2⁴
// 47 = 2² + 3³ + 2⁴
//
// How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?
//
// The final answer to the problem is 1097343.
//
// Execution time measurements: Approximately 200 ms.
//
// Details on any optimizations made during development: Sieve for prime generation, nested loops with early breaks, Set for uniqueness.
// Interesting notes or insights from the AI implementation process: Adapted sieve and nested loops from C++, using BigInt for power calculations to avoid overflow.

function prime_power_triples() {
  const LIMIT = 50000000n;
  let max_prime = 0;
  while (BigInt(max_prime) * BigInt(max_prime) < LIMIT) max_prime++;
  max_prime--;
  const is_prime = new Array(max_prime + 1).fill(true);
  is_prime[0] = is_prime[1] = false;
  const primes = [];
  for (let i = 2; i <= max_prime; i++) {
    if (is_prime[i]) {
      primes.push(i);
      for (let j = i * i; j <= max_prime; j += i) {
        is_prime[j] = false;
      }
    }
  }
  const numbers = new Set();
  for (const p4 of primes) {
    const fourth = BigInt(p4) ** 4n;
    if (fourth >= LIMIT) break;
    for (const p3 of primes) {
      const cube = BigInt(p3) ** 3n;
      if (fourth + cube >= LIMIT) break;
      for (const p2 of primes) {
        const square = BigInt(p2) ** 2n;
        const sum = fourth + cube + square;
        if (sum >= LIMIT) break;
        numbers.add(sum);
      }
    }
  }
  return numbers.size;
}

module.exports = {
  answer: () => prime_power_triples()
};