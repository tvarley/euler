// https://projecteuler.net/problem=16
// Power digit sum

// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
//
// What is the sum of the digits of the number 2^1000?

// Answer: 1366

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int power_digit_sum(size_t max)
{
  std::vector<int> numbers;
  numbers.push_back(1);

  std::cout << std::endl;

  for (size_t i = 0; i < max; i++) {
    int carry = 0;

    std::for_each(numbers.begin(),numbers.end(),[&carry](int&  n){
      n *= 2;
      n += carry;
      carry = ( n >= 10 )?1:0;
      n -= (carry * 10);
    });

    if( 0 != carry ){
      numbers.push_back(carry);
    }
  }

  int total = 0;

  for (auto itr = numbers.rbegin() ; itr != numbers.rend() ; itr++) {
    total += *itr;
  }

  return total;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
  std::cout << "Answer: " << power_digit_sum(15) << std::endl;
  std::cout << "Answer: " << power_digit_sum(1000) << std::endl;
  return 0;
}
#endif // #if ! defined UNITTEST_MODE
