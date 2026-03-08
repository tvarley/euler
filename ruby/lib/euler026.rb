#!/usr/bin/env ruby
# frozen_string_literal: true

# A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
#
# 1/2 = 0.5
# 1/3 = 0.(3)
# 1/4 = 0.25
# 1/5 = 0.2
# 1/6 = 0.1(6)
# 1/7 = 0.(142857)
# 1/8 = 0.125
# 1/9 = 0.(1)
# 1/10 = 0.1
#
# Where 0.1(6) means 0.1666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
#
# Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
#
# Answer: 983
def cycle_length(d)
  seen = {}
  remainder = 1
  position = 0
  while remainder != 0 && !seen[remainder]
    seen[remainder] = position
    remainder *= 10
    remainder %= d
    position += 1
  end
  remainder == 0 ? 0 : position - seen[remainder]
end

def euler026_solution
  max_length = 0
  max_d = 0
  (2..999).each do |d|
    len = cycle_length(d)
    if len > max_length
      max_length = len
      max_d = d
    end
  end
  max_d
end

puts euler026_solution if __FILE__ == $PROGRAM_NAME