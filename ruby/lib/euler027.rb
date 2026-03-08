#!/usr/bin/env ruby
# frozen_string_literal: true

# Euler discovered the remarkable quadratic formula:
#
# n² + n + 41
#
# It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 = 41 × 41 = 1681, which is 41², not a prime.
#
# The incredible formula n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.
#
# Considering quadratics of the form:
#
# n² + an + b, where |a| < 1000 and |b| ≤ 1000
#
# Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
#
# Answer: -59231
def is_prime(n)
  return false if n < 2
  (2..Math.sqrt(n).to_i).each do |i|
    return false if n % i == 0
  end
  true
end

def euler027_solution
  max_count = 0
  max_product = 0
  (-999..999).each do |a|
    (-1000..1000).each do |b|
      count = 0
      n = 0
      loop do
        value = n * n + a * n + b
        break unless is_prime(value)
        count += 1
        n += 1
      end
      if count > max_count
        max_count = count
        max_product = a * b
      end
    end
  end
  max_product
end

puts euler027_solution if __FILE__ == $PROGRAM_NAME