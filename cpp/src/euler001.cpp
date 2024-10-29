// https://projecteuler.net/problem=1

// If we list all the natural numbers below 10 that are multiples of 3 or 5,
// we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.
// 
// Answer: 233168

#include <iostream>

int sum_natural_35(size_t upper)
{
  unsigned int sum(0);
  for( int i = upper ; --i; )
  {
    if( 0 == i % 3 )
    {
      sum += i;
    }
    else if ( 0 == i % 5 )
    {
      sum += i;
    }
  }
  return sum;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
  std::cout << sum_natural_35(1000) << std::endl;
}
#endif // UNITTEST_MODE
