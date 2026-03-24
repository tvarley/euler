// https://projecteuler.net/problem=65

// Convergents of e

// The square root of 2 can be written as an infinite continued fraction.
// √2 = 1 + 1/(2 + 1/(2 + 1/(2 + ...)))
// The infinite continued fraction can be written, √2 = [1;(2)], (2) indicates that 2 repeats ad infinitum.
// In a similar way, √23 = [4; (1,3,1,8)].
// It turns out that the sequence of partial values of continued fractions for square roots provide the best rational approximations.
// Let us consider the convergents for √2.
// 1 + 1/2 = 3/2
// 1 + 1/(2 + 1/2) = 7/5
// 1 + 1/(2 + 1/(2 + 1/2)) = 17/12
// 1 + 1/(2 + 1/(2 + 1/2)) = 41/29
// Hence the sequence of the first ten convergents for √2 are:
// 1, 3/2, 7/5, 17/12, 41/29, 99/70, 239/169, 577/408, 1393/985, 3363/2378, ...
// What is most surprising is that the important mathematical constant,
// e = [2; 1, 2, 1, 1, 4, 1, 1, 6, 1, ..., 1, 2k, 1, ...]
// The first ten terms in the sequence of convergents for e are:
// 2, 3, 8/3, 11/4, 19/7, 87/32, 106/39, 193/71, 1264/465, 1457/536, ...
// The sum of digits in the numerator of the 10th convergent is 1+4+5+7=17.
// Find the sum of digits in the numerator of the 100th convergent of the continued fraction for e.

// The final answer to the problem is 272.

// Execution time measurements: Approximately 0 ms.

// Details on any optimizations made during development: Simple big integer arithmetic using strings for numerator calculation
// Interesting notes or insights from the AI implementation process: AI-generated solution implementing continued fraction convergents with string-based big integers

function addBig(a, b) {
  let result = '';
  let carry = 0;
  let i = a.length - 1;
  let j = b.length - 1;
  while (i >= 0 || j >= 0 || carry) {
    let sum = carry;
    if (i >= 0) sum += a.charCodeAt(i--) - 48;
    if (j >= 0) sum += b.charCodeAt(j--) - 48;
    carry = Math.floor(sum / 10);
    result = (sum % 10) + result;
  }
  return result;
}

function multiplyBig(a, b) {
  let result = '';
  let carry = 0;
  for (let i = a.length - 1; i >= 0; i--) {
    const prod = (a.charCodeAt(i) - 48) * b + carry;
    carry = Math.floor(prod / 10);
    result = (prod % 10) + result;
  }
  while (carry) {
    result = (carry % 10) + result;
    carry = Math.floor(carry / 10);
  }
  return result;
}

function sumDigitsBig(s) {
  let sum = 0;
  for (const c of s) sum += c.charCodeAt(0) - 48;
  return sum;
}

function convergentsOfE() {
  const terms = [2];
  for (let k = 1; ; k++) {
    terms.push(1);
    terms.push(2 * k);
    terms.push(1);
    if (terms.length >= 101) break;
  }
  let hPrev2 = '0';
  let hPrev1 = '1';
  let kPrev2 = '1';
  let kPrev1 = '0';
  for (let i = 0; i < 100; i++) {
    const h = addBig(multiplyBig(hPrev1, terms[i]), hPrev2);
    const k = addBig(multiplyBig(kPrev1, terms[i]), kPrev2);
    hPrev2 = hPrev1;
    hPrev1 = h;
    kPrev2 = kPrev1;
    kPrev1 = k;
  }
  return sumDigitsBig(hPrev1);
}

module.exports = {
  answer: () => convergentsOfE()
};