// https://projecteuler.net/problem=33

// The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s. We shall consider fractions like, 30/50 = 3/5, to be trivial examples. There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator. If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
//
// Answer: 100

module.exports = {
  answer: () => {
    function gcd(a, b) {
      return b === 0 ? a : gcd(b, a % b);
    }

    let num = 1, den = 1;
    for (let a = 10; a < 100; a++) {
      for (let b = a + 1; b < 100; b++) {
        const sa = a.toString(), sb = b.toString();
        if (sa[1] === sb[1] && sa[1] !== '0') {
          const x = parseInt(sa[0]), y = parseInt(sb[0]);
          if (x * b === y * a) {
            num *= x;
            den *= y;
          }
        }
        if (sa[0] === sb[1] && sa[0] !== '0') {
          const x = parseInt(sa[1]), y = parseInt(sb[0]);
          if (x * b === y * a) {
            num *= x;
            den *= y;
          }
        }
        if (sa[1] === sb[0] && sa[1] !== '0') {
          const x = parseInt(sa[0]), y = parseInt(sb[1]);
          if (x * b === y * a) {
            num *= x;
            den *= y;
          }
        }
      }
    }
    return den / gcd(num, den);
  }
};