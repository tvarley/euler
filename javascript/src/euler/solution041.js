// https://projecteuler.net/problem=41

// We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

// What is the largest n-digit pandigital prime that exists?

// Answer: 7652413

const isPrime = (n) => {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 === 0 || n % 3 === 0) return false;
  for (let i = 5; i * i <= n; i += 6) {
    if (n % i === 0 || n % (i + 2) === 0) return false;
  }
  return true;
};

const getPermutations = (arr) => {
  if (arr.length === 0) return [[]];
  const result = [];
  for (let i = 0; i < arr.length; i++) {
    const rest = arr.slice(0, i).concat(arr.slice(i + 1));
    const perms = getPermutations(rest);
    for (const perm of perms) {
      result.push([arr[i], ...perm]);
    }
  }
  return result;
};

module.exports = {
  answer: () => {
    const digits = [7,6,5,4,3,2,1];
    const perms = getPermutations(digits);
    let maxPrime = 0;
    for (const perm of perms) {
      const num = parseInt(perm.join(''));
      if (isPrime(num)) {
        maxPrime = Math.max(maxPrime, num);
      }
    }
    return maxPrime;
  }
};