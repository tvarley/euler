// https://projecteuler.net/problem=23
// Non-abundant sums

// A perfect number is a number for which the sum of its proper divisors is
// exactly equal to the number. For example, the sum of the proper divisors of
// 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
//
// A number n is called deficient if the sum of its proper divisors is less
// than n and it is called abundant if this sum exceeds n.
//
// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
// number that can be written as the sum of two abundant numbers is 24.
// By mathematical analysis, it can be shown that all integers greater than
// 28123 can be written as the sum of two abundant numbers.
// However, this upper limit cannot be reduced any further by analysis even
// though it is known that the greatest number that cannot be expressed as the
// sum of two abundant numbers is less than this limit.
//
// Find the sum of all the positive integers which cannot be written as
// the sum of two abundant numbers.

// Answer: 4179871

#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

enum HOW_PERFECT
{
  PERFECT,
  DEFICIENT,
  ABUNDENT
};

HOW_PERFECT how_perfect(int number)
{
  int sum{1};
  int i = 2;
  for (int j = number; i < j; ++i) {
    if ( number % i == 0 ) {
      sum += i;
      j = number / i;
      if (i == j)
         break;
      sum += j;
    }
  }

  if(sum == number){
    return PERFECT;
  }else if(sum > number){
    return DEFICIENT;
  }else{
    return ABUNDENT;
  }
}

long non_abundunt_sums()
{
  constexpr uint32_t max{28123};
  std::vector<int> abundents;
  for( uint32_t i{1} ; i <= max ; ++i ){
    if(how_perfect(i) == ABUNDENT) {
      abundents.push_back(i);
    }
  }
  std::array<bool, max> are_sums{};
  for(uint32_t i{}; i < abundents.size(); ++i) {
    for( uint32_t j{i} ; ; ++j ) {
      uint32_t k = abundents[i] + abundents[j];
      if( k >= max ) 
        break;
      are_sums[k] = true;
    }
  }
  long sum{};
  for (uint32_t i{}; i < max; ++i) {
    if (!are_sums[i]) {
      std::cout << i << ") - " << are_sums[i] << std::endl;
      sum += i;
    }
  }
  
  return sum;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
  std::cout << "Answer: " << non_abundunt_sums() << std::endl;
}
#endif //#if ! defined UNITTEST_MODE
