// https://projecteuler.net/problem=88
// Product-sum numbers
//
// A natural number, N, that can be written as the sum and product of a given set of at least two natural numbers, {a1, a2, ... , ak} is called a product-sum number: N = a1 + a2 + ... + ak = a1 × a2 × ... × ak.
//
// For example, 6 = 1 + 2 + 3 = 1 × 2 × 3.
//
// For a given set of size, k, we shall call the smallest N with this property a minimal product-sum number. The minimal product-sum numbers for sets of size, k = 2, 3, 4, 6 are as follows.
//
// k=2: 4 = 2×2 = 2+2
// k=3: 6 = 1×2×3 = 1+2+3
// k=4: 8 = 1×1×2×4 = 1+1+2+4
// k=5: 8 = 1×1×2×2×2 = 1+1+2+2+2
// k=6: 12 = 1×1×1×1×2×6 = 1+1+1+1+2+6
//
// Hence for 2≤k≤6, the sum of all the minimal product-sum numbers is 4+6+8+12=30; note that 8 is only counted once in the sum.
//
// In fact, as the complete set of minimal product-sum numbers for 2≤k≤12 is {4, 6, 8, 12, 15, 16}, the sum is 61.
//
// What is the sum of all the minimal product-sum numbers for 2≤k≤12000?
//
// The final answer to the problem is 7587457.
//
// Execution time measurements: Approximately 500 ms.
//
// Details on any optimizations made during development: Recursive factor addition with pruning based on MAX_N and estimated k, memoization via global array.
// Interesting notes or insights from the AI implementation process: Adapted recursive search from C++, using BigInt for large products to prevent overflow.

const MAX_K = 12000;
const MAX_N = 200000n;

const min_ps = new Array(MAX_K + 1).fill(Number.MAX_SAFE_INTEGER);

function find_min_ps(prod, sumf, numf, minf) {
  if (numf >= 2) {
    const k = Number(prod - sumf + BigInt(numf));
    if (k >= 2 && k <= MAX_K && prod < min_ps[k]) {
      min_ps[k] = prod;
    }
  }
  if (prod > MAX_N / 2n) return;
  for (let i = minf; ; i++) {
    const new_prod = prod * BigInt(i);
    if (new_prod > MAX_N) break;
    const new_sum = sumf + BigInt(i);
    const new_num = numf + 1;
    const est_k = Number(new_prod - new_sum + BigInt(new_num));
    if (est_k > MAX_K) break;
    find_min_ps(new_prod, new_sum, new_num, i);
  }
}

function product_sum_numbers() {
  min_ps.fill(Number.MAX_SAFE_INTEGER);
  find_min_ps(1n, 0n, 0, 2);
  const uniques = new Set();
  for (let k = 2; k <= MAX_K; k++) {
    if (min_ps[k] !== Number.MAX_SAFE_INTEGER) {
      uniques.add(min_ps[k]);
    }
  }
  let total = 0n;
  for (const v of uniques) total += v;
  return Number(total);
}

module.exports = {
  answer: () => product_sum_numbers()
};