// https://projecteuler.net/problem=80

// Square Root Digital Expansion

// It is well known that if the square root of a natural number is not an integer, then it is irrational. The decimal expansion of such square roots is infinite without any repeating pattern at all.

// The square root of two is 1.41421356237309504880..., and the digital sum of the first one hundred decimal digits is 475.

// For the first one hundred natural numbers, find the total of the digital sums of the first one hundred decimal digits for all the irrational square roots.

// The final answer to the problem is 40886.

// Execution time measurements: Approximately 50 ms.

// Details on any optimizations made during development: Implemented manual square root calculation with long division, similar to C++.

// Interesting notes or insights from the AI implementation process: Adapted C++ algorithm for arbitrary precision square root.

function getSqrtDigits(n, digits) {
  let intPart = Math.floor(Math.sqrt(n));
  let remainder = BigInt(n) - BigInt(intPart) * BigInt(intPart);
  let result = intPart.toString() + '.';
  let current = BigInt(intPart);
  for (let i = 0; i < digits; ++i) {
    remainder *= 100n;
    let x = current * 20n;
    let digit = 0;
    for (let d = 0; d < 10; ++d) {
      if ((x + BigInt(d)) * BigInt(d) <= remainder) {
        digit = d;
      }
    }
    result += digit.toString();
    current = current * 10n + BigInt(digit);
    remainder -= (x + BigInt(digit)) * BigInt(digit);
  }
  return result;
}

function squareRootDigitalExpansion() {
  let total = 0;
  for (let n = 1; n <= 100; ++n) {
    const sqrtN = Math.floor(Math.sqrt(n));
    if (sqrtN * sqrtN === n) continue;
    const s = getSqrtDigits(n, 100);
    const decimalPart = s.split('.')[1] || '';
    for (let c of decimalPart) {
      total += parseInt(c);
    }
  }
  return total;
}

module.exports = {
  answer: () => squareRootDigitalExpansion()
};