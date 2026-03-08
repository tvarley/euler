// https://projecteuler.net/problem=14

// The following iterative sequence is defined for the set of positive integers:
// n → n/2 (n is even)
// n → 3n + 1 (n is odd)
// Using the rule above and starting with 13, we generate the following sequence:
// 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
// It can be seen that this sequence (starting at 13 and finishing at 1) contains
// 10 terms. Although it has not been proved yet (Collatz Problem), it is thought
// that all starting numbers finish at 1.
// Which starting number, under one million, produces the longest chain?
//
// Answer: 837799

const memo = new Map();

function collatzLength(n) {
  if (n === 1) return 1;
  if (memo.has(n)) return memo.get(n);

  let length;
  if (n % 2 === 0) {
    length = 1 + collatzLength(n / 2);
  } else {
    length = 1 + collatzLength(3 * n + 1);
  }

  memo.set(n, length);
  return length;
}

module.exports = {
  answer: () => {
    let maxLength = 0;
    let maxNumber = 0;

    for (let i = 1; i < 1000000; i++) {
      const length = collatzLength(i);
      if (length > maxLength) {
        maxLength = length;
        maxNumber = i;
      }
    }

    return maxNumber;
  }
};