# frozen_string_literal: true

require 'euler014'

describe 'Euler 014 solution' do
  it 'calculate collatz sequence length' do
    expect(collatz_sequence_length(13)).to eq 10
  end

  it 'should calculate 014 correctly' do
    expect(longest_collatz_sequence).to eq 837_799
  end
end
