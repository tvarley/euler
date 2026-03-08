// https://projecteuler.net/problem=26

// A unit fraction contains 1 in the numerator. The decimal value of the unit
// fractions with denominators 2 to 10 are given:
// 1/2  = 0.5
// 1/3  = 0.(3)
// 1/4  = 0.25
// 1/5  = 0.2
// 1/6  = 0.1(6)
// 1/7  = 0.(142857)
// 1/8  = 0.125
// 1/9  = 0.(1)
// 1/10 = 0.1
// Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can
// be seen that 1/7 has a 6-digit recurring cycle.
// Find the value of d < 1000 for which 1/d contains the longest recurring
// cycle in its decimal fraction part.
//
// Answer: 983

function cycleLength(d) {
  const remainders = new Map();
  let remainder = 1;
  let position = 0;

  while (remainder !== 0) {
    if (remainders.has(remainder)) {
      return position - remainders.get(remainder);
    }
    remainders.set(remainder, position);
    remainder = (remainder * 10) % d;
    position++;
  }

  return 0;
}

module.exports = {
  answer: () => {
    let maxCycle = 0;
    let result = 0;

    for (let d = 2; d < 1000; d++) {
      const len = cycleLength(d);
      if (len > maxCycle) {
        maxCycle = len;
        result = d;
      }
    }

    return result;
  }
};
