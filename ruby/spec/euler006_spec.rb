# frozen_string_literal: true

require 'euler006'

describe 'Euler 006 solution' do
  it 'should calculate 006 correctly' do
    expect(sum_squares(100)).to eq 25_164_150
  end
end
