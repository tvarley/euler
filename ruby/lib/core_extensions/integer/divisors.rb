# frozen_string_literal: true

# /lib/core_extensions/integer/divisors.rb
require 'prime'

# Divisor extension for Integer
module Divisors
  def divisor_count
    sum = 1
    # see https://en.wikipedia.org/wiki/Divisor_function
    prime_division.each do |x|
      sum *= (x[1] + 1)
    end
    sum
  end
end

# Integer mixin
class Integer
  include Divisors
end
