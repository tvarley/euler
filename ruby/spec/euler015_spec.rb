# frozen_string_literal: true

require 'euler015'

describe 'Euler 015 solution' do
  it 'should calculate euler 015 example correctly' do
    expect(lattice_paths(2)).to eq 6
  end

  it 'should calculate euler 015 correctly' do
    expect(lattice_paths(20)).to eq 137_846_528_820
  end
end
