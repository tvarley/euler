# frozen_string_literal: true

require 'euler002'

describe 'Euler 002 solution' do
  it 'should calculate 002 correctly' do
    expect(sum_even_fib(4_000_000)).to eq 4_613_732
  end
end
