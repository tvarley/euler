require 'euler017'

describe 'Euler 017 solution' do
  describe 'Simple humanize' do
    it 'should not accept < 1' do
      expect { simple_humanize_length(0) }.to raise_error(ArgumentError)
    end

    it 'should not accept > 999999' do
      expect { simple_humanize_length(100000) }.to raise_error(ArgumentError)
    end
  end

  describe 'number_letter_counts' do
    it 'should calculate euler 017 example correctly' do
      expect(number_letter_counts(5)).to eq 19
    end

    it 'should calculate euler 017 correctly' do
      expect(number_letter_counts(1000)).to eq 21124
    end

    it 'should calculate euler 017 example correctly (cheat)' do
      expect(number_letter_counts_cheat(5)).to eq 19
    end

    it 'should calculate euler 017 correctly (cheat)' do
      expect(number_letter_counts_cheat(1000)).to eq 21124
    end
  end
end
