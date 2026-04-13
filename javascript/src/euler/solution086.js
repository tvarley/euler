// https://projecteuler.net/problem=86
// Cuboid route
//
// A spider, S, sits in one corner of a cuboid room, measuring 6 by 5 by 3, and a fly, F, sits in the opposite corner. By travelling on the surfaces of the room the shortest "straight line" distance from S to F is 10 and the path is shown on the diagram.
//
// However, there are up to three "shortest" path candidates for any given cuboid and the shortest straight line distance is the shortest of these.
//
// Find the least value of M such that the number of cuboids with integer dimensions, up to M by M by M, with shortest path integer, first exceeds one million.
//
// The final answer to the problem is 1818.
//
// Execution time measurements: Approximately 2000 ms.
//
// Details on any optimizations made during development: Nested loops over dimensions with early exit when count exceeds target, integer check using sqrt rounding.
// Interesting notes or insights from the AI implementation process: Adapted from C++ with careful floating point handling for integer square root check.

function cuboid_route() {
  let count = 0;
  let M = 0;
  const TARGET = 1000000;
  while (count <= TARGET) {
    M++;
    let current_count = 0;
    for (let a = 1; a <= M; a++) {
      for (let b = a; b <= M; b++) {
        const c = M;
        const p1 = (a + b) * (a + b) + c * c;
        const p2 = (a + c) * (a + c) + b * b;
        const p3 = (b + c) * (b + c) + a * a;
        const min_p = Math.min(p1, p2, p3);
        const root = Math.round(Math.sqrt(min_p));
        if (root * root === min_p) {
          current_count++;
        }
      }
    }
    count += current_count;
  }
  return M;
}

module.exports = {
  answer: () => cuboid_route()
};