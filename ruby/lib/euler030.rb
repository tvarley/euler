#!/usr/bin/env ruby
# frozen_string_literal: true

# Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
#
# 1634 = 1^4 + 6^4 + 3^4 + 4^4
# 8208 = 8^4 + 2^4 + 0^4 + 8^4
# 9474 = 9^4 + 4^4 + 7^4 + 4^4
#
# As 1 = 1^4 is not a sum it is not included.
#
# The sum of these numbers is 1634 + 8208 + 9474 = 19316.
#
# Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
#
# Answer: 443839
def euler030_solution
  sum = 0
  # Upper limit: 6 digits max, 6*9^5 = 354294, but check up to 999999
  (2..999_999).each do |n|
    digit_sum = n.to_s.chars.map { |d| d.to_i**5 }.sum
    sum += n if digit_sum == n
  end
  sum
end

puts euler030_solution if __FILE__ == $PROGRAM_NAME