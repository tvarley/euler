require 'euler016'

describe 'Euler 016 solution' do
  it 'should calculate euler 016 example correctly' do
    expect(power_digit_sum(15)).to eq 26
  end

  it 'should calculate euler 016 correctly' do
    expect(power_digit_sum(1000)).to eq 1366
  end
end
