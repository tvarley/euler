// https://projecteuler.net/problem=20
// Factorial digit sum

// n! means n × (n − 1) × ... × 3 × 2 × 1
//
// For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
// and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
//
// Find the sum of the digits in the number 100!

// Answer: 648

#include <iostream>
#include <chrono>

static const int big_size = 500;

int factorial_digit_sum(int fme)
{
  int digits[big_size] = {0};
  digits[0] =1;

  int sum = 0;

  for (size_t factor = 2; factor < fme; factor++) {
    int carry = 0;
    for (size_t j = 0; j < big_size; j++) {
      int x = digits[j] * factor + carry;
      carry = 0;
      sum = x;
      if( x > 9){
        sum = x % 10;
        carry = x / 10;
      }
      digits[j]=sum;
    }
  }
  int ret = 0;
  for (size_t i = 0; i < big_size; i++) {
    ret += digits[i];
  }
  return ret;
}

int factorial_digit_sum_opt(int fme)
{
  int digits[big_size] = {0};
  digits[0] =1;

  int sum = 0;

  int high_water = 2;

  for (size_t factor = 2; factor < fme; factor++) {
    int carry = 0;
    for (size_t j = 0; j <= high_water; j++) {
      int x = digits[j] * factor + carry;
      carry = 0;
      sum = x;
      if( x > 9){
        sum = x % 10;
        carry = x / 10;
        if( j == high_water ){
          high_water+=2;
        }
      }
      digits[j]=sum;
    }
  }
  int ret = 0;
  for (size_t i = 0; i < high_water; i++) {
    ret += digits[i];
  }
  return ret;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
  typedef std::chrono::high_resolution_clock my_clock;
  typedef std::chrono::milliseconds timer_res;

  uint64_t a,b;
  auto p1 = my_clock::now();
  for( int i = 0 ; i < 1000; i++ ){
    a = factorial_digit_sum(100);
  }
  auto p2 = my_clock::now();

  auto a1 = p2-p1;
  std::cout << "Brute force took: " << a1.count() << std::endl;

  p1 = my_clock::now();
  for( int i = 0 ; i < 1000; i++ ){
    b = factorial_digit_sum_opt(100);
  }
  p2 = my_clock::now();

  a1 = p2-p1;
  std::cout << "Opt force took: " << a1.count() << std::endl;

  std::cout << "Answer: " << factorial_digit_sum_opt(100) << std::endl;
}
#endif // #if ! defined UNITTEST_MODE
