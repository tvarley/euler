// https://projecteuler.net/problem=15

// Starting in the top left corner of a 2×2 grid, and only being able to move
// to the right and down, there are exactly 6 routes to the bottom right corner.
// How many such routes are there through a 20×20 grid?
//
// Answer: 137846528820

function factorial(n) {
  let result = 1n;
  for (let i = 2n; i <= n; i++) {
    result *= i;
  }
  return result;
}

module.exports = {
  answer: () => {
    // C(40, 20) = 40! / (20! * 20!)
    const n = 40n;
    const k = 20n;
    return factorial(n) / (factorial(k) * factorial(n - k));
  }
};