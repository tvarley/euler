// https://projecteuler.net/problem=5

// 2520 is the smallest number that can be divided by each of the numbers from
// 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the
// numbers from 1 to 20?

// Answer: 232792560

#include <iostream>
#include <cstdint>

int prob005_brute_force(int max)
{
  uint32_t answer = 0;
  uint32_t test = max;
  bool check = false;
  while (!check) {
    check = true;
    for( uint32_t i = max ; i && check ; --i){
      check &= (0 == (test%i));
    }
    if( !check ){
      test += 20;
    }
  }
  answer = test;
  return answer;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
  std::cout << "Answer: " << prob005_brute_force(20) << std::endl;
}
#endif
