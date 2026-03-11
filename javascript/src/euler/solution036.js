// https://projecteuler.net/problem=36

// The decimal number, 585 = 1001001001_2 (binary), is palindromic in both bases. Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2. (Please note that the palindromic number, in either base, may not include leading zeros.)
//
// Answer: 872187

module.exports = {
  answer: () => {
    function isPalindrome(s) {
      return s === s.split('').reverse().join('');
    }

    let sum = 0;
    for (let i = 1; i < 1000000; i++) {
      if (isPalindrome(i.toString()) && isPalindrome(i.toString(2))) {
        sum += i;
      }
    }
    return sum;
  }
};