#!/usr/bin/env ruby
# frozen_string_literal: true

(1..30).each do |i|
  num = format('%03d', i)
  output = `ruby lib/euler#{num}.rb`.strip
  puts "Euler #{i}: #{output}"
end