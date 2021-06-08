// https://projecteuler.net/problem=25
// 1000-digit Fibonacci number
//
// The Fibonacci sequence is defined by the recurrence relation:
// 
// Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
// Hence the first 12 terms will be:
// 
// F1 = 1
// F2 = 1
// F3 = 2
// F4 = 3
// F5 = 5
// F6 = 8
// F7 = 13
// F8 = 21
// F9 = 34
// F10 = 55
// F11 = 89
// F12 = 144
// The 12th term, F12, is the first term to contain three digits.
// 
// What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

// Answer: 4782

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "simple_timer.h"

typedef std::vector<uint32_t> Zbigint; 

// class Zbigint : public std::vector<uint32_t>
// {
//   public:
//     Zbigint operator+( const Zbigint& b) 
//     {
//       Zbigint result(1,3);
//       return result;
//     }
// };
// 
double z1000_digit_fibinacci_number()
{
  double result{0};
  {
    simple_timer x("1000-digit Fibonacci Number");

    double fib1{1};
    double fib2{1};
    double index{0};

    do {
      result = fib1 + fib2;
      fib2 = fib1;
      fib1 = result;
      index++;
      std::cout << index << ")result: " <<  std::to_string(result) << " - " << std::to_string(result).size() << std::endl;
    } while( std::to_string(result).size() < 1000 );
  }
  return result;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
  std::cout << "Answer: " << z1000_digit_fibinacci_number() << std::endl;
}
#endif //#if ! defined UNITTEST_MODE
