# frozen_string_literal: true

require 'euler003'

describe 'Euler 003 solution' do
  it 'should calculate 003 correctly' do
    expect(largest_prime_number(600_851_475_143)).to eq 6857
  end
end
