// https://projecteuler.net/problem=17

// If the numbers 1 to 5 are written out in words: one, two, three, four, five,
// then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
// If all the numbers from 1 to 1000 (one thousand) inclusive were written out
// in words, how many letters would be used?
//
// Answer: 21124

const ones = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"];
const teens = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"];
const tens = ["", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"];

function numberToWords(n) {
  if (n === 1000) return "one thousand";

  let result = "";

  if (n >= 100) {
    result += ones[Math.floor(n / 100)] + " hundred";
    n %= 100;
    if (n > 0) result += " and ";
  }

  if (n >= 20) {
    result += tens[Math.floor(n / 10)];
    n %= 10;
    if (n > 0) result += "-" + ones[n];
  } else if (n >= 10) {
    result += teens[n - 10];
  } else if (n > 0) {
    result += ones[n];
  }

  return result;
}

module.exports = {
  answer: () => {
    let total = 0;
    for (let i = 1; i <= 1000; i++) {
      const words = numberToWords(i).replace(/[-\s]/g, "");
      total += words.length;
    }
    return total;
  }
};