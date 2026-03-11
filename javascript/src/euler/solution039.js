// https://projecteuler.net/problem=39

// If p is the perimeter of a right angle triangle with integral length sides, {a, b, c}, there are exactly three solutions for p = 120. {20,48,52}, {24,45,51}, {30,40,50} For which value of p ≤ 1000, is the number of solutions maximised?
//
// Answer: 840

module.exports = {
  answer: () => {
    let maxCount = 0, maxP = 0;
    for (let p = 1; p <= 1000; p++) {
      let count = 0;
      for (let a = 1; a < p; a++) {
        for (let b = a; b < p - a; b++) {
          const c = p - a - b;
          if (c < b) continue;
          if (a * a + b * b === c * c) count++;
        }
      }
      if (count > maxCount) {
        maxCount = count;
        maxP = p;
      }
    }
    return maxP;
  }
};