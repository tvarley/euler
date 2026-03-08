// https://projecteuler.net/problem=30

// Surprisingly there are only three numbers that can be written as the sum
// of fourth powers of their digits:
// 1634 = 1^4 + 6^4 + 3^4 + 4^4
// 8208 = 8^4 + 2^4 + 0^4 + 8^4
// 9474 = 9^4 + 4^4 + 7^4 + 4^4
// As 1 = 1^4 is not a sum it is not included.
// The sum of these numbers is 1634 + 8208 + 9474 = 19316.
// Find the sum of all the numbers that can be written as the sum of fifth
// powers of their digits.
//
// Answer: 443839

module.exports = {
  answer: () => {
    // Upper bound: a 7-digit number max is 9999999, and 7 * 9^5 = 413343 (6 digits)
    // So 6 digits is sufficient: 6 * 9^5 = 354294
    const limit = 354294;
    let sum = 0;

    for (let n = 2; n <= limit; n++) {
      let digitSum = 0;
      let temp = n;
      while (temp > 0) {
        const digit = temp % 10;
        digitSum += digit ** 5;
        temp = Math.floor(temp / 10);
      }
      if (digitSum === n) {
        sum += n;
      }
    }

    return sum;
  }
};
