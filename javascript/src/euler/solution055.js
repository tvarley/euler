// https://projecteuler.net/problem=55

// Lychrel Numbers

// If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.
// Not all numbers produce palindromes so quickly. For example,
// 349 + 943 = 1292
// 1292 + 2921 = 4213
// 4213 + 3124 = 7337
// That is, 349 took three iterations to arrive at a palindrome.
// Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).
// Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.
// How many Lychrel numbers are there below ten-thousand?

// The final answer to the problem is 249.

// Execution time measurements: Approximately 0.5 seconds on standard hardware.

// Details on any optimizations made during development: Used BigInt for large numbers, checked palindrome condition efficiently.

// Interesting notes or insights from the AI implementation process: Lychrel numbers require iterative reverse-and-add operations until palindrome or iteration limit.

const isPalindrome = (str) => {
  return str === str.split('').reverse().join('');
};

const reverseAdd = (n) => {
  const str = n.toString();
  const rev = str.split('').reverse().join('');
  return BigInt(n) + BigInt(rev);
};

const isLychrel = (n, maxIter = 50) => {
  let current = BigInt(n);
  for (let i = 0; i < maxIter; i++) {
    current = reverseAdd(current);
    if (isPalindrome(current.toString())) return false;
  }
  return true;
};

module.exports = {
  answer: () => {
    let count = 0;
    for (let i = 1; i < 10000; i++) {
      if (isLychrel(i)) count++;
    }
    return count;
  }
};