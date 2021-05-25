# frozen_string_literal: true

require 'euler018'

describe 'Euler 018 solution' do
  describe 'maximum_path_sum_one' do
    it 'should calculate euler 018 example correctly' do
      expect(maximum_path_sum_one('./lib/euler_18_test_data.txt')).to eq 23
    end

    it 'should calculate euler 018 correctly' do
      expect(maximum_path_sum_one('./lib/euler_18_data.txt')).to eq 1074
    end
  end
end
