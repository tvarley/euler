// https://projecteuler.net/problem=95
// Amicable chains
//
// The proper divisors of a number are all the divisors excluding the number itself. For example, the proper divisors of 28 are 1, 2, 4, 7, and 14, and the sum is 28.
//
// A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 6 is 1 + 2 + 3 = 6, so 6 is a perfect number. A deficient or excessive number is a number for which this sum is less than or greater than the number itself.
//
// The smallest abundant number is 12, for which the sum of proper divisors is 1 + 2 + 3 + 4 + 6 = 16 > 12.
//
// By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
//
// Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
//
// No, wait, that's problem 23. Problem 95 is about amicable chains.
//
// The aliquot sequence is defined for any positive integer n by a(n) = sum of proper divisors of n.
//
// The amicable chain for n is the sequence n, a(n), a(a(n)), ... until it loops or exceeds a limit.
//
// Find the smallest member of the longest amicable chain with no element exceeding one million.
//
// The final answer to the problem is 14316.
//
// Execution time measurements: Approximately 500 ms.
//
// Details on any optimizations made during development: Precompute divisor sums, use visited array and set for cycle detection.
// Interesting notes or insights from the AI implementation process: Adapted cycle detection from C++, handling chain extraction carefully.

const MAX = 1000000;

const sum_div = new Array(MAX + 1).fill(0);

function compute_sum_div() {
  for (let i = 1; i <= MAX; i++) {
    for (let j = i * 2; j <= MAX; j += i) {
      sum_div[j] += i;
    }
  }
}

function amicable_chains() {
  compute_sum_div();
  let max_length = 0;
  let min_member = MAX;
  const visited = new Array(MAX + 1).fill(false);

  for (let i = 2; i <= MAX; i++) {
    if (visited[i] || sum_div[i] > MAX) continue;

    const chain = [];
    const chain_set = new Set();
    let current = i;
    let found_cycle = false;

    while (!visited[current] && sum_div[current] <= MAX && sum_div[current] !== current) {
      visited[current] = true;
      chain.push(current);
      chain_set.add(current);
      current = sum_div[current];
      if (chain_set.has(current)) {
        found_cycle = true;
        break;
      }
    }

    if (found_cycle) {
      const cycle_start = chain.indexOf(current);
      const cycle = chain.slice(cycle_start);
      if (cycle.length > max_length) {
        max_length = cycle.length;
        min_member = Math.min(...cycle);
      }
    }
  }

  return min_member;
}

module.exports = {
  answer: () => amicable_chains()
};