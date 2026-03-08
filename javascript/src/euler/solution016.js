// https://projecteuler.net/problem=16

// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
// What is the sum of the digits of the number 2^1000?
//
// Answer: 1366

module.exports = {
  answer: () => {
    let num = 2n ** 1000n;
    let sum = 0;
    let numStr = num.toString();

    for (let digit of numStr) {
      sum += parseInt(digit);
    }

    return sum;
  }
};