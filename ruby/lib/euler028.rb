#!/usr/bin/env ruby
# frozen_string_literal: true

# Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
#
# 21 22 23 24 25
# 20  7  8  9 10
# 19  6  1  2 11
# 18  5  4  3 12
# 17 16 15 14 13
#
# It can be seen that the sum of the numbers on the diagonals is 101.
#
# What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
#
# Answer: 669171001
def euler028_solution
  sum = 1
  (1..500).each do |k|
    side = 2 * k + 1
    corner = side * side
    sum += corner + (corner - 2 * k) + (corner - 4 * k) + (corner - 6 * k)
  end
  sum
end

puts euler028_solution if __FILE__ == $PROGRAM_NAME