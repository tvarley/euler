// https://projecteuler.net/problem=9

// A Pythagorean triplet is a set of three natural numbers, a < b < c,
// for which a² + b² = c².
// For example, 3² + 4² = 9 + 16 = 25 = 5².
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.
//
// Answer: 31875000

module.exports = {
  answer: () => {
    for (let a = 1; a < 1000; a++) {
      for (let b = a + 1; b < 1000 - a; b++) {
        let c = 1000 - a - b;
        if (a * a + b * b === c * c) {
          return a * b * c;
        }
      }
    }
  }
};