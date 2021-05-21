#!/usr/bin/env ruby
# frozen_string_literal: true

# The prime factors of 13195 are 5, 7, 13 and 29.
#
# What is the largest prime factor of the number 600851475143?
#
# Answer: 6857

def largest_prime_number(upper)
  answer = 2
  point = 3
  divisor = upper

  divisor /= 2 while divisor.even?

  while divisor != 1
    while (divisor % point).zero?
      answer = point
      divisor /= point
    end
    point += 2
  end
  answer
end

puts largest_prime_number(600_851_475_143) if __FILE__ == $PROGRAM_NAME
