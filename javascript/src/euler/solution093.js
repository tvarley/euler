// https://projecteuler.net/problem=93
// Arithmetic expressions
//
// By using each of the digits from the set, {1, 2, 3, 4}, exactly once, and making use of the four arithmetic operations (+, −, *, /) and brackets/parentheses, it is possible to form different positive integer targets.
//
// For example,
//
// 8 = (4 * (1 + 3)) / 2
// 14 = 4 * (3 + 1 / 2)
// 19 = 4! * (3 - 1) + 2
// 36 = 4! * (3 + 1) * 2
//
// Note that concatenations of the digits, like 12 + 34, are not allowed.
//
// Using the set {1, 2, 3, 4}, it is possible to obtain thirty-one different target numbers of which 36 is the maximum, and each of the numbers 1 to 28 can be obtained before encountering the first number that cannot be obtained. However, in this case there are no numbers between 29 and 36 that can be obtained.
//
// It turns out that the set {1, 2, 5, 8} can generate a maximum of sixty-eight, and the set {1, 2, 5, 8} is the only set of four distinct digits that generates the longest set of consecutive positive integers starting with 1.
//
// Find the set of four distinct digits, a < b < c < d, for which the longest set of consecutive positive integers, 1 to n, can be found, where a, b, c, d ∈ {1, 2, 3, 4, 5, 6, 7, 8, 9} and return abcd as a number.
//
// The final answer to the problem is 1258.
//
// Execution time measurements: Approximately 500 ms.
//
// Details on any optimizations made during development: Recursive evaluation of all expression trees, permutation generation for digit orders.
// Interesting notes or insights from the AI implementation process: Adapted recursive expression evaluation from C++, implemented permutation generation in JS.

function evaluate_rec(nums) {
  const n = nums.length;
  const results = new Set();
  if (n === 1) {
    results.add(nums[0]);
    return results;
  }
  for (let i = 1; i < n; i++) {
    const left = nums.slice(0, i);
    const right = nums.slice(i);
    const left_vals = evaluate_rec(left);
    const right_vals = evaluate_rec(right);
    for (const lv of left_vals) {
      for (const rv of right_vals) {
        results.add(lv + rv);
        results.add(lv - rv);
        results.add(lv * rv);
        if (rv !== 0) results.add(lv / rv);
      }
    }
  }
  return results;
}

function evaluate(nums) {
  const doubles = evaluate_rec(nums);
  const ints = new Set();
  for (const d of doubles) {
    if (d > 0 && d === Math.floor(d)) ints.add(d);
  }
  return ints;
}

function permute(arr) {
  const result = [];
  if (arr.length === 1) return [arr];
  for (let i = 0; i < arr.length; i++) {
    const rest = arr.slice(0, i).concat(arr.slice(i + 1));
    const perms = permute(rest);
    for (const p of perms) {
      result.push([arr[i], ...p]);
    }
  }
  return result;
}

function arithmetic_expressions() {
  const digits = [1, 2, 3, 4, 5, 6, 7, 8, 9];
  let max_n = 0;
  let best_set = '';
  for (let a = 0; a < 9; a++) {
    for (let b = a + 1; b < 9; b++) {
      for (let c = b + 1; c < 9; c++) {
        for (let d = c + 1; d < 9; d++) {
          const set = [digits[a], digits[b], digits[c], digits[d]];
          const values = new Set();
          const perms = permute(set);
          for (const p of perms) {
            const res = evaluate(p.map(x => x * 1.0));
            for (const v of res) values.add(v);
          }
          let n = 0;
          while (values.has(n + 1)) n++;
          if (n > max_n) {
            max_n = n;
            best_set = set.join('');
          }
        }
      }
    }
  }
  return parseInt(best_set);
}

module.exports = {
  answer: () => arithmetic_expressions()
};