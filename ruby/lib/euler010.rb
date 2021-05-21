#!/usr/bin/env ruby
# frozen_string_literal: true

#
# https://projecteuler.net/problem=10
# Summation of primes
# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
#
# Find the sum of all the primes below two million.
#
# Answer: 142913828922
require 'prime'

def sum_primes
  sieve = Prime::EratosthenesGenerator.new
  prime_sum = 0
  prime = sieve.next
  while prime <= 2_000_000
    prime_sum += prime
    prime = sieve.next
  end
  prime_sum
end

puts sum_primes if __FILE__ == $PROGRAM_NAME
