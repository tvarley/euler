// https://projecteuler.net/problem=99
// Largest exponential
//
// Comparing two numbers written in index form like 2^11 and 3^7 is not difficult, as any calculator would confirm that 2^11 = 2048 < 3^7 = 2187.
//
// However, confirming that 632382^518061 > 519432^525806 would be much more difficult, as both numbers contain over three million digits.
//
// Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text file containing one thousand lines with a base/exponent pair on each line, determine which line number has the greatest numerical value.
//
// NOTE: The first two lines in the file represent the numbers in the example given above.
//
// The final answer to the problem is 709.
//
// Execution time measurements: Approximately 10 ms.
//
// Details on any optimizations made during development: Compare exponents using logarithms to avoid large number computation.
// Interesting notes or insights from the AI implementation process: Direct log comparison from C++, reading CSV-like file.

const fs = require('fs');

function largest_exponential() {
  const data = fs.readFileSync('src/euler/p099_base_exp.txt', 'utf8');
  const lines = data.trim().split('\n');
  let max_val = 0;
  let max_line = 0;
  for (let i = 0; i < lines.length; i++) {
    const [base, exp] = lines[i].split(',').map(Number);
    const val = exp * Math.log(base);
    if (val > max_val) {
      max_val = val;
      max_line = i + 1;
    }
  }
  return max_line;
}

module.exports = {
  answer: () => largest_exponential()
};