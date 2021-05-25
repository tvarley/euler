#!/usr/bin/env ruby
# frozen_string_literal: true

# https:#projecteuler.net/problem=19
# Counting Sundays

# You are given the following information, but you may prefer to do some research for yourself.
#
# - 1 Jan 1900 was a Monday.
# - Thirty days has September,
# - April, June and November.
# - All the rest have thirty-one,
# - Saving February alone,
# - Which has twenty-eight, rain or shine.
# - And on leap years, twenty-nine.
# - A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
#
# How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

# Answer: 171

require 'date'

def first_sunday?(month, year)
  # @see http://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Gauss.27_algorithm
  offsets = [0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4].freeze
  year -= 1 if month < 3
  ((year + year / 4 - year / 100 + year / 400 + offsets[month - 1] + 1) % 7).zero?
end

def counting_sundays(start_date, end_date)
  suns = 0
  current = start_date
  while current <= end_date
    current = current >> 1
    suns += 1 if first_sunday?(current.month, current.year)
  end
  suns
end

start_date = DateTime.parse('1/1/1901')
end_date = DateTime.parse('31/12/2000')
puts counting_sundays(start_date, end_date) if __FILE__ == $PROGRAM_NAME
