// https://projecteuler.net/problem=20
//
// n! means n × (n − 1) × ... × 3 × 2 × 1
//
// For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
// and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
//
// Find the sum of the digits in the number 100!
//
// Answer: 648

pub fn factorial_digit_sum(n: usize) -> u64 {
    let mut digits = vec![1u32];
    for i in 2..=n {
        let mut carry = 0;
        for d in digits.iter_mut() {
            let temp = *d * i as u32 + carry;
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
    fn euler_020() {
        assert_eq!(factorial_digit_sum(10), 27);
        assert_eq!(factorial_digit_sum(100), 648);
    }
}