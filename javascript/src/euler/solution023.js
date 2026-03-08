// https://projecteuler.net/problem=23

// A perfect number is a number for which the sum of its proper divisors is
// exactly equal to the number. For example, the sum of the divisors of 28
// would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
// A number n is called deficient if the sum of its proper divisors is less
// than n and it is called abundant if this sum exceeds n.
// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the
// smallest number that can be written as the sum of two abundant numbers is
// 24. By mathematical analysis, it can be shown that all integers greater
// than 28123 can be written as the sum of two abundant numbers. However,
// this upper limit cannot be reduced any further by analysis even though
// it is known that the greatest number that cannot be expressed as the sum
// of two abundant numbers is less than this limit.
// Find the sum of all the positive integers which cannot be written as the
// sum of two abundant numbers.
//
// Answer: 4179871

function sumOfDivisors(n) {
  let sum = 1; // 1 is always a divisor
  for (let i = 2; i * i <= n; i++) {
    if (n % i === 0) {
      sum += i;
      if (i !== n / i) sum += n / i;
    }
  }
  return sum;
}

function isAbundant(n) {
  return sumOfDivisors(n) > n;
}

module.exports = {
  answer: () => {
    const limit = 28123;
    const abundant = [];

    // Find all abundant numbers up to limit
    for (let i = 12; i <= limit; i++) {
      if (isAbundant(i)) {
        abundant.push(i);
      }
    }

    // Create boolean array for sums of two abundant numbers
    const canBeSum = new Array(limit + 1).fill(false);

    // Mark all sums of two abundant numbers
    for (let i = 0; i < abundant.length; i++) {
      for (let j = i; j < abundant.length; j++) {
        const sum = abundant[i] + abundant[j];
        if (sum <= limit) {
          canBeSum[sum] = true;
        }
      }
    }

    // Sum all numbers that cannot be written as sum of two abundant numbers
    let total = 0;
    for (let i = 1; i <= limit; i++) {
      if (!canBeSum[i]) {
        total += i;
      }
    }

    return total;
  }
};