// https://projecteuler.net/problem=32

// We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital. The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital. Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital. HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
//
// Answer: 45228

module.exports = {
  answer: () => {
    function isPandigital(str) {
      if (str.length !== 9 || str.includes('0')) return false;
      return new Set(str).size === 9;
    }

    const products = new Set();
    for (let a = 1; a < 10000; a++) {
      for (let b = 1; a * b < 10000 && b <= a; b++) {
        const c = a * b;
        const concat = a.toString() + b.toString() + c.toString();
        if (isPandigital(concat)) {
          products.add(c);
        }
      }
    }
    return Array.from(products).reduce((sum, p) => sum + p, 0);
  }
};