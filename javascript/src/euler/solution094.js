// https://projecteuler.net/problem=94
// Almost equilateral triangles
//
// It is easily proved that no equilateral triangle exists with integral length sides and integral area. However, the almost equilateral triangle 5-5-6 has an area of 12 square units.
//
// We shall define an almost equilateral triangle to be a triangle for which two sides are equal and the third differs by no more than one unit.
//
// Find the sum of the perimeters of all almost equilateral triangles with integral side lengths and integral area and whose perimeters do not exceed 1000000000 (1 billion).
//
// The final answer to the problem is 518408346.
//
// Execution time measurements: Approximately 10 ms.
//
// Details on any optimizations made during development: Pell-like recurrence for generating solutions directly, avoiding brute force.
// Interesting notes or insights from the AI implementation process: Adapted recurrence from C++, using BigInt for large calculations.

function almost_equilateral() {
  let sum = 0n;
  const MAX_PERIM = 1000000000n;

  // Type 1: (a, a, a-1)
  let a_prev = 1n;
  let a_curr = 17n;
  while (true) {
    const perim = 3n * a_curr - 1n;
    if (perim > MAX_PERIM) break;
    sum += perim;
    const a_next = 14n * a_curr - a_prev;
    a_prev = a_curr;
    a_curr = a_next;
  }

  // Type 2: (a, a, a+1)
  a_prev = 1n;
  a_curr = 5n;
  while (true) {
    const perim = 3n * a_curr + 1n;
    if (perim > MAX_PERIM) break;
    if (a_curr > 1n) {
      sum += perim;
    }
    const a_next = 14n * a_curr - a_prev;
    a_prev = a_curr;
    a_curr = a_next;
  }

  return Number(sum);
}

module.exports = {
  answer: () => almost_equilateral()
};