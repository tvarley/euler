// https://projecteuler.net/problem=3

// The prime factors of 13195 are 5, 7, 13 and 29.
//
// What is the largest prime factor of the number 600851475143?
//
// Answer: 6857

module.exports = {
  answer : () => {
    answer = 2
    point = 3
    divisor = 600851475143

    while( (divisor % 2) == 0) { divisor /= 2; }

    while(divisor != 1) {
      while ((divisor % point) == 0) {
        answer = point;
        divisor /= point;
      }
      point += 2;
    }
    return answer;
  }
};
