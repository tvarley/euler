// https://projecteuler.net/problem=34

// 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145. Find the sum of all numbers which are equal to the sum of the factorial of their digits. Note: As 1! = 1 and 2! = 2 are not sums they are not included.
//
// Answer: 40730

module.exports = {
  answer: () => {
    const fact = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880];
    function sumFactDig(n) {
      let sum = 0;
      while (n > 0) {
        sum += fact[n % 10];
        n = Math.floor(n / 10);
      }
      return sum;
    }
    let total = 0;
    for (let i = 10; i < 10000000; i++) {
      if (sumFactDig(i) === i) total += i;
    }
    return total;
  }
};