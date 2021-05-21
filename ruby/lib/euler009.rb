#!/usr/bin/env ruby
# frozen_string_literal: true

#
# https://projecteuler.net/problem=9
# Special Pythagorean triplet
#
# Problem 9
#
# A Pythagorean triplet is a set of three natural numbers, a < b < c,
# for which,
#
# a^2 + b^2 = c^2
#
# For example, (3^2 + 4^2) = (9 + 16) = 25 = 5^2.
#
# There exists exactly one Pythagorean triplet for which a + b + c = 1000.
# Find the product abc.
#
# Answer: 31875000
# a:200 b:375 c:425

def pyg(limit)
  # We can limit the range of a and b because of the following requirements:
  # a < b < c
  # a + b + c = 1000
  (1..limit / 3).each do |a|
    (a..limit / 2).each do |b|
      c = 1000 - b - a
      return (a * b * c) if (a * a) + (b * b) == (c * c)
    end
  end
end

puts pyg(1000) if __FILE__ == $PROGRAM_NAME
