#!/usr/bin/env ruby
# frozen_string_literal: true

# A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
#
# 012   021   102   120   201   210
#
# What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
#
# Answer: 2783915460
def euler024_solution
  digits = (0..9).to_a
  target = 999_999  # 0-based index
  result = []
  (1..10).reverse_each do |i|
    fact = (1..(i - 1)).inject(1, :*) || 1
    index = target / fact
    result << digits.delete_at(index)
    target %= fact
  end
  result.join.to_i
end

puts euler024_solution if __FILE__ == $PROGRAM_NAME