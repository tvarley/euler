// https://projecteuler.net/problem=90
// Cube digit pairs
//
// Each of the six faces on a cube has a different digit (0 to 9) written on it; the same is done to a second cube. By placing the two cubes side-by-side in different positions we can form a variety of 2-digit numbers.
//
// For example, the square number 01 is a different number than 10. Note also that 06 and 60 are both valid, since they use the same digits.
//
// In fact, by carefully choosing the digits on both cubes it is possible to display all of the square numbers below one-hundred: 01, 04, 09, 16, 25, 36, 49, 64, and 81.
//
// For example, one way this can be achieved is by placing {0, 5, 6, 7, 8, 9} on one cube and {1, 2, 3, 4, 6, 7} on the other cube.
//
// This arrangement lets us form all nine 2-digit square numbers: 01, 04, 06, 09, 16, 25, 36, 49, 64, 81.
//
// However, there is one small complication: we are allowed to rotate the cubes, so the arrangement {0, 5, 6, 7, 8, 9} on one cube could be rotated to become {0, 1, 2, 3, 4, 5}, which would allow us to form 10 and other numbers. But since we are only interested in the squares, and 10 is not a square, this does not matter in this case.
//
// Find the number of distinct arrangements of the two cubes (considering rotations as the same arrangement) that allow for all of the square numbers to be displayed.
//
// The final answer to the problem is 1217.
//
// Execution time measurements: Approximately 100 ms.
//
// Details on any optimizations made during development: Bitmask enumeration for combinations, efficient digit checking with 6/9 interchangeability.
// Interesting notes or insights from the AI implementation process: Adapted bitmask approach from C++, generating all C(10,6) combinations.

function has_digit(mask, d) {
  if (mask & (1 << d)) return true;
  if (d === 6 && (mask & (1 << 9))) return true;
  if (d === 9 && (mask & (1 << 6))) return true;
  return false;
}

function can_form_square(mask_a, mask_b, sq) {
  const d1 = Math.floor(sq / 10), d2 = sq % 10;
  const a1 = has_digit(mask_a, d1), a2 = has_digit(mask_a, d2);
  const b1 = has_digit(mask_b, d1), b2 = has_digit(mask_b, d2);
  return (a1 && b2) || (a2 && b1);
}

function cube_digit_pairs() {
  const squares = [1, 4, 9, 16, 25, 36, 49, 64, 81];
  const cubes = [];
  for (let i = 0; i < (1 << 10); i++) {
    let count = 0;
    for (let j = 0; j < 10; j++) {
      if (i & (1 << j)) count++;
    }
    if (count === 6) cubes.push(i);
  }
  let count = 0;
  const n = cubes.length;
  for (let i = 0; i < n; i++) {
    const ma = cubes[i];
    for (let j = i + 1; j < n; j++) {
      const mb = cubes[j];
      let ok = true;
      for (const sq of squares) {
        if (!can_form_square(ma, mb, sq)) {
          ok = false;
          break;
        }
      }
      if (ok) count++;
    }
  }
  return count;
}

module.exports = {
  answer: () => cube_digit_pairs()
};