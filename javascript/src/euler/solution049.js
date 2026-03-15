// https://projecteuler.net/problem=49

// The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
// There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
// What 12-digit number do you form by concatenating the three terms in this sequence?

// Answer: 296962999629

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
    const primes = [];
    for (let i = 1000; i < 10000; i++) {
      if (isPrime(i)) primes.push(i);
    }
    const groups = {};
    for (const p of primes) {
      const key = p.toString().split('').sort().join('');
      if (!groups[key]) groups[key] = [];
      groups[key].push(p);
    }
    for (const group of Object.values(groups)) {
      if (group.length >= 3) {
        group.sort((a, b) => a - b);
        for (let i = 0; i < group.length - 2; i++) {
          for (let j = i + 1; j < group.length - 1; j++) {
            for (let k = j + 1; k < group.length; k++) {
              if (group[j] - group[i] === group[k] - group[j] && group[i] !== 1487) {
                return parseInt(`${group[i]}${group[j]}${group[k]}`);
              }
            }
          }
        }
      }
    }
  }
};