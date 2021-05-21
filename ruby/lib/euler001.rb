#!/usr/bin/env ruby
# frozen_string_literal: true

# If we list all the natural numbers below 10 that are multiples of 3 or 5,
# we get 3, 5, 6 and 9. The sum of these multiples is 23.
#
# Find the sum of all the multiples of 3 or 5 below 1000.
#
# Answer: 233168
def euler001_solution
  sum = 0
  (0..999).each do |num|
    sum += num if (num % 3).zero? || (num % 5).zero?
  end
  sum
end

puts euler001_solution if __FILE__ == $PROGRAM_NAME
