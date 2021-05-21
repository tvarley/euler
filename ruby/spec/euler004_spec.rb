# frozen_string_literal: true

require 'euler004'

describe 'Euler 004 solution' do
  it 'should detect a palindromic number' do
    expect(palindrome_test(1001)).to be_truthy
    expect(palindrome_test(0)).to be_truthy
    expect(palindrome_test(1_001_100_110_011_001)).to be_truthy
    expect(palindrome_test(1002)).to be_falsey
    expect(palindrome_test(1_001_130_120_011_001)).to be_falsey
  end

  it 'should calculate 004 correctly' do
    expect(prob004_brute_force).to eq 906_609
  end
end
