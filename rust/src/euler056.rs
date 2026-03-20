// https://projecteuler.net/problem=56
//
// A googol (10^100) is a massive number: one followed by one-hundred zeros; 100^100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.
// Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?
//
// Answer: 972

use num_bigint::BigUint;

pub fn powerful_digit_sum() -> u32 {
    let mut max_sum = 0;
    for a in 2..100 {
        for b in 2..100 {
            let num = BigUint::from(a as u32).pow(b);
            let sum: u32 = num.to_string().chars().map(|c| c.to_digit(10).unwrap()).sum();
            if sum > max_sum {
                max_sum = sum;
            }
        }
    }
    max_sum
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_056() {
        assert_eq!(powerful_digit_sum(), 972);
    }
}