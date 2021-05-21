#!/usr/bin/env ruby
# frozen_string_literal: true

# https://projecteuler.net/problem=7
#
# By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
# we can see that the 6th prime is 13.
#
# What is the 10001st prime number?
#
# Answer: 104743

require 'prime'

def find_10001_prime
  sieve = Prime::EratosthenesGenerator.new
  answer = 0
  10_001.times { |_i| answer = sieve.next }
  answer
end

puts find_10001_prime if __FILE__ == $PROGRAM_NAME
