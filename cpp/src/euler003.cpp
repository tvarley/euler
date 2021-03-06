// https://projecteuler.net/problem=3

// The prime factors of 13195 are 5, 7, 13 and 29.
//
// What is the largest prime factor of the number 600851475143

// Answer: 6857

#include <iostream>
#include <cstdint>

using namespace std;

uint64_t largest_prime_factor(uint64_t number)
{
  uint64_t answer = 1;
  uint64_t point = 3;
  uint64_t divisor = number;

  while (divisor % 2 == 0) {
    answer = 2;
    divisor = divisor/2;
  }

  while (divisor != 1) {
      while (divisor % point == 0) {
        answer = point;
        divisor = divisor/point;
      }
      point += 2;
  }

  return answer;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
  std::cout << "Answer: " << largest_prime_factor(600851475143) << std::endl;
}
#endif // #if ! defined UNITTEST_MODE
