#!/usr/bin/env ruby
# frozen_string_literal: true

# https://projecteuler.net/problem=6
# The sum of the squares of the first ten natural numbers is,
#
# 1^2 + 2^2 + ... + 10^2 = 385
# The square of the sum of the first ten natural numbers is,
#
# (1 + 2 + ... + 10)^2 = 55^2 = 3025
# Hence the difference between the sum of the squares of the first ten
# natural numbers and the square of the sum is 3025 - 385 = 2640.
#
# Find the difference between the sum of the squares of the first one
# hundred natural numbers and the square of the sum.

# Answer: 25164150

def sum_squares(limit)
  sum_square = 0
  square_sum = 0

  (0..limit).each do |i|
    sum_square += (i * i)
    square_sum += i
  end
  (square_sum * square_sum) - sum_square
end

puts sum_squares(100) if __FILE__ == $PROGRAM_NAME
