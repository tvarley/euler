#!/usr/bin/env ruby
# frozen_string_literal: true

# Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
#
# For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
#
# What is the sum of all the name scores in the file?
#
# Answer: 871198282
def euler022_solution
  names = File.read('lib/p022_names.txt').gsub('"', '').split(',').sort
  total_score = 0
  names.each_with_index do |name, index|
    position = index + 1
    value = name.chars.sum { |c| c.ord - 'A'.ord + 1 }
    total_score += position * value
  end
  total_score
end

puts euler022_solution if __FILE__ == $PROGRAM_NAME