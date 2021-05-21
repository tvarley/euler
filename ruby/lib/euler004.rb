#!/usr/bin/env ruby
# frozen_string_literal: true

# https://projecteuler.net/problem=4

# A palindromic number reads the same both ways.
# The largest palindrome made from the product of two
# 2-digit numbers is 9009 = 91 x 99
# Find the largest palindrome made from the product of two 3-digit numbers.

# Answer: 906609

def palindrome_test(test_me)
  reversed = 0
  original = test_me

  while original.positive?
    reversed = reversed * 10 + (original % 10)
    original /= 10
  end

  (test_me == reversed)
end

def prob004_brute_force
  max_pali = 0
  (100..999).each do |i|
    (100..999).each do |j|
      t = i * j
      max_pali = t if (t > max_pali) && palindrome_test(t)
    end
  end
  max_pali
end

puts prob004_brute_force if __FILE__ == $PROGRAM_NAME
