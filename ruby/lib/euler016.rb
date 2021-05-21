#!/usr/bin/env ruby
# frozen_string_literal: true

# https:projecteuler.net/problem=16
# Power digit sum
#
# 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
#
# What is the sum of the digits of the number 2^1000?
#
# Answer: 1366

def power_digit_sum(power)
  digits = (2**power).to_s
  digits.split('').reduce(0) { |sum, digit| sum + digit.to_i }
end

puts power_digit_sum(1000) if __FILE__ == $PROGRAM_NAME
