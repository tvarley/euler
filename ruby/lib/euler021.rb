#!/usr/bin/env ruby
# frozen_string_literal: true

# Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
# If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
#
# For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
#
# Evaluate the sum of all the amicable numbers under 10000.
#
# Answer: 31626
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

def euler021_solution
  sum = 0
  seen = {}
  (2..9999).each do |a|
    next if seen[a]

    b = sum_proper_divisors(a)
    if b != a && sum_proper_divisors(b) == a && b < 10000
      sum += a + b
      seen[a] = true
      seen[b] = true
    end
  end
  sum
end

puts euler021_solution if __FILE__ == $PROGRAM_NAME