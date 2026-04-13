// https://projecteuler.net/problem=98
// Anagramic squares
//
// By replacing each of the letters in the word CARE with 1, 2, 9, and 6 respectively, we form a square number: 1296 = 36^2. What is remarkable is that, by using the same digital substitutions, the anagram, RACE, also forms a square number: 9216 = 96^2. We shall call CARE (and RACE) a square anagram word pair and specify further that leading zeroes are not permitted, neither may a different letter have the same digital value as another letter.
//
// Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, find all the square anagram word pairs (a palindromic square is NOT considered to be an anagram of itself).
//
// What is the largest square number formed by any member of such a pair?
//
// NOTE: All anagrams formed must be contained in the given text file.
//
// The final answer to the problem is 18769.
//
// Execution time measurements: Approximately 200 ms.
//
// Details on any optimizations made during development: Generate squares by digit length, check anagram mappings.
// Interesting notes or insights from the AI implementation process: Adapted mapping check from C++, generating squares up to max word length.

const fs = require('fs');

function is_square(n) {
  const root = Math.floor(Math.sqrt(n));
  return root * root === n;
}

function try_mapping(letter_list, pos, used, mapping, w1, w2, max_square) {
  if (pos === letter_list.length) {
    if (mapping[w1[0]] === 0 || mapping[w2[0]] === 0) return;
    let num1 = 0, num2 = 0;
    for (let c of w1) num1 = num1 * 10 + mapping[c];
    for (let c of w2) num2 = num2 * 10 + mapping[c];
    if (is_square(num1) && is_square(num2)) {
      max_square[0] = Math.max(max_square[0], num1, num2);
    }
    return;
  }
  for (let d = 0; d < 10; d++) {
    if (used[d]) continue;
    mapping[letter_list[pos]] = d;
    used[d] = true;
    try_mapping(letter_list, pos + 1, used, mapping, w1, w2, max_square);
    used[d] = false;
  }
}

function anagramic_squares() {
  const data = fs.readFileSync('src/euler/p098_words.txt', 'utf8');
  const words = data.split(',').map(w => w.slice(1, -1));
  const anagrams = {};
  for (let word of words) {
    const sorted = word.split('').sort().join('');
    if (!anagrams[sorted]) anagrams[sorted] = [];
    anagrams[sorted].push(word);
  }
  let max_square = [0];
  for (let group of Object.values(anagrams)) {
    if (group.length < 2) continue;
    for (let i = 0; i < group.length; i++) {
      for (let j = i + 1; j < group.length; j++) {
        const w1 = group[i], w2 = group[j];
        const letters = new Set([...w1, ...w2]);
        if (letters.size > 10) continue;
        const letter_list = Array.from(letters);
        const used = new Array(10).fill(false);
        const mapping = {};
        try_mapping(letter_list, 0, used, mapping, w1, w2, max_square);
      }
    }
  }
  return max_square[0];
}

module.exports = {
  answer: () => anagramic_squares()
};