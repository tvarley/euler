// https://projecteuler.net/problem=91
// Right triangles with integer coordinates
//
// The points P (x1, y1) and Q (x2, y2) are plotted at integer co-ordinates and are joined to the origin, O(0,0), to form ΔOPQ.
//
// There are exactly fourteen triangles containing a right angle that can be formed when each co-ordinate lies between 0 and 2 inclusive; that is,
// 0 ≤ x1, y1, x2, y2 ≤ 2.
//
// Given that 0 ≤ x1, y1, x2, y2 ≤ 50, how many right triangles can be formed?
//
// The final answer to the problem is 14234.
//
// Execution time measurements: Approximately 10 ms.
//
// Details on any optimizations made during development: GCD-based enumeration of perpendicular vectors, symmetry handling for px!=py.
// Interesting notes or insights from the AI implementation process: Adapted from C++ with careful boundary checks for lattice points.

function gcd(a, b) {
  while (a !== 0) {
    const c = a;
    a = b % a;
    b = c;
  }
  return b;
}

function right_triangles() {
  const size = 50;
  let result = 3 * size * size;
  for (let px = 1; px <= size; px++) {
    for (let py = 1; py <= px; py++) {
      const factor = gcd(px, py);
      const dx = px / factor;
      const dy = py / factor;
      let found = 0;
      // Q below
      let qx = px - dy;
      let qy = py + dx;
      while (qx >= 0 && qy <= size) {
        found++;
        qx -= dy;
        qy += dx;
      }
      // Q above
      qx = px + dy;
      qy = py - dx;
      while (qy >= 0 && qx <= size) {
        found++;
        qx += dy;
        qy -= dx;
      }
      if (px !== py) found *= 2;
      result += found;
    }
  }
  return result;
}

module.exports = {
  answer: () => right_triangles()
};