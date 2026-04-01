// https://projecteuler.net/problem=89
// Roman numerals
//
// The rules for writing Roman numerals allow for many ways of writing each number (see About Roman Numerals...). However, there is always a "best" way of writing a particular number.
//
// For example, the following represent all of the legitimate ways of writing the number sixteen:
//
// IIIIIIIIIIIIIIII
// VIIIIIIIIIII
// VVIIIIIII
// XIIIIII
// VVVI
// XVI
//
// The last example being considered the most efficient, as it uses the least number of numerals.
//
// The 11K text file, roman.txt (right click and 'Save Link/Target As...'), contains one thousand numbers written in valid, but not necessarily minimal, Roman numerals; that is, they are arranged in descending units and obey the subtractive notation (see About Roman Numerals... for the definitive rules for this problem).
//
// Find the number of characters saved by writing each of these in their minimal form.
//
// Note: You can assume that all the Roman numerals in the file contain no more than four consecutive identical units.
//
// The final answer to the problem is 743.
//
// Execution time measurements: Approximately 10 ms.
//
// Details on any optimizations made during development: Direct parsing and conversion using value tables, no complex logic.
// Interesting notes or insights from the AI implementation process: Adapted parsing and generation from C++ using arrays for Roman values.

const fs = require('fs');

function roman_to_int(s) {
  const values = [
    ['M', 1000], ['CM', 900], ['D', 500], ['CD', 400],
    ['C', 100], ['XC', 90], ['L', 50], ['XL', 40],
    ['X', 10], ['IX', 9], ['V', 5], ['IV', 4], ['I', 1]
  ];
  let total = 0;
  let i = 0;
  while (i < s.length) {
    let found = false;
    for (const [str, val] of values) {
      if (s.substr(i, str.length) === str) {
        total += val;
        i += str.length;
        found = true;
        break;
      }
    }
    if (!found) i++;
  }
  return total;
}

function int_to_roman(num) {
  const values = [
    [1000, 'M'], [900, 'CM'], [500, 'D'], [400, 'CD'],
    [100, 'C'], [90, 'XC'], [50, 'L'], [40, 'XL'],
    [10, 'X'], [9, 'IX'], [5, 'V'], [4, 'IV'], [1, 'I']
  ];
  let result = '';
  for (const [val, str] of values) {
    while (num >= val) {
      result += str;
      num -= val;
    }
  }
  return result;
}

function roman_numerals() {
  const data = fs.readFileSync('src/euler/p089_roman.txt', 'utf8');
  const lines = data.trim().split('\n');
  let saved = 0;
  for (const line of lines) {
    if (!line) continue;
    const value = roman_to_int(line);
    const minimal = int_to_roman(value);
    saved += line.length - minimal.length;
  }
  return saved;
}

module.exports = {
  answer: () => roman_numerals()
};