#!/usr/bin/env ruby
# frozen_string_literal: true

# Longest Collatz sequence

# The following iterative sequence is defined for the set of positive integers:
#
# n -> n/2 (n is even)
# n -> 3n + 1 (n is odd)
#
# Using the rule above and starting with 13, we generate the following sequence:
#
# 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
# It can be seen that this sequence (starting at 13 and finishing at 1)
# contains 10 terms.
# Although it has not been proved yet (Collatz Problem),
# it is thought that all starting numbers finish at 1.
#
# Which starting number, under one million, produces the longest chain?
#
# NOTE: Once the chain starts the terms are allowed to go above one million.

# Answer: 837799

# Ikky GlobalVar, but ok for this
# rubocop:disable Style/GlobalVars
$cache = []

def collatz_sequence_length(start, options = {})
  options = { cache: true }.merge(options)

  chain_length = 1
  current_value = start

  while current_value != 1
    unless $cache[current_value].nil?
      chain_length += $cache[current_value]
      break
    end

    chain_length += 1

    if current_value.even?
      current_value /= 2
    else
      current_value = (current_value * 3) + 1
    end
  end

  $cache[start] = chain_length if options[:cache]
  chain_length
end

def longest_collatz_sequence_process(options = {})
  longest_starting_number = 1

  max_chain_length = -1

  2.upto(1_000_000) do |i|
    chain_length = collatz_sequence_length(i, options)
    if chain_length > max_chain_length
      longest_starting_number = i
      max_chain_length = chain_length
    end
  end
  longest_starting_number
end
# rubocop:enable Style/GlobalVars

def longest_collatz_sequence
  longest_collatz_sequence_process
  # require 'benchmark'
  # Benchmark.measure { longest_collatz_sequence_process(cache: false) }
  # Cache on: 3.460000   0.110000   3.570000 (  3.580396)
  # Cache off: 22.350000   0.200000  22.550000 ( 22.635814)
end

puts longest_collatz_sequence if __FILE__ == $PROGRAM_NAME
