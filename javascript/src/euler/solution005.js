// https://projecteuler.net/problem=5

// 2520 is the smallest number that can be divided by each of the numbers from
// 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the
// numbers from 1 to 20?

// Answer: 232792560

module.exports = {
  answer : () => {
    var answer = 0;
    var test = 20;
    var check = false;

    while( !check ) {
      check = true;
      for( i = 20 ; i && check ; --i ) {
        check &= (0 == (test % i));
      }
      if( !check ) {
        test += 20;
      }
    }
    return test;
  }
};

