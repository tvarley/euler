#!/usr/bin/ruby
#
# https://projecteuler.net/problem=12
# The sequence of triangle numbers is generated by adding the natural numbers.
# So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28.
# The first ten terms would be:
#
# 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
#
# Let us list the factors of the first seven triangle numbers:
#
# 1: 1
# 3: 1,3
# 6: 1,2,3,6
# 10: 1,2,5,10
# 15: 1,3,5,15
# 21: 1,3,7,21
# 28: 1,2,4,7,14,28
#
# We can see that 28 is the first triangle number to have over five divisors.
#
# What is the value of the first triangle number to have over five hundred divisors?
#
# Answer: 76576500

# @see http://en.wikipedia.org/wiki/Triangular_number
def triangle(num)
  return 3 if 1 == num
  ((num + 1) * num) / 2
end

# Math fact: a prime decomposition n = Prod_i p_i^e_i yields
# Prod_i (e_i + 1) different divisors
def num_divisors(num)
  divisors = 1
  count = 0
  while (0 == num % 2)
    count += 1
    num /= 2
  end
  divisors *= (count + 1)

  (3..num).step(2).each do |i|
    count = 0
    while (0 == (num % i))
      count += 1
      num /= i
    end
    divisors *= (count + 1)
  end
  divisors
end

def highest_divisible_triangular_number(stop)
  divisor_count = 0
  i = 1

  while (i <= stop)
    divisor_count = num_divisors(triangle(i))
    i += 1
    puts "#{i}/#{divisor_count}"
  end
  triangle(i - 1)
end

puts "Answer: #{highest_divisible_triangular_number(500)}"
