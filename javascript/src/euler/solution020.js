// https://projecteuler.net/problem=20

// n! means n × (n − 1) × ... × 3 × 2 × 1
// For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
// and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
// Find the sum of the digits in the number 100!
//
// Answer: 648

function factorial(n) {
  let result = 1n;
  for (let i = 2n; i <= n; i++) {
    result *= i;
  }
  return result;
}

module.exports = {
  answer: () => {
    const fact = factorial(100n);
    const factStr = fact.toString();
    let sum = 0;

    for (let digit of factStr) {
      sum += parseInt(digit);
    }

    return sum;
  }
};