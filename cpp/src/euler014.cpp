// https://projecteuler.net/problem=14
// Longest Collatz sequence

// The following iterative sequence is defined for the set of positive integers:
//
// n → n/2 (n is even)
// n → 3n + 1 (n is odd)
//
// Using the rule above and starting with 13, we generate the following sequence:
//
// 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
// It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
// Although it has not been proved yet (Collatz Problem),
// it is thought that all starting numbers finish at 1.
//
// Which starting number, under one million, produces the longest chain?
//
// NOTE: Once the chain starts the terms are allowed to go above one million.

// Answer: 837799

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

uint64_t next_collatz_term(uint64_t prev)
{
  uint64_t ret;
  if( 0 == (prev%2)){
    ret = prev/2;
  }else{
    ret = (3 * prev)+1;
  }
  return ret;
}

static std::vector<int> previous_counts(1000000,-1);

int count_collatz_terms_brute(uint64_t start)
{
  int count = 1;
  while( 1 != start ){
    start = next_collatz_term(start);
    count++;
  }
  return count;
}

int count_collatz_terms_opt(uint64_t start)
{
  if( 1 == start ) return 1;

  int count = 0;

  if( start < 1000000 ){
    count = previous_counts.at(start);
    if( -1 == count ){
      count = count_collatz_terms_opt(next_collatz_term(start));
      count++;
      previous_counts.at(start) = count;
    }
  }else{
    count = count_collatz_terms_brute(start);
  }

  return count;
}

uint64_t longest_collatz_sequence_brute(uint64_t max_check)
{
  int max_count = 0;
  int max_counter = 0;
  for (uint64_t i = 1; i < max_check; i++) {
      int terms = count_collatz_terms_brute(i);
      if( max_count < terms ){
        max_count = terms;
        max_counter = i;
      }
  }
  return max_counter;
}

// Optimization, store previous counts and skip already calculated values.
uint64_t longest_collatz_sequence_opt(uint64_t max_check)
{
  int max_count = 0;
  int max_counter = 0;

  for (uint64_t i = 2; i < max_check; i++) {
    if( -1 == previous_counts.at(i) ){
      int count = count_collatz_terms_opt(i);
      if( max_count < count ){
        max_count = count;
        max_counter = i;
      }
    }
  }

  return max_counter;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
  std::cout << "Check(1): " << count_collatz_terms_opt(13) << std::endl;
  std::cout << "Check(2): " << count_collatz_terms_brute(13) << std::endl;

  int answer = longest_collatz_sequence_brute(1000000);
  std::cout << "Answer: " << answer
                          << '/' << count_collatz_terms_brute(answer)
                          << std::endl;

  answer = longest_collatz_sequence_opt(1000000);
  std::cout << "Answer: " << answer
                          << '/' << count_collatz_terms_opt(answer)
                          << std::endl;
}
#endif // #if ! defined UNITTEST_MODE
