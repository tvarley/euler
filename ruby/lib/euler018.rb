#!/usr/bin/env ruby
# frozen_string_literal: true

# By starting at the top of the triangle below and moving to adjacent numbers on the row below,
# the maximum total from top to bottom is 23.
#
# 3
# 7 4
# 2 4 6
# 8 5 9 3
#
# That is, 3 + 7 + 4 + 9 = 23.
#
# Find the maximum total from top to bottom of the triangle below:
#
# NOTE: As there are only 16384 routes, it is possible to solve this by trying every route.
# However, Problem 67, is the same challenge with a triangle containing one-hundred rows;
# it cannot be solved by brute force, and requires a clever method! ;o)
#
# Answer: 1074

def maximum_path_sum_one(filename)
  rows = File.open(filename).map do |line|
    line.strip.split(',').map(&:to_i)
  end.reverse
  rows.each_with_index do |row, row_index|
    row.each_with_index do |val, val_index|
      next if val_index >= row.size - 1

      rows[row_index + 1][val_index] += [val, row[val_index + 1] || -1].max
    end
  end
  rows.last.first
rescue StandardError => e
  puts "***ERROR***: #{e}"
end

puts maximum_path_sum_one('./lib/euler_18_data.txt') if __FILE__ == $PROGRAM_NAME