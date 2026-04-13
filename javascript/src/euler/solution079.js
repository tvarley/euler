// https://projecteuler.net/problem=79

// Passcode Derivation

// A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

// The text file, keylog.txt, contains fifty successful login attempts.

// Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.

// The final answer to the problem is 73162890.

// Execution time measurements: Approximately 10 ms.

// Details on any optimizations made during development: Used topological sort on digit graph, similar to C++.

// Interesting notes or insights from the AI implementation process: Adapted C++ graph and indegree approach.

const fs = require('fs');

function passcodeDerivation() {
  const data = fs.readFileSync('src/euler/keylog.txt', 'utf8').split('\n').filter(line => line.length === 3);
  const graph = Array.from({length: 10}, () => new Set());
  const indegree = new Array(10).fill(0);
  const digits = new Set();
  for (const log of data) {
    const a = parseInt(log[0]), b = parseInt(log[1]), c = parseInt(log[2]);
    digits.add(a);
    digits.add(b);
    digits.add(c);
    if (!graph[a].has(b)) {
      graph[a].add(b);
      indegree[b]++;
    }
    if (!graph[b].has(c)) {
      graph[b].add(c);
      indegree[c]++;
    }
  }
  const queue = [];
  for (const d of digits) {
    if (indegree[d] === 0) queue.push(d);
  }
  let passcode = '';
  while (queue.length > 0) {
    const d = queue.shift();
    passcode += d;
    for (const next of graph[d]) {
      indegree[next]--;
      if (indegree[next] === 0) queue.push(next);
    }
  }
  return passcode;
}

module.exports = {
  answer: () => passcodeDerivation()
};