// https://projecteuler.net/problem=16
//
// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
//
// What is the sum of the digits of the number 2^1000?
//
// Answer: 1366

pub fn power_digit_sum(base: u32, exponent: usize) -> u64 {
    let mut digits = vec![1u32];
    for _ in 0..exponent {
        let mut carry = 0;
        for d in digits.iter_mut() {
            let temp = *d * base + carry;
            *d = temp % 10;
            carry = temp / 10;
        }
        while carry > 0 {
            digits.push(carry % 10);
            carry /= 10;
        }
    }
    digits.iter().map(|&d| d as u64).sum()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_016() {
        assert_eq!(power_digit_sum(2, 15), 26);
        assert_eq!(power_digit_sum(2, 1000), 1366);
    }
}