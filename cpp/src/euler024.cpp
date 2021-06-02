// https://projecteuler.net/problem=24
// Lexicographic permutations

// A permutation is an ordered arrangement of objects. 
// For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. 
// If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. 
// The lexicographic permutations of 0, 1 and 2 are:

// 012   021   102   120   201   210

// What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

// Answer: 2783915460

#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>

#include "simple_timer.h"

std::string lexicographic_permutations_cheat(std::string input)
{
  int perm_count = 0;
  std::string result;
  std::sort(input.begin(), input.end());
  do {
    result = input;
  } while(std::next_permutation(input.begin(), input.end()) && ++perm_count < 1000000);

  return result;
}

// @see - https://www.geeksforgeeks.org/lexicographic-permutations-of-string/
// Following are the steps to print the permutations lexicographic-ally
// 1. Sort the given string in non-decreasing order and print it. 
// The first permutation is always the string sorted in non-decreasing order.
// 2. Start generating next higher permutation. 
// Do it until next higher permutation is not possible. 
// If we reach a permutation where all characters are sorted in non-increasing order, 
// then that permutation is the last permutation.
// 
// Steps to generate the next higher permutation:
// 1. Take the previously printed permutation and find the rightmost character in it, 
// which is smaller than its next character. Let us call this character as ‘first character’.
// 2. Now find the ceiling of the ‘first character’. 
// Ceiling is the smallest character on right of ‘first character’, 
// which is greater than ‘first character’. Let us call the ceil character as ‘second character’.
// 3. Swap the two characters found in above 2 steps.
// 4. Sort the substring (in non-decreasing order) after the original index of ‘first character’.
std::string lexicographic_permutations(const std::string& input)
{
  std::string result = input;
  std::sort(result.begin(), result.end());
  std::cout << "Input: " << input << std::endl;
  std::cout << "Result: " << result << std::endl;
  int perm_count = 0;
  while( ++perm_count < 1000000 ) {
  }
  return input;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
  std::string solution = "2783915460";
  // std::string digits("0123456789");
  std::string digits("0132456789");
  std::cout << "Solution: " << solution << std::endl;

  // ------8<---- Cheat Mode---8<-------
  {
    simple_timer x("Lexicographics permutations (cheat mode)");
    std::string cheat_answer = lexicographic_permutations_cheat(digits);
    std::cout << "Cheat mode" << std::endl;
    std::cout << "Answer: " << cheat_answer << std::endl;
    std::cout << "Correct?: " << (cheat_answer == solution ? "PASS" : "FAIL") << std::endl;
  }
  // ------8<---- Cheat Mode---8<-------

  // ------8<----Non Cheat Mode---8<-------
  {
    simple_timer x("Lexicographics permutations ( non cheat mode)");
    std::string answer = lexicographic_permutations(digits);
    std::cout << "Cheat mode" << std::endl;
    std::cout << "Answer: " << answer << std::endl;
    std::cout << "Correct?: " << (answer == solution ? "PASS" : "FAIL") << std::endl;
  }
  // ------8<----Non Cheat Mode---8<-------


  // std::cout << "Answer: " << lexicographic_permutations(digits) << std::endl;
}
#endif //#if ! defined UNITTEST_MODE
