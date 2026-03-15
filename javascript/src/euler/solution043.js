// https://projecteuler.net/problem=43

// The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.
// Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
// d2 d3 d4=406 is divisible by 2
// d3 d4 d5=063 is divisible by 3
// d4 d5 d6=635 is divisible by 5
// d5 d6 d7=357 is divisible by 7
// d6 d7 d8=572 is divisible by 11
// d7 d8 d9=728 is divisible by 13
// d8 d9 d10=289 is divisible by 17
// Find the sum of all 0 to 9 pandigital numbers with this property.

// Answer: 16695334890

// Optimization: Instead of generating all 10! permutations (3.6M) and checking each,
// use backtracking to build the number digit-by-digit. Check substring divisibility
// constraints incrementally as digits are added, pruning invalid branches early.
// This reduces time complexity from O(10!) to effectively O(10^k) where k<<10 due to constraints.

const backtrack = (current, used, sum, divs) => {
  const len = current.length;
  if (len === 10) {
    const num = current[7] * 100 + current[8] * 10 + current[9];
    if (num % 17 === 0 && current[0] !== 0) sum[0] += parseInt(current.join(''));
    return;
  }
  // Check constraint if applicable (for len 4-9)
  if (len >= 4 && len < 10) {
    const num = current[len - 3] * 100 + current[len - 2] * 10 + current[len - 1];
    if (num % divs[len - 4] !== 0) return;
  }
  for (let d = 0; d <= 9; d++) {
    if (!used.has(d)) {
      used.add(d);
      current.push(d);
      backtrack(current, used, sum, divs);
      current.pop();
      used.delete(d);
    }
  }
};

module.exports = {
  answer: () => {
    const sum = [0];
    const divs = [2, 3, 5, 7, 11, 13, 17]; // for positions 3,4,5,6,7,8,9 (len-3 index)
    backtrack([], new Set(), sum, divs);
    return sum[0];
  }
};