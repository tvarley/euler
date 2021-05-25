# frozen_string_literal: true

require 'euler019'
require 'date'

describe 'Euler 019 solution' do
  describe 'counting sundays' do
    it 'should calculate euler 019 example correctly' do
      expect(counting_sundays(DateTime.parse('1/1/1901'), DateTime.parse('31/12/2000'))).to eq 171
    end
  end
end
