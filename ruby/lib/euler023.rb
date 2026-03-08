#!/usr/bin/env ruby
# frozen_string_literal: true

# A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
#
# A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
#
# As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
#
# Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
#
# Answer: 4179871
def sum_proper_divisors(n)
  return 0 if n == 1

  sum = 1
  (2..Math.sqrt(n).to_i).each do |i|
    if n % i == 0
      sum += i
      sum += n / i unless i == n / i
    end
  end
  sum
end

def euler023_solution
  limit = 28_123
  abundant = []
  (2..limit).each do |n|
    abundant << n if sum_proper_divisors(n) > n
  end

  can_be_sum = Array.new(limit + 1, false)
  abundant.each do |a|
    abundant.each do |b|
      sum = a + b
      break if sum > limit
      can_be_sum[sum] = true
    end
  end

  sum = 0
  (1..limit).each do |n|
    sum += n unless can_be_sum[n]
  end
  sum
end

puts euler023_solution if __FILE__ == $PROGRAM_NAME