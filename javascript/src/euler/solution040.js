// https://projecteuler.net/problem=40

// An irrational decimal fraction is created by concatenating the positive integers: 0.123456789101112131415161718192021⋯ It can be seen that the 12th digit of the fractional part is 1. If d_n represents the nth digit of the fractional part, find the value of the following expression. d_1 × d_10 × d_100 × d_1000 × d_10000 × d_100000 × d_1000000
//
// Answer: 210

module.exports = {
  answer: () => {
    let s = '';
    let i = 1;
    while (s.length < 1000000) {
      s += i.toString();
      i++;
    }
    return parseInt(s[0]) * parseInt(s[9]) * parseInt(s[99]) * parseInt(s[999]) * parseInt(s[9999]) * parseInt(s[99999]) * parseInt(s[999999]);
  }
};