// https://projecteuler.net/problem=21

// Let d(n) be defined as the sum of proper divisors of n (numbers less than
// n which divide evenly into n).
// If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair
// and each of a and b are called amicable numbers.
// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22,
// 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are
// 1, 2, 4, 71 and 142; so d(284) = 220.
// Evaluate the sum of all the amicable numbers under 10000.
//
// Answer: 31626

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

module.exports = {
  answer: () => {
    const divisorSums = new Array(10000);
    for (let i = 1; i < 10000; i++) {
      divisorSums[i] = sumOfDivisors(i);
    }

    let sum = 0;
    for (let a = 1; a < 10000; a++) {
      const b = divisorSums[a];
      if (b < 10000 && b !== a && divisorSums[b] === a) {
        sum += a;
      }
    }

    return sum;
  }
};