// https://projecteuler.net/problem=57
//
// It is possible to show that the square root of two can be expressed as an infinite continued fraction.
// √2 =1+ 1/(2+ 1/(2 +1/(2+ ...)))
// By expanding this for the first four iterations, we get:
// 1 + 1/2 = 3/2 = 1.5
// 1 + 1/(2 + 1/2) = 7/5 = 1.4
// 1 + 1/(2 + 1/(2+1/2)) = 17/12 = 1.41666...
// 1 + 1/(2 + 1/(2+1/(2+1/2))) = 41/29 = 1.41379...
// The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985, is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.
// In the first one-thousand expansions, how many fractions contain a numerator with more digits than the denominator?
//
// Answer: 153

use num_bigint::BigUint;

pub fn square_root_convergents() -> u32 {
    let mut count = 0;
    let mut h_prev = BigUint::from(1u32);
    let mut k_prev = BigUint::from(1u32);
    let mut h = BigUint::from(3u32);
    let mut k = BigUint::from(2u32);
    for _ in 1..1000 {
        if h.to_string().len() > k.to_string().len() {
            count += 1;
        }
        let h_next = &h * 2u32 + &h_prev;
        let k_next = &k * 2u32 + &k_prev;
        h_prev = h;
        k_prev = k;
        h = h_next;
        k = k_next;
    }
    count
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_057() {
        assert_eq!(square_root_convergents(), 153);
    }
}